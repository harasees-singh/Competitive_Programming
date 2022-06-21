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
#define int                             long long
#define endl                            '\n'
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
vector<vector<vi>> change;
vi knapsack(int id){
    // job to be done

    vector<vi> dp(sz(change[id]) + 1, vi(199, -1));

    vector<vector<bool>> chosen(sz(change[id]) + 1, vector<bool>(199));

    for(int i=0; i <= sz(change[id]); i++) dp[i][0] = 0;

    for(int i=1; i <= sz(change[id]); i++){
        int t = change[id][i-1][0], p = change[id][i-1][1];

        for(int j=0; j <= 198; j++){
            dp[i][j]=dp[i-1][j];
            if(j-p>=0 and dp[i-1][j-p] != -1 and (dp[i-1][j-p] + t < dp[i][j] or dp[i][j]==-1)){
                dp[i][j] = t + dp[i-1][j-p]; chosen[i][j]=1;
            }
        }
    }
    int mn=infinity, P=-1;
    int n = sz(change[id]);

    for(int i=100; i<=198; i++){
        if(dp[n][i] != -1 and dp[n][i] < mn)
            mn = dp[n][i], P = i;
    }
    vi ret; 

    // cout << P << ' ' << mn << endl;

    if(P==-1){
        // cout << "NO" << endl;
        return {};
    }
    // assert(chosen[n][P]);
    int it=n;
    while(it){
        if(chosen[it][P]){
            ret.pb(it-1);
            P -= change[id][it-1][1];
        }
        it--;
    }
    return ret;
}
void solve(){
    int n, m; cin >> n >> m; 
    vi in(n); for(auto &p : in) cin >> p;

    change = vector<vector<vi>> (n + 1); // e, t, p // id, time req, percent change

    for(int i=0; i < m; i++){
        int e, t, p; cin >> e >> t >> p;

        change[e].push_back({t, p, i});
    }
    // auto ret = knapsack(1, in[0]);
    // for(auto p : ret) cout << p << ' '; cout << endl;
    
    vi ans;
    int time=0;

    for(int i=1; i <= n; i++){
        vi ret = knapsack(i);

        if(!sz(ret)){
            cout << -1 << endl; return;
        }
        for(auto p : ret) time += change[i][p][0];

        if(time > in[i-1]){
            // cout << time << ' ' << i << endl;
            cout << -1 << endl; return;
        }
        for(auto p : ret) ans.push_back(change[i][p][2] + 1);
    }
    cout << sz(ans) << endl;
    for(auto p : ans) 
        cout << p << ' '; cout << endl;
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