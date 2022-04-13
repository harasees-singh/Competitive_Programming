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

int32_t main(){
        
        FIO
        int t; cin >> t;
        l(T, 1, t + 1){
            cout << "Case #" << T << ": ";

            int x, y; cin >> x >> y;

            string s; cin >> s;
            for(auto &p : s){
                if(p == '?') continue;
                if(p == 'C') p = 'a';

                else p = 'b';
            }
            int n = sz(s);

            vector<vi> dp(n, {0, 0});

            // dp[0][(s[0] - 'a' + 1) % 2] = infinity;
            if(s[0] != '?') dp[0][(s[0] - 'a' + 1) % 2] = infinity;

            for(int i = 1; i < n; i++){
                int costa = min(dp[i - 1][0], dp[i - 1][1] + y);
                int costb = min(dp[i - 1][1], dp[i - 1][0] + x);

                // cout << costa << ' ' << costb << endl;

                if(s[i] != '?'){
                    dp[i][s[i] - 'a'] = (s[i] == 'a' ? costa : costb);

                    dp[i][(s[i] - 'a' + 1) % 2] = infinity;    
                }
                else dp[i][0] = costa, dp[i][1] = costb;
            }
            // for(auto p : dp) cout << p[0] << ' ' << p[1] << endl;
            cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
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