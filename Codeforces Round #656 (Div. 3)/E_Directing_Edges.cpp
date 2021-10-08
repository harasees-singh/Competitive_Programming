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

const int N = 2e5 + 1;

vector<int> vis;
vector<vi> g;
vector<int> order;

void dfs(int i){

        vis[i] = 1;

        for(auto p : g[i])
                if(!vis[p])
                        dfs(p);

        order.pb(i);
}

int32_t main(){
    FIO

    w(t){
            int n, m; cin >> n >> m;

            vis = vector<int>(n + 1);

            g = vector<vi>(n + 1);

            order = vector<int>();

            vpii edges;

            l(i, 0, m){

                    int t; cin >> t;

                    int u, v; cin >> u >> v;

                    if(t)
                            g[u].pb(v);
                    
                    edges.pb(make_pair(u, v));
            }

            // topological sort the entire thing and obtain the order for each node;

            l(i, 1, n + 1)
                    if(!vis[i])
                            dfs(i);
            
            reverse(all(order));

            vi pos(n + 1);

            int it = 0;

            for(auto p : order)
                    pos[p] = it, it++;

            bool ok = true;

            l(i, 1, n + 1)
                    for(auto p : g[i])
                            if(pos[i] > pos[p])
                                    ok = false;
            
            if(ok){
                    cout << "YES" << endl;

                    // for every edge, direct it in the order as assigned by the topological sort to ensure it stays acyclic.

                    for(auto p : edges){

                            int x, y; tie(x, y) = p;

                            if(pos[x] < pos[y])
                                    cout << x << space << y << endl;
                            else 
                                    cout << y << space << x << endl;
                    }
            }
            else    
                    cout << "NO" << endl;
    }

}
