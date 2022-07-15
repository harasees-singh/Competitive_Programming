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
vector<vector<vector<int>>> m;

// dp[i][mark] maximum good nodes in the subtree with ith node marked acc to mark and minimum cost for the same
vector<vector<pii>> dp;
void dfs(int i, int P){
    if(sz(g[i]) == 1 and i != 1){
        dp[i][0] = {0, 1};

        dp[i][1] = {1, 1};

        return;
    }
    for(auto p : g[i]) 
        if(p != P) 
            dfs(p, i);
    
    pii zero;
    for(int j = 0; j < sz(g[i]); j++){
        auto p = g[i][j];

        if(p != P){
            if(dp[p][0].ff > dp[p][1].ff){
                zero.ff += dp[p][0].ff;
                zero.ss += dp[p][0].ss;

                m[i][0][j] = 0;
            }
            else if(dp[p][1].ff > dp[p][0].ff){
                zero.ff += dp[p][1].ff; 
                zero.ss += dp[p][1].ss; 

                m[i][0][j] = 1;
            }
            else{
                if(dp[p][0].ss < dp[p][1].ss){
                    zero.ff += dp[p][0].ff;
                    zero.ss += dp[p][0].ss;

                    m[i][0][j] = 0;
                }
                else {
                    zero.ff += dp[p][1].ff; 
                    zero.ss += dp[p][1].ss; 

                    m[i][0][j] = 1;
                }
            }
        }
    }
    pii one; 

    for(int j = 0; j < sz(g[i]); j++){
        auto p = g[i][j];
        if(p != P){
            one.ff += dp[p][0].ff; 

            m[i][1][j] = 0;

            one.ss += dp[p][0].ss;
        }
    }
    dp[i][0] = {zero.ff, zero.ss + 1};

    dp[i][1] = {one.ff + 1, one.ss + sz(g[i])};
}
vector<int> ans; 

void path(int mark, int i, int P){
    if(mark){
        ans[i] = sz(g[i]);
    }
    else{
        ans[i] = 1;
    }
    for(int j = 0; j < sz(g[i]); j++){
        auto p = g[i][j];
        if(p != P){
            path(m[i][mark][j], p, i);
        }
    }
}
void slv(){
    int n; cin >> n;  

    g = vector<vector<int>> (n + 1);
    dp = vector<vector<pii>> (n + 1, vector<pii> (2));
    ans = vector<int> (n + 1);

    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; 

        g[u].push_back(v); 

        g[v].push_back(u);
    }   
    m = vector<vector<vector<int>>> (n + 1, vector<vector<int>> (2));

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++) m[i][j] = vector<int> (sz(g[i]));
    }

    if(n == 2){
        cout << 2 << ' ' << 2 << endl;

        cout << 1 << ' ' << 1 << endl; return;
    }
    dfs(1, 0);

    if(dp[1][0].ff > dp[1][1].ff){
        path(0, 1, 0);

        cout << dp[1][0] << endl;
    }
    else if(dp[1][1].ff > dp[1][0].ff){

        path(1, 1, 0); 

        cout << dp[1][1] << endl;
    }
    else{
        if(dp[1][0].ss < dp[1][1].ss){
            cout << dp[1][0] << endl;

            path(0, 1, 0);
        }
        else{
            cout << dp[1][1] << endl;

            path(1, 1, 0);
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
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