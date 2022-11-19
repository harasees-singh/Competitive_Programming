// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        INT32_MAX
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

void prn() {}
template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE
// code a basic knapsack
// given cycle lens are vlaues and weight associated with each cycle is 1

void slv(){
        int n; cin >> n;

        vector<int> in(n + 1); for(int i = 1; i <= n; i++) cin >> in[i];

        vector<bool> vis(n + 1);

        vector<pair<int, int>> perm = {{0, 0}};

        mii f;

        for(int i = 1; i <= n; i++){
            int p = i;
            if(vis[p]) continue;
            int len = 0;

            for(; vis[p] == false; vis[p] = true, p = in[p], len++) ;
            f[len]++;
        }
        for(auto p : f) perm.push_back(p);
        vector<int> dp(n + 1, infinity);
        dp[0] = 0;

        for(int i = 1; i < perm.size(); i++){

            vector<int> temp(dp);

            int k = perm[i].second;
            int len = perm[i].first;

            for(int it = 0; it < len; it++){
                deque<pair<int, int>> Q;
                for(int j = it; j <= n; j += len){
                    while(Q.empty() == false and Q.back().first >= dp[j] - j / len){
                        Q.pop_back();
                    }
                    Q.push_back(make_pair(dp[j] - j / len, j));

                    while(Q.front().second < j - k * len)
                        Q.pop_front();
                    
                    // lazy delete done
                    auto p = Q.front();

                    int range_min = p.first + p.second / len + (j - p.second) / len; // first (-it)
                    // then the ans = dp[j] + x; where x is the number of cycles of len perm[i]
                    // needed to get to j i.e. (j - j') / k;
                    
                    amin(temp[j], range_min);
                }
            }
            dp = temp;
        }
        for(auto &p : dp) p--;
        
        int mn = dp[n];
    
        for(int i = n - 1; i >= 1; i--){
            amin(dp[i], mn + 1);
            amin(mn, dp[i]);
        }
        for(int i = 1; i <= n; i++) cout << dp[i] << " \n"[i == n];
}

int32_t main(){
        
        FIO

        int T = 1;

        int t; cin >> t;

        for(; T <= t; T++){
            cout << "Case #" << T << ": ";
            
            slv();
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