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
#include <numeric>
#define infinity 999999999999999999
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
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
int __gcd(int a, int b){
    if(b==0) return a;
    return __gcd(b, a%b);
}
MOD_DEFINE
vi visited;
vector<vi> adjacency;
void solve(int node){

    cout << "?" << space << node << endl; cout.flush();
    
    vi input = {0} ;
    loop(i, 1, sz(visited)){
        int temp; cin >> temp; input.pb(temp);
    }
    loop(i, 1, sz(visited)){
        int temp = input[i];
        if(temp == 1)
        {
            adjacency[node].pb(i);
            adjacency[i].pb(node);
        }
        if(temp == 2)
        {
            if(!(visited[i]))
            {
                visited[i] = 1;
                solve(i);
            }
        }
    }
}
void dfs(int node, int parent){
    if(sz(adjacency[node]) == 1 And adjacency[node][0] == parent) return;

    for(auto child:adjacency[node]){
        if(child != parent){
            cout << node << space << child << endl;
            dfs(child, node);
        }
    }
}
int32_t main(){
    FIO
    int n; cin >> n;

    adjacency.resize(n+1);
    visited.resize(n+1);
    
    cout << "?" << space << 1 << endl; cout.flush();
    
    vi corner_case = {0};
    vi input[2];

    loop(i, 1, n+1){
        int temp; cin >> temp; corner_case.pb(temp); 
        input[temp & 1].push_back(i);
    }
    if(sz(input[0]) > sz(input[1])) swap(input[0], input[1]);

    if(input[0][0] == 1) // we have hit the case when starting from 1 is the best case scenario. so we will use the corner case array 
    {
        visited[1] = 1;
        loop(i, 1, n+1){
            if(corner_case[i] == 1){
                adjacency[1].push_back(i); adjacency[i].push_back(1);
            }
            if(corner_case[i] == 2)
            {
                if(!(visited[i]))
                {
                    visited[i] = 1;
                    solve(i);
                }
            }
        }
    }
    else
    {
        visited[input[0][0]] = 1;
        solve(input[0][0]);
    }
    cout << "!" << endl;
    dfs(1, 0);
    return 0;
}