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

vector<vector<int>> g;
vector<int> d; 
vector<int> p;
vector<int> in;
void setParent(int i, int j){
    for(auto u : g[i]){
        if(u != j){
            p[u] = i; 

            setParent(u, i);
        }
    }
}
int mx = INT64_MIN;
void dfs(int i, int j, int depth, int have){
    if(depth == d[i]){
        have += in[i] / 2; 
    }

    else if(d[i] > depth or d[i] == -1) have += in[i];

    mx = max(mx, have);

    for(auto u : g[i]){
        if(u != j){
            dfs(u, i, depth + 1, have);
        }
    }
}
void slv(){
        int n; cin >> n;

        int R; cin >> R;

        g = vector<vector<int>> (n + 1);
        in = vector<int> (n + 1);
        p = vector<int> (n + 1);

        for(int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v; 

            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) cin >> in[i];

        d = vector<int> (n + 1, -1);

        d[R] = 0;

        setParent(1, 0);

        int u = p[R];
        int put = 0;
        for(; u; u = p[u]){
            d[u] = ++put; 
        }
        dfs(1, 0, 0, 0);

        cout << mx << endl;
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