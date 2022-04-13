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

// re rooting dp

// dp[i] stores value of given function if i is the root;

// sub[i] stores the value of function if i's parent is disconnected and only i's subtree is considered

// SUM[i] stores the sum of ai of children
vi dp, sub, in, SUM;
int TOT;
int ans = 0;
vector<vi> g;
int dfs(int i, int p){

    for(auto it : g[i]){
        if(it != p){
            sub[i] += dfs(it, i);

            SUM[i] += SUM[it]; 
        }

    }
    sub[i] += SUM[i];

    SUM[i] += in[i];
    
    return sub[i];
}
void reroot(int i, int p){
    // reroot i's children
    for(auto it : g[i]){
        if(it != p){
            dp[it] = dp[i] - SUM[it];

            int nodesum = TOT - SUM[it];

            dp[it] += nodesum;

            amax(ans, dp[it]);

            reroot(it, i);
        }
    }
}

int32_t main(){
        
        FIO
        int n; cin >> n;

        dp = vi(n + 1); in = vi(n + 1);
        SUM = vi(n + 1); sub = vi(n + 1);

        for(int i = 1; i <= n; i++) cin >> in[i];

        TOT = accumulate(all(in), 0ll);

        g = vector<vi> (n + 1);

        for(int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v;

            g[u].pb(v); g[v].pb(u);
        }
        dfs(1, 0);

        dp[1] = sub[1];


        amax(ans, dp[1]);

        reroot(1, 0);

        // for(auto p : dp) cout << p << ' '; cout << endl;
        cout << ans << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/