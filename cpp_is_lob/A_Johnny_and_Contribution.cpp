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

        int n, m; cin >> n >> m;

        vector<vi> g(n + 1);

        for(int i = 0; i < m; i++){
                int u, v; cin >> u >> v;

                g[u].pb(v); g[v].pb(u);
        }
        vector<pii> val;
        for(int i = 1; i <= n; i++){
                int u; cin >>u;

                val.pb(make_pair(u, i));
        }

        sort(all(val));

        vi dp(n + 1); 

        for(auto p : val){
                int need, id; tie(need, id) = p;
                vi hogya(need);
                for(auto u : g[id]){
                        if(dp[u]){
                                if(dp[u] == need){
                                        cout << -1; return 0;
                                }
                                hogya[dp[u]] = 1;
                        }
                }
                // cout << id << endl;


                for(int i = 1; i < need; i++){
                        // cout << hogya[i] << ' ';
                        if(not hogya[i]){
                                cout << -1; return 0;
                        }
                }

                dp[id] = need;
        }
        for(auto p : val)
                cout << p.ss << ' ';

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/