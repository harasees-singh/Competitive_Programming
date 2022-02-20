// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 998244353;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
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

MOD_DEFINE
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        int q = a / m;
        int t = m;
 
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        y = x - q * y;
        x = t;
    }
 
    if (x < 0)
        x += m0;
 
    return x;
}
// 999999999999999999
int inverse2;
int calc(int i){
        return ((((i % MOD) * ((i + 1) % MOD)) % MOD) * inverse2) % MOD;
}
int get(int i){
        if(i <= 9){
                return (i * (i + 1)) / 2 ;
        }

        int len = sz(to_string(i));

        // string ten = "1";
        int ten = 1;

        for(int i = 0; i < len - 1; i++) ten*=10;

        // cout << ten << endl;

        int tenpower = ten;

        int tot = calc(i - tenpower + 1);
        // cout << tot << endl;

        return (tot + get(tenpower - 1)) % MOD;
}

int32_t main(){
        FIO 
        inverse2 = modInverse(2, MOD);
        // cout << inverse2 << endl;
        int n; cin >> n;
        cout << get(n) << endl;
        return 0;
}
