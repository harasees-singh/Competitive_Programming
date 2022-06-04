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

        // expr reduces to (n - 2) * (sum a**2 + sum b**2) + (sum a)**2 + (sum b)**2;

        // minimize sum a;
        
        w(T){

        int n; cin >> n; 
        int overhead =0;
        vi a(n); for(auto &p : a) cin >> p, overhead += p*p;
        vi b(n); for(auto &p : b) cin >> p, overhead += p*p;
        overhead *= (n - 2);
        int A = accumulate(all(a), 0ll);
        int B = accumulate(all(b), 0ll);
        vector<bool> dp(1e4 + 1);

        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = 1e4; j >= 0; j--){
                if(j + a[i] < sz(dp)) dp[j + a[i]] = dp[j] | dp[j + a[i]];
                if(j + b[i] < sz(dp)) dp[j + b[i]] = dp[j] | dp[j + b[i]];

                dp[j] = 0;
            }
        }
        int mn = infinity;

        for(int i = 0; i <= 1e4; i++){
            if(dp[i]){
                amin(mn, i*i + (A + B - i)*(A + B - i) + overhead);
            }
        }
        cout << mn << endl;
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