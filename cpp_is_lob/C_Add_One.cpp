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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

vector<vector<int>> dp;

int dfs(int x, int k){
        if(k + x < 10 or k == 0) return 1;

        if(x > 1) return (dfs(1, k - (10 - x)) + dfs(0, k - (10 - x)))%MOD;

        if(dp[x][k] != -1) return dp[x][k];

        return dp[x][k] = (dfs(1, k - (10 - x)) + dfs(0, k - (10 - x)))%MOD;
}

int32_t main(){
        
        FIO
        dp = vector<vi>(2, vi(2e5 + 1, -1));

        w(t){
                int n, k; cin >> n >> k;


                int cnt = 0;

                while(n){
                        cnt += dfs(n%10, k); n/=10;
                        cnt%=MOD;
                }
                cout << cnt << endl;
        }
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/