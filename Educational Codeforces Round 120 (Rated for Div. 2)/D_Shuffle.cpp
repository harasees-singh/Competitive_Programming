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
#define w(t)                            int t; cin >> t; while(t--)
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

MOD_DEFINE
string s; int n;

const int N = 200000 + 5;
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
ll p = 998244353;

// int getlen(int i){
//         int cnt = 0;

//         for(int j = i; j < n; j++) {if(s[j] == '0') cnt++; else break;}

//         for(int j = i - 1; j >= 0; j--) {if(s[j] == '0') cnt++; else break;}

//         return cnt;
// }

int32_t main(){
        
        FIO

        InverseofNumber(p);
        InverseofFactorial(p);
        factorial(p);

        int k; cin >> n >> k;

        cin >> s;

        int ans = 0;

        vi vis(n);

        for(int i = 0; i < n; i++){
                if(s[i] == '0') continue;

                int j = i;
                int cnt = 0;
                int Sub = 0;
                int N = 0;
                bool sub = false; 
                for(int k = i - 1; k >= 0; k--){
                        if(s[k] == '1') break; 
                        
                        N++; 

                        if(vis[k]) sub = true; else vis[k] = 1;
                }
                if(sub and k > 1) Sub += N;

                while(j < n and cnt < k){
                        int zero = 0;
                        if(s[j] == '1') cnt++; j++; N++;
                        bool sub = false;

                        if(vis[j]) sub = true;
                        while(j < n and s[j] == '0') zero++, vis[j] = 1, j++, N++;

                        if(sub and k > 1) Sub += zero;
                }
                if(cnt == k) 
                        if(N > k)
                                ans += Binomial(N, k, p) - 1, ans -= Sub, ans += p, ans %= p;

        }
        cout << (ans + 1) % p << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/