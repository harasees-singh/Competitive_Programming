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
int power(int x, int y, ll p) { 
    int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    // cout <<"x= "<< x << endl;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    // cout << "res" << res << endl;
    return res; 
} 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
 
int nCr(int n, int r){

    if(r == 0) return 1;

    return (nCr(n - 1, r - 1)*(((n)*(modInverse(r, MOD)))%MOD))%MOD;
}

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;
        int k; cin >> k;

        // vector<pii> I;

        map<int, int> freq;

        l(i, 0, n)
        {
            int t; cin >> t;

            freq[t]++;
        }

        auto it = --freq.end();

        int ans = 0;

        while(true){

            int pick = min(k, (*it).ss); k-= pick;

            if(k == 0)  
                    {ans = nCr((*it).ss, pick); break;}
            it--;
        }

        // cout << nCr(5, 3) << endl;

        cout << ans << endl;
    }

}
