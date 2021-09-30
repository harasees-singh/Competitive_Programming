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
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE
template<typename T>
T power(T x, T y, ll p) { 
    T res = 1;     
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
int32_t main(){
    FIO
    test_cases_loop{
        int n; cin >> n;

        int cpy = n;

        umii primes;

        for(int i = 2; i <= sqrt(n); i++)
                while(n%i == 0)
                        n/=i, primes[i]++;
        if(n > 1)
                primes[n]++;
        
        int maxi = 0;
        int prime;

        for(auto p : primes)
                if(p.ss > maxi)
                        maxi = p.ss, prime = p.ff;

        cout << maxi << endl;
        int pw = 1;

        l(i, 0, maxi - 1)
                pw *= prime;
        
        l(i, 0, maxi - 1)
                cout << prime << space;
        
        cout << cpy/pw << endl;
                
    }

}
