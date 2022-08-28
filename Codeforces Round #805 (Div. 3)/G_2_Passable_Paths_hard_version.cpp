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
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(T)                            int T; cin >> T; while(T--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vector<int>, greater<int>>
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
vector<vi> g;
vector<int> d;
vector<int> tin;
vector<int> tout;
vector<int> parent;
vector<vector<int>> up;
int t; 
int l;
void dfs(int root, int p){
        tin[root] = ++t;

        d[root] = d[p] + 1;

        up[root][0] = p;

        for(int i = 1; i <= l; i++)
                up[root][i] = up[up[root][i - 1]][i - 1]; 
        
        for(auto u : g[root])
                if(u != p)
                        dfs(u, root);
        
        tout[root] = ++t;
        
}
bool isAncestor(int i, int j){
        return tin[i] <= tin[j] and tout[i] >= tout[j];
}
void preprocess(){

        l = 0;

        int c(2e5 + 10);
        while(c) l++, c/=2;

        up = vector<vector<int>>(2e5 + 10, vector<int>(l + 1));

        dfs(1, 0);
}
int lca(int u, int v){
        if(isAncestor(u, v))
                return u;
                
        if(isAncestor(v, u))
                return v;

        for(int i = l; i >= 0; i--)
                if(!isAncestor(up[u][i], v))
                        u = up[u][i];

        return up[u][0];
}
void slv(){
        int n; cin >> n; 
        g = vector<vector<int>> (n + 1);

        for(int i = 0; i < n - 1; i++){
                int u, v; cin >> u >> v; 

                g[u].push_back(v); 
                g[v].push_back(u);
        }
        d = vector<int> (n + 1);
        tin = vector<int> (n + 1);
        tout = vector<int> (n + 1);
        tout[0] = INT32_MAX;
        parent = vector<int> (n + 1);

        preprocess();

        int q; cin >> q; 

        for(int _ = 0; _ < q; _++){
                int t; cin >> t; 

                vector<pair<int, int>> T;

                for(int i = 0; i < t; i++){
                        int u; cin >> u; 

                        T.push_back(make_pair(d[u], u));
                }
                sort(all(T));

                vector<int> vis(t);

                vector<int> leaves(2, -1);

                for(int i = 0; i < 2; i++){
                        int j; 
                        for(j = t - 1; j >= 0; j--) if(not vis[j]) {leaves[i] = T[j].ss; break;}
                        
                        int leaf = T[j].ss;

                        for(; j >= 0; j--){
                                if(not vis[j] and isAncestor(T[j].ss, leaf)){
                                        vis[j] = 1; leaf = T[j].ss;
                                }
                        }
                }
                if(count(all(vis), 0ll)){
                        cout << "NO" << endl; continue;
                }
                if(leaves[1] != -1){
                        if(d[lca(leaves[0], leaves[1])] > T[0].ff){
                                cout << "NO" << endl; continue;
                        }
                }
                
                cout << "YES" << endl;
        }
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