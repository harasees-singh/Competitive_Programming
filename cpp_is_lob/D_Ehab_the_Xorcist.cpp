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

int32_t main(){
        
        FIO

        // xor = u, sum = v;

        int u, v; cin >> u >> v;

        // assert(u <= v);

        // ans always less than 4

        // u, (v - u)/2, (v - u)/2;

        // assert((u - v) % 2 == 0); // xor and sum have the same parity

        // u = 2, v = 4;

        // 2, 1, 1 // 2 ^ 1 == 1 + 2 so can combine

        // 0 0 exception answer = empty array

        // if u == v answer = {u};
        
        if(u == v){
                if(u == 0){
                        cout << 0; return 0;
                }
                cout << 1 << endl << u; return 0;
        }
        if(u%2 != v%2 or v < u){
                cout << -1; return 0;
        }
        vi ans(3);

        ans[0] = u; ans[1] = ans[2] = (v - u)/2;

        if((ans[0] ^ ans[1]) == ans[0] + ans[1]){
                cout << 2 << endl << (ans[0] ^ ans[1]) << ' ' << ans[2]; return 0;
        }
        cout << 3 << endl;
        for(auto p : ans) cout << p << ' ';


        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/