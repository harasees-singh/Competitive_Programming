#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
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
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

vi vis;
vector<vi> g;
vi edge;

int32_t main(){
    FIO

    w(t){

            int n, k; cin >> n >> k;

            vis = vi(n + 1);
            g = vector<vi>(n + 1);
            edge = vi(n + 1);

            l(i, 0, n - 1){

                    int u, v; cin >> u >> v;

                    edge[u]++, edge[v]++;

                    g[u].pb(v), g[v].pb(u);

            }

            vi leaves;

            l(i, 1, n + 1){
                    if(edge[i] < 2)
                            leaves.push_back(i), vis[i] = 1;
            }

            l(i, 0, k){
                    vi t;

                    for(auto p : leaves){

                            for(auto q : g[p]){

                                    edge[q]--;

                                    if(!vis[q] and edge[q] < 2)
                                            t.push_back(q), vis[q] = 1;
                            }
                    }

                    leaves = t;

                    if(!sz(leaves))
                            break;
            }   
            
            cout << sz(leaves) + count(all(vis), 0ll) - 1 << endl;
    }   

}