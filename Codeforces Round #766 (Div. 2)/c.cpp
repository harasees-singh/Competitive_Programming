// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE
// if deg of a node is > 2 then -1 since addition of 2 odd primes will be even
// for the rest of the tree assign 2, 3 aternately
vector<vi> g;
map<pii, int> edge;
int col = 0;
void dfs(int i, int p){
    for(auto q : g[i]){
        if(q != p){
            edge[{i, q}] = col == 0 ? 2 : 3; col ^= 1; dfs(q, i);
        }
    }
}
int32_t main(){
        FIO 

        w(t){
            int n; cin >> n;
            edge.clear();
            g = vector<vi> (n + 1);

            vector<pii> store;

            for(int i = 0; i < n - 1; i++){
                int u, v; cin >> u >> v; g[v].pb(u); g[u].pb(v);
                store.push_back(make_pair(u, v));
            }
            bool ok = 1;
            for(auto p : g) if(sz(p) > 2) {cout << -1 << endl; ok = 0; break;}

            if(not ok) continue;

            int degone;

            for(int i = 1; i <= n; i++) if(sz(g[i]) == 1) degone = i;

            dfs(degone, 0);

            for(auto p : store){
                if(edge.count(p)) cout << edge[p] << ' ';

                else cout << edge[{p.ss, p.ff}] << ' ';
            }
            cout << endl;
        }

        return 0;
}
