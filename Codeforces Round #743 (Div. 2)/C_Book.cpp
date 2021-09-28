#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define Set                             tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;

MOD_DEFINE

// time to read the book is  1 + max(time to read the children)

// if child returns -1 (it means it was not connected to 0) break and cout << -1;

int dfs(int n, vector<vi> &adj, vi &visited, vi &dp){

    int ans = 0;

    if(n == 0) return 0;

    for(int i = 0; i < sz(adj[n]); i++){

        int child = adj[n][i];
        
        if(visited[child] and child){

            if(dp[child] == -1) {dp[n] = -1; return -1;}

            int ret = 1 + dp[child];

            ret -= (bool)(child < n); 

            ans = max(ans, ret);

            continue;
        }

        visited[child] = 1;

        int ret = dfs(child, adj, visited, dp);

        if(ret == -1) {dp[n] = -1;  return -1;}

        ret -= (bool)(child < n and ret);

        ans = max(1 + ret, ans);
        
    }

    dp[n] = ans;

    return ans;
}

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;

        vector<vi> adj(n + 1);

        l(i, 0, n){

            int p; cin >> p;

            if(p == 0) adj[i + 1].push_back(0);

            l(j, 0, p){

                int t; cin >> t;

                adj[i + 1].push_back(t);
            }
        }
        vi visited(n + 1);

        bool ok = true;

        int gans = 0;

        vi dp(n + 1, -1);

        l(i, 1, n + 1){
            
            int ans;

            if(visited[i])

                    ans = dp[i];

            else {

                visited[i] = 1;

                ans = dfs(i, adj, visited, dp);

                dp[i] = ans;
            }

            if(ans == -1) {ok = false; break;}

            gans = max(ans, gans);
        }

        if(ok) cout << gans << endl; else cout << -1 << endl;
        
    }
}