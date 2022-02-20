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
// 1 1 1 1 0 1
// 1 1 0 1 0 1 -> reject = 1 (size)
// 1 1 0 1 0 1
// 0 0 0 0 0 0 -> 4 == count of 1s
// bits[id] = 1;
// 1 1 0 1 0 1


int32_t main(){
        
        FIO

        int n, m; cin >>  n >> m;

        vector<vi> can_select(n, vi(m, 1));

        vi a(n), b(m);  

        for(auto &p : a) cin >> p; for(auto &p : b) cin >> p;

        vi bits(10);
        // greedily reject ele that will turn on the ith bit
        for(int i = 9; i >= 0; i--){
                vector<vi> reject(n); 
                bool flag = 1;
                l(j, 0, n){

                        l(id, 0, m){
                                if(can_select[j][id]){
                                        if((1 << i) & ((int)(b[id] & a[j]))) reject[j].pb(id);
                                }
                        }
                        if(sz(reject[j]) == count(all(can_select[j]), 1)){
                                // cout << i << ' ' << j << endl;
                                // if(i == 5 and j == 0){
                                //         // for(auto p : can_select[j]) cout << p << ' '; cout << endl;
                                //         // for(auto p : reject) cout << p << ' '; cout << endl;
                                //         // cout << "OK" << endl;
                                // }
                                bits[i] = 1;

                                flag = 0;

                                break;
                        }
                }
                if(flag){
                        l(j, 0, n){
                                l(k, 0, sz(reject[j])) can_select[j][reject[j][k]] = 0;
                        }
                }
        }
        int mul = 1;
        int ans = 0;
        for(auto p : bits) ans += mul * p, mul *= 2;

        cout << ans << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/