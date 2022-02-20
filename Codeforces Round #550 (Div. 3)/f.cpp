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
vector<vi> g;
vi vis; // 1 means black, -1 means white, 0 unvis
bool ok = 1;
void dfs(int i, int color){

        if(vis[i]){
                if(vis[i] != color) ok = 0; 
                
                return;
        }
        vis[i] = color;

        color = (color == 1 ? -1 : 1);

        for(auto p : g[i]) dfs(p, color);
}
int32_t main(){
        FIO 

        int n, m; cin >> n >> m;

        g = vector<vi> (n + 1);

        vis = vi(n + 1);
        vector<pii> edges;
        for(int i = 0; i < m; i++){
                int u, v; cin >> u >> v;

                edges.push_back(make_pair(u, v));

                g[u].pb(v);

                g[v].pb(u);
        }

        dfs(1, 1);

        if(ok){
                cout << "YES" << endl;

                // for(int i = 1; i <= n; i++) 
                //         if(vis[i] == 1) cout << 1; else cout << -1; 
                for(auto p : edges){
                        if(vis[p.ff] == 1) cout << 1; else cout << 0;
                }
        }
        else cout << "NO";

        cout << endl;

        return 0;
}
