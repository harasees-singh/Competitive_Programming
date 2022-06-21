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
void solve(){
    int n, m; cin >> n >> m; 

    g = vector<vi> (n + 1);
    int s, t; cin >> s >> t; 
    for(int i=0; i < m; i++){
        int u, v; cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);
    }

    vi dp(n + 1);
    vector<bool> vis(n + 1);

    vi d(n + 1);

    queue<int> Q;
    vis[s] = 1; Q.push(s);
    dp[s] = 1;
    while(!Q.empty()){
        int top=Q.front();

        Q.pop();

        for(auto p : g[top]){
            if(d[p] == d[top]+1) dp[p] += dp[top]; dp[p] %= MOD;

            if(vis[p]) continue;
            d[p] = d[top] + 1;
            vis[p]=1;

            dp[p] += dp[top]; dp[p] %= MOD;

            Q.push(p);
        }
    }
    vi DP(n + 1);

    set<int> have; 
    vis = vector<bool>(n + 1);
    have.insert(s); 

    vis[s]=1;
    while(not have.empty()){

        set<int> temp;

        for(auto p : have){
            for(auto q : g[p]){
                if(not vis[q]) temp.insert(q);
            }
        }

        for(auto p : have){
            for(auto q : g[p]){
                
                if(temp.count(q) and vis[q]) DP[q] += DP[p], DP[q] %= MOD;

                if(not vis[q])
                    vis[q] = 1, DP[q] += DP[p], DP[q] %= MOD;
                
            }
        }
        

        set<int> cpy(temp);

        for(auto p : cpy){
            for(auto q : g[p]){
                if(temp.count(q)){
                    // sideways edge
                    DP[q] += dp[p]; DP[q] %= MOD;
                }
            }
        }
        
        have = temp;
    }
    // for(auto p :dp) cout << p << ' '; cout << endl;
    // for(auto p :DP) cout << p << ' '; cout << endl;

    cout << (dp[t] + DP[t]) % MOD << endl;
}
int32_t main(){
        
        FIO

        w(T){
            solve();
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