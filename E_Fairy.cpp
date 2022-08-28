// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
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
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(T)                            int T; cin >> T; while(T--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE
// answer is zero if u can't make the graph bipartite by removing one edge
// answer is m (all edges) if the graph is already bipartite (check by assigning colors to the dfs tree)
// answer is 1 if there is exactly 1 contradictory back-edge
// answer can contain a set of span-edges if all the back-edges passing over them are contradictory and there is no other contradictory back-edge not passing over this set
vector<vector<int>> g; 
map<pair<int, int>, int> id; 
set<pair<int, int>> span_edges;
vector<bool> vis;
vector<int> out, in;
vector<int> d; 
vector<bool> color;
vector<int> in_contradictory; // number of contradictory back-edges ending at u
vector<int> out_contradictory; // number of contradictory back-edges starting from u
vector<int> dp;
int netContradictoryedges = 0;
pair<int, int> SingleContradictoryEdge;

void dfsTree(int u, bool col){
        if(vis[u]) return;
        vis[u] = 1;     
        color[u] = col;


        for(int v : g[u]){
                if(!vis[v]){
                        d[v] = d[u] + 1;
                        span_edges.insert({u, v});

                        dfsTree(v, col ^ 1);
                }
        }
        int summation_dp = 0;
        for(int v : g[u]){
                if(span_edges.count({u, v}) == 0 and d[v] > d[u]){
                        // back-edge into the subtree of u

                        out[u]++, in[v]++;

                        if(color[u] == color[v]){
                                // contradictory back-edge

                                in_contradictory[v]++;
                                out_contradictory[u]++;

                                netContradictoryedges++;

                                SingleContradictoryEdge = {u, v};
                        }
                }
                if(span_edges.count({u, v}))
                        summation_dp += dp[v];
        }
}
void DP(int u){
        if(vis[u]) return;
        vis[u] = 1;

        int summation_dp = 0;
        for(int v : g[u])
                if(span_edges.count({u, v})) 
                        DP(v),
                        summation_dp += dp[v];
        
        dp[u] = summation_dp + in[u] - out[u];
}
vector<int> ans;
int dfs(int u, int parent){
        // return number of contradictory back_edges
        if(vis[u]) return 0;
        vis[u] = 1;

        int N = 0;

        for(int v : g[u])
                if(span_edges.count({u, v}))
                        N += dfs(v, u);
        
        N += in_contradictory[u];

        N -= out_contradictory[u];

        if(N == dp[u] and N == netContradictoryedges){
                if(id.count({u, parent}))
                        ans.push_back(id[{u, parent}]);
                else 
                        ans.push_back(id[{parent, u}]);
        }
        return N;
}
void slv(){
        int n, m; cin >> n >> m; 

        g = vector<vector<int>> (n + 1);
        d = vector<int> (n + 1);
        out = vector<int> (n + 1);
        in = vector<int> (n + 1);
        dp = vector<int> (n + 1);
        in_contradictory = vector<int> (n + 1);
        out_contradictory = vector<int> (n + 1);

        for(int i = 0; i < m; i++){
                int u, v; cin >> u >> v; 

                id[{u, v}] = i + 1;

                g[u].push_back(v);
                g[v].push_back(u);
        }
        vis = vector<bool> (n + 1);
        color = vector<bool> (n + 1);

        // dfsTree(1, 0);
        for(int i = 1; i <= n; i++) dfsTree(i, 0);


        vis = vector<bool> (n + 1);
        // marking colors and calculating dp;
        for(int i = 1; i <= n; i++) DP(i);

        if(netContradictoryedges == 0){
                // already bipartite
                cout << m << endl; 
                for(int i = 1; i <= m; i++) cout << i << ' '; return;
        }

        vis = vector<bool> (n + 1);
        for(int i = 1; i <= n; i++) dfs(i, 0);

        if(netContradictoryedges == 1){
                if(id.count(SingleContradictoryEdge))
                        ans.push_back(id[SingleContradictoryEdge]);
                else 
                        ans.push_back(id[{SingleContradictoryEdge.second, SingleContradictoryEdge.first}]);
        }
        sort(all(ans));
        cout << ans.size() << endl;
        for(auto p : ans) cout << p << ' ';
}

int32_t main(){
        
        FIO

        slv();
        
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/