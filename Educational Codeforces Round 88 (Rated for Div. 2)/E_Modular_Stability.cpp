#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

// call these to initialize arrays 
// O(1) time complexity 
// use Binomial(n, r, p) all exceptions handled
/*
InverseofNumber(p);
InverseofFactorial(p);
factorial(p);
*/

ll p = 998244353;

const int N = 500000 + 5;

ll factorialNumInverse[N + 1];
 
ll naturalNumInverse[N + 1];
 
ll fact[N + 1];

 
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll Binomial(ll N, ll R, ll p)
{
	if(R > N or R < 0 or N < 0) return 0;
    ll ans = ((fact[N] * factorialNumInverse[R])% p * factorialNumInverse[N - R])% p;
    return ans;
}



int32_t main(){
    FIO

    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);

    int n, k; cin>> n >> k;

    if(n < k){
            cout << 0 << endl;

            return 0;
    }
    if(n == k){
            cout << 1 << endl;
            return 0;
    }
    int ans = 0;

    l(i, 1, n + 1){
            int P = n/i - 1;

            int r = k - 1;

            if(p >= r)
                    ans += Binomial(P, r, p), ans %= p;
            
            else    
                    break;
    }
    cout << ans << endl;
}
