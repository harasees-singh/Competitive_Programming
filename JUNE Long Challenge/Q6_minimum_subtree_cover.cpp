#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

int dfs(vector<vi> &tree, vi &depth_vector, int node, int parent, vi &child_parent){
    if(node!= 1 And tree[node].size() == 1){
        // leaf found
        child_parent[node]=parent;
        depth_vector[node] = 1;
        return 1;
    }
    child_parent[node]=parent;
    int max_depth=0;
    int i=0;
    while(i < sz(tree[node])){
    // loop(i, 0, tree[node].size()){
        if(tree[node][i] != parent){
            max_depth = max(max_depth, dfs(tree, depth_vector, tree[node][i], node, child_parent)); 
            // max_depth = dfs(tree, depth_vector, tree[node][i]);
        }
        i++;
    }
    max_depth++;
    depth_vector[node]=max_depth;
    return max_depth;
}
int32_t main(){
    FIO
    test_cases_loop{
        // cout << "reflex " << endl;
        int n, k; cin >> n >> k;
        vi depth_vector(n+1);
        vector<vi> tree(n+1, vector<int>());
        loop(i, 0, n-1){
            int parent, child; cin >> parent >> child;
            tree[parent].pb(child); tree[child].pb(parent);
            
        }
        // for(int j=1; j<= n; j++){loop(i, 0, tree[j].size()){cout << "greet " << j <<"'s children " << tree[j][i] << endl;}}
        // break;
        vi answer;
        int total = 0;
        vi child_parent(n+1);
        // tree is complete
        // cout << "fine " <<endl;
        // if(sz(tree[1]) == 1){total += dfs(tree, depth_vector, tree[1][0]); total++;}
        total += dfs(tree, depth_vector, 1, 0, child_parent);
        answer.pb(total);
        vi leaves;
        
        loop(i, 2, n+1){
            if(tree[i].size() == 1){
                leaves.pb(i);
            }
        }
        vi visited(n+1, 0);
        // visited[1]=1;
        for(auto leaf: leaves){
            
            while(leaf != 1)
            {
                int parent = child_parent[leaf];
                if(depth_vector[parent] == 1+depth_vector[leaf] And !visited[parent]){leaf = parent; visited[parent]=1;}
                else {answer.pb(depth_vector[leaf]); total += depth_vector[leaf]; break;}
            }
        }
        sort(all(answer));
        if(k==1){cout << 1 << endl; continue;}
        if(n==1){cout << 1 << endl; continue;}
        if(k==n And sz(tree[1])>1){cout << sz(answer) << endl; continue;}
        if(k==n And sz(tree[1])==1){cout << sz(answer)+1 << endl; continue;}
        // loop(i, 0, answer.size()){cout<< "debug " << answer[i] << space;} cout << endl;
        int index=0;
        // bool parity=false;
        // cout << "sz of answer " << sz(answer) << endl;
        while(total - answer[index] >= k){
            // parity=true;
            total -= answer[index]; index++;
        }
        sz(tree[1])==1 ? index--: index=index;
        int possible_answer = sz(answer) - index;
        int headroom=0; int curr=1;
        while((sz(tree[curr]) == 1 And curr==1) Or (sz(tree[curr])==2 And curr!=1)){headroom++; tree[curr][0] != child_parent[curr] ? curr = tree[curr][0]: curr = tree[curr][1];}
        // parity ? index-- : index=index;
        if(headroom == n-1){k >= 2 ? cout << 2 << endl : cout << 1 << endl; continue;}
        // cout << "headroom " <<headroom << endl;
        int another_potential_answer  = infinity;
        int index2= 0;
        // cout << "headroom " << headroom << endl;
        if(headroom){
            total = n;
            total -= headroom;
            
            answer[sz(answer)-1]-=headroom;
            // loop(i, 0, answer.size()){cout<< "debug " << answer[i] << space;} cout << endl;
            while(total - answer[index2] >= k And index2 < sz(answer)){
                total -= answer[index2]; index2++;
            }
            // cout << "index " << index2 << endl;
            another_potential_answer = sz(answer) - index2;
            //--------------------------------------------------
            // if(total < k)cout << "total less than k " << endl;
            //--------------------------------------------------
            if(total < k){another_potential_answer++;}
            // total <= k ? another_potential_answer = another_potential_answer : another_potential_answer++;
        }
        // cout << "possible answer " << possible_answer << " another ptential answer " << another_potential_answer << endl;
        // cout << min(possible_answer, another_potential_answer) << endl;
        cout << possible_answer << endl;
    }
    return 0;
}

