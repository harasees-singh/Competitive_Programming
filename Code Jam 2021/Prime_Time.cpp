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

        // worst case sum of numbers in the product set = 60 * 499; 

        // roughly 3e4

        // for all numbers in tot - 3e4 to tot (3e4 + 1 numbers), get their prime factorization

        // and check if they satisfy prod (the number itself) == sum of remaining primes in O(100);

        int test; cin >> test;

        vi SIEVE(500, 1);

        SIEVE[0] = SIEVE[1] = 0;
    
        for(int i = 2; i < 500; i++){
            for(int j = i * i; j < 500; j += i){
                SIEVE[j] = 0;
            }
        }

        for(int T = 1; T <= test; T++){
            int mx = 0;
            cout << "Case #" << T << ": "; 

            int n; cin >> n;

            mii primes;
            
            for(int i = 2; i < 500; i++){
                if(SIEVE[i]) primes[i] = 0;
            }
            for(int i = 0; i < n; i++){
                int p, j; cin >> p >> j;

                primes[p] = j;
            }
            int tot = 0;

            for(auto p : primes) tot += p.ff * p.ss;

            mii cpymap(primes);

            int L = max(0ll, (int)(tot - 3e4));

            for(int op = L; op <= tot; op++){
                // if sum set has a sum op
                primes = cpymap;
                int cpy(op);
                // it's prime factorization (which is unique should converge into primes map);
                int rem = op;
                for(auto p : primes){
                    while(op % p.ff == 0 and p.ss) op /= p.ff, p.ss--;

                    rem -= p.ss * p.ff;
                }
                if(rem == 0 and op == 1){
                    amax(mx, cpy);
                }
                op = cpy;
            }
            cout << mx << endl;
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