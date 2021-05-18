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
#define And &&
#define Or ||
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
int MOD = 1e9+7;


using namespace std;
class tree{
    public:

        map<int, vi> adj;
        int dfs(int , int);
        void push_tree(int, int);
};
void tree:: push_tree(int a, int b){
    adj[a].pb(b);
}
int ans=0;
int tree:: dfs(int node, int parent){
    if(adj[node].size()==1 And node!=1){
        ans++;return 1;
    }
    int to_be_returned=1;
    
    
    loop(i, 0, adj[node].size()){
        if(adj[node][i]!=parent){
            int val_returned=dfs(adj[node][i], node);
            ans+=to_be_returned*val_returned%MOD;
            ans%=MOD;
            
            to_be_returned+=2*val_returned%MOD;
        }
    }
    ans++;
    // loop(i, 0, values_stored_for_answer.size()){
    //     loop(j, i+1, values_stored_for_answer.size()){
    //         ans+=(values_stored_for_answer[i]*values_stored_for_answer[j])%MOD;
    //         ans=ans%MOD;
    //     }
    // }
    return to_be_returned%MOD;
}
int32_t main(){
    test_cases_loop{
        ans=0;
        int n; cin >> n;
        tree g;
        loop(i, 0, n-1){
            int u, v;
            cin >> u >> v;
            g.push_tree(u, v); g.push_tree(v, u);
        }
        g.dfs(1, -1);
        cout << ans << endl;
    }
}
