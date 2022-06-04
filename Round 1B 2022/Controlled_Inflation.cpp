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

        int T; cin >> T; 

        for(int t = 1; t <= T; t++){
            cout << "Case #" << t << ": ";

            int n, p; cin >> n >> p;

            vector<vi> in(n, vi(p));

            for(auto &P : in) for(auto &q : P) cin >> q; 

            for(auto &P : in) sort(all(P));

            vector<pii> IN(n);
            int id = 0;
            for(auto &P : in) IN[id++] = {P[0], P[p - 1]}; 

            vector<pii> dp(n); // {down, up};

            dp[0] = {2 * IN[0].ss - IN[0].ff, IN[0].ss};

            for(int i = 1; i < n; i++){
                int diff = IN[i].ss - IN[i].ff;
                dp[i].ff = min(dp[i - 1].ff + abs(IN[i - 1].ff - IN[i].ss) + diff, dp[i - 1].ss + abs(IN[i - 1].ss - IN[i].ss) + diff);

                dp[i].ss = min(dp[i - 1].ff + abs(IN[i - 1].ff - IN[i].ff) + diff, dp[i - 1].ss + abs(IN[i - 1].ss - IN[i].ff) + diff);
            }
            cout << min(dp[n - 1].ff, dp[n - 1].ss) << endl;
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