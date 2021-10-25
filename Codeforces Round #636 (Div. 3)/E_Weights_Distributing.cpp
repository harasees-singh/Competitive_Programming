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

void bfs(vi& depth, int a){

        queue<int> Q;

        vis[a] = 1;

        Q.push(a);
        
        while(Q.empty() == false){

                    int curr = Q.front();

                    for(auto p : g[curr]){

                            if(!vis[p])
                                    Q.push(p), depth[p] = depth[curr] + 1, vis[p] = 1;
                            
                    }
                    Q.pop();
            }
        return;
}


int32_t main(){
    FIO

    w(t){

                int n, m, a, b, c; cin >> n >> m >> a >> b >> c;

                g = vector<vi>(n + 1);

                int cost[m + 1];

                cost[0] = 0;

                l(i, 1, m + 1)
                        cin >> cost[i];

                sort(cost, cost + m + 1);

                l(i, 0, m){
                        cost[i + 1] = cost[i] + cost[i + 1];
                }
                
                l(i, 0, m){

                        int u, v; cin >> u >> v;

                        g[u].push_back(v);
                        g[v].push_back(u);
                }

                vis = vi(n + 1);

                vi aDepthMap(n + 1);

                bfs(aDepthMap, a);

                vis = vi(n + 1);
                
                vi bDepthMap(n + 1);

                bfs(bDepthMap, b);

                vi cDepthMap(n + 1);

                vis = vi(n + 1);

                bfs(cDepthMap, c);

                int mini = infinity;

                l(i, 1, n + 1){

                        if(bDepthMap[i] + cDepthMap[i] + aDepthMap[i] > m)
                                continue;

                        mini = min(mini, cost[bDepthMap[i]] + cost[aDepthMap[i] + cDepthMap[i] + bDepthMap[i]]);
                }

                cout << mini << endl;
    }

}
