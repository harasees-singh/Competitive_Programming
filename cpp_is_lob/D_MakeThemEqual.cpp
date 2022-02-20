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
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
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

int32_t main(){
        FIO 
        vector<int> cost(1e3 + 1, infinity);
        
        cost[1]=cost[0]=0;      
        // filling this in n * sqrt(n)
        for(int i = 1; i <= 1e3; i++){
                int j = 1;
                for(; j * j < i; j++){
                        if(i + i/j > 1e3) continue;

                        cost[i + i/j] = min(cost[i + i/j], 1 + cost[i]);
                }

                int limit = i/j;

                for(int k = 1; k <= limit; k++){
                        if(i + k > 1e3) break;

                        cost[i + k] = min(cost[i + k], 1 + cost[i]);
                }
        }
        assert(*max_element(all(cost)) < 20);

        w(t){
                int n, k; cin >> n >> k;

                vi b(n), c(n);

                for(auto &p : b) cin >> p;
                for(auto &p : c) cin >> p;

                vector<int> dp(20 * n, -1);
                // 2e4 at max

                dp[0] = 0;
                int it = 0;
                for(auto p : b){
                        int will_cost = cost[p];   

                        int value = c[it];

                        vi cpy(dp);

                        for(int i = 0; i < sz(dp); i++){
                                if(dp[i] != -1){
                                        cpy[i + will_cost] = max(dp[i + will_cost], dp[i] + value);
                                }
                        }
                        dp = cpy;
                        it++;
                }
                int mx = 0;

                for(int i = 0; i <= min(k, sz(dp) - 1); i++){
                        mx = max(mx, dp[i]);
                }
                cout << mx << endl;
        }

        return 0;
}
