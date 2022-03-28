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
mii D, N;

void fill(int n, mii &M){
    int cpy(n);
    for(int i = 2; i * i <= cpy; i++){
        while(n % i == 0) M[i]++, n/=i;
    }
    if(n > 1) M[n] += 1;
}
int32_t main(){
        
        FIO

        w(t){
            int n, d; cin >> n >> d;

            D.clear(); N.clear();

            if(n % (d * d) or n <= d * d){
                cout << "NO" << endl; continue;
            }
            // should be of the form d * d * something
            // then we can divide something into parts such dat no part is beautiful and distribute them over our 2 beautiful numbers

            // if n is a power of d and d is prime then answer is always no

            // if n = d * d then answer is no

            // consider n / (d * d), 

            // iteratie over it's prime numbers frequency map


            // store prime, frequency

            fill(n, N); fill(d, D);

            // for(auto p : D) cout << p << endl; 
            // cout << endl;
            // for(auto p : N) cout << p << endl; 

            for(auto p : D){
                assert(2 * p.ss <= N[p.ff]);
                // if(2 * p.ss > N[p.ff]){
                //     cout << "! " << p << endl;

                //     cout << n << ' ' << d << endl;
                // }

                N[p.ff] -= 2 * p.ss;
            }
            int cnt = 0;

            for(auto p : N){
                if(p.ff != d){
                    cnt++;

                    if(p.ss > 1) cnt++;
                }
            }
            cout << (cnt >= 2 ? "YES": "NO") << endl;
            
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