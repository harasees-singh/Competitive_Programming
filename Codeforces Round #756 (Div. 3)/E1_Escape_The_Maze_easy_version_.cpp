// ਹਰਅਸੀਸ ਸਿੰਘ

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
#define fps(x, y)                       fixed<<setprecision(y)<<x
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<vi> g;
vi vis;
vi df;
vi dr;
MOD_DEFINE
// find distance of every leaf from closest frand (1 simultaneous bfs from all the frands)
// find distance of every leaf from root (1 bfs from root)

void bfs(queue<int> &q, vi &d){
        while(q.empty() == 0){
                int cur = q.front();
                q.pop();
                for(auto p : g[cur])
                        if(!vis[p])
                                d[p] = d[cur] + 1, vis[p] = 1, q.push(p);
        }
}

int32_t main(){
        
        FIO
        w(t){
                int n, k; 

                cin >> n >> k;

                vi frands(k);

                for(auto &p : frands) cin >> p;

                g = vector<vi>(n + 1);

                l(i, 0, n - 1){
                        int u, v; cin >> u >> v;

                        g[u].pb(v), g[v].pb(u);
                }
                dr = vi(n + 1);

                df = vi(n + 1);

                vis = vi(n + 1);

                queue<int> q;

                for(auto f : frands) 
                        q.push(f), vis[f] = 1;
                
                bfs(q, df);

                vis = vi(n + 1);

                q.push(1);

                vis[1] = 1;

                bfs(q, dr);

                bool ok = 0;

                for(int i = 2; i <= n; i++){
                        if(g[i].size() == 1){
                                // leaf

                                ok = ok or (dr[i] < df[i]);
                        }
                }
                cout << (ok ? "YES" : "NO") << endl;
 
        }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/