// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        1e9
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

void slv(){
        int n; cin >> n; 

        vi in(n); cin >> in;

        if(n == 1){
                cout << 1 << endl; return;
        }

        vector<vector<bool>> rem(n + 1, vector<bool>(n + 1));

        for(int i = 0; i < n; i++){
                vi f(n + 1);
                int F = 0;                
                for(int j = i; j < n; j++){
                        f[in[j - 1]]++;
                        amax(F, f[in[j - 1]]);
                        // rem[i + 1][j + 1] = ; 
                }
                
        }
        // for(auto p : rem) prnIter(p);
        vector<int> dp(n + 1);
        dp[1] = 1;
        int mx = rem[2][n];

        for(int i = 2; i <= n; i++){
                if(rem[1][i - 1]) dp[i] = 1;

                else if(rem[1][i]) dp[i] = 0;

                else dp[i] = -infinity;

                for(int j = 1; j <= i - 1; j++){
                        if(in[j - 1] == in[i - 1]){
                                bool ok = (j + 1 <= i - 1 ? rem[j + 1][i - 1] : 1);

                                if(ok)
                                        amax(dp[i], dp[j] + 1);
                        }
                }
                if(i + 1 > n or rem[i + 1][n]) amax(mx, dp[i]);
        }
        cout << mx << endl;
}

int32_t main(){
        
        FIO

        w(T) 
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