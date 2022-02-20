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

        int n, k; cin >> n >> k;

        string s; cin >> s;

        vector<vi> lst(n + 1, vi(26, -1));

        for(int i = n - 1; i >= 0; i--){
                for(int j = 0; j < 26; j++)
                        lst[i][j] = lst[i + 1][j];

                int cur = s[i] - 'a';

                lst[i][cur] = i;
        }

        vector<vi> dp(n + 1, vi(n + 1));

        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int i = n - 1; i >= 0; i--){
                for(int j = 1; j <= n; j++){
                        for(int ch = 0; ch < 26; ch++){
                                if(lst[i][ch] != -1){
                                        dp[i][j] += dp[lst[i][ch] + 1][j - 1];

                                        dp[i][j] = min(dp[i][j], k);
                                }
                        }
                }
        }
        int cnt = 0;
        int ans = 0;
        for(int cost = 0; cost <= n; cost++){
                int need = min(k - cnt, dp[0][n - cost]);

                ans += cost * need;

                cnt += need;
        }
        cout << (cnt == k ? ans : -1) << endl;

        return 0;
}
