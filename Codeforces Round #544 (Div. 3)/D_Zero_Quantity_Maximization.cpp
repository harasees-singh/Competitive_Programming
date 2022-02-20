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
// #define int                             long long
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
// {-bi, ai} 
pii reduce(int num, int den){
        if(den==0){
                if(num==0) return {0, 0};
                else return {-1, -1};
        }
        int gcd = __gcd(abs(num), abs(den));

        if(den < 0) num *= -1;

        return make_pair(num/gcd, abs(den)/gcd);
}
int32_t main(){
        
        FIO

        map<pii, int> f;

        int n; cin >> n;

        vi a(n), b(n); for(auto &p : a) cin >> p; for(auto &p : b) cin >> p;
        int zero_zero = 0;
        for(int i = 0; i < n; i++){
                pii t = reduce(-b[i], a[i]);
                if(t == make_pair(-1, -1)){
                        continue;
                }
                if(t == make_pair(0, 0)){
                        zero_zero++;
                        continue;
                }
                f[t]++;
        }
        int mx = 0;

        for(auto p : f){ 
                       
                mx = max(mx, p.ss);
        }

        cout << mx + zero_zero << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/