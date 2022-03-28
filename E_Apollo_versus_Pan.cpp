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
int f(int x, int c){
    return (x >> c) & 1;

    // is cth bit on or not
}
vi precompute;
int32_t main(){
        
        FIO

        w(T){
            int n; cin >> n;

            precompute = vi(60);

            vi in(n); for(auto &p : in) cin >> p;

            // precompute summation i from 1 to n {f(xi, c)} for all cs from 0 to 59;

            for(int bit = 0; bit < 60; bit++){
                for(int i = 0; i < n; i++)
                    precompute[bit] += f(in[i], bit);

                // cout << precompute[bit] << ' ';
            }
            // cout << endl;
            int out = 0;
            
            for(int j = 0; j < n; j++){
                int Andj = 0, ORj = 0;

                for(int bit = 0; bit < 60; bit++){
                    Andj += ((1ll << bit) % MOD) * precompute[bit] * f(in[j], bit);

                    ORj += ((1ll << bit) % MOD) * (n - (1 - f(in[j], bit)) * (n - precompute[bit]));

                    Andj %= MOD; ORj %= MOD;
                }

                out += Andj * ORj; out %= MOD;
            }
            cout << out << endl;
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