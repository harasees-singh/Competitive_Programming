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
int get(int i){
        int cnt=0;
        for(; i; cnt++){
                i/=10;
        }
        return cnt;
}
int32_t main(){
        
        FIO
        int n, k; cin >>n >> k; 

        vi in(n); 

        for(auto &p : in) cin >> p;

        map<int, vi> dp; // {rem, {}} vector stores number of instances of that rem for i len

        for(auto p : in){
                int len = get(p);
                if(!dp.count(p % k))
                        dp[p % k] = vi(11);
                
                dp[p % k][len]++;
        } 
        // for(auto p : dp){
        //         cout << p.ff << endl;
        //         for(auto q : p.ss){
        //                 cout << q << ' ';
        //         }
        //         cout << endl;
        // }
        cout.flush();
        int ans = 0;
        for(auto p : in){
                for(int i = 1, mul = 10; i <= 10; i++, mul *= 10){
                        int need = (k - (((mul%k) * (p%k)) % k)) % k;

                        if(dp.count(need))
                                ans += dp[need][i];

                        ans -= ((need == p%k) and (get(p)==i));
                }
        }
        cout << ans;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/