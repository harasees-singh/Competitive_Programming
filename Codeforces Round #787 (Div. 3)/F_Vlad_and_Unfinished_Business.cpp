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
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

vector<vi> g;
set<int> path; // nodes in the path from x to y
bool dfs(int x, int y, int parent){
        if(x==y){
                path.insert(y);

                return 1;
        }
        for(auto p : g[x]){
                if(p != parent){
                        if(dfs(p, y, x)){
                                path.insert(x);

                                return 1;
                        }
                }
        }
        return 0;
}

int32_t main(){
        
        FIO
        // only one path from x to y

        // rest of the works must be done from nodes belonging to this path (assumption) for optimality

        // a multisource bfs from the nodes on the path from x to y should give the optimal 

        // paths for each of the tasks.

        w(T){
                path.clear();

                int n, k; cin >> n >> k;

                vi vis(n + 1);

                g = vector<vi> (n + 1) ;

                int x, y; cin >> x >> y;

                set<int> tasks; for(int i=0; i<k; i++){int t; cin >> t; tasks.insert(t);}

                for(int i = 0; i < n - 1; i++){
                        int u, v; cin >> u >> v; 

                        g[u].pb(v); g[v].pb(u);
                }
                dfs(x, y, 0);

                // for(auto p: path) cout << p << ' '; cout << endl; // fine

                vi dp(n + 1);
                for(auto p : path) dp[p]=p;
                queue<int> Q; 
                for(auto p: path) Q.push(p);

                while(Q.size()){
                        int top = Q.front();
                        Q.pop();

                        for(auto p : g[top]){
                                if(dp[p]==0){
                                        dp[p]=top;
                                        Q.push(p);
                                }
                        }
                }
                set<pii> edges; 

                for(auto p: tasks){
                        while(dp[p] != p){
                                int parent=dp[p];
                                if(edges.count({p, parent})) break;
                                edges.insert({p, parent}); 
                                edges.insert({parent, p});
                                p=parent; 
                        }
                }
                cout << sz(path)-1 + sz(edges) << endl;
        }

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/