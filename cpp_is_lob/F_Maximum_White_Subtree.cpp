// ਹਰਅਸੀਸ ਸਿੰਘ

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

vector<vi> g;
vi dp; // stores the answer to each node considering it as the root and it's subtree as the whole tree.
vi color;
vi ans;

int dfs(int i, int p){
        dp[i] = (color[i] ? 1 : -1);
        for(auto c : g[i])
                if(c != p) // not parent
                        dp[i] += max(0ll, dfs(c, i));

        return dp[i];
}

void reRoot(int i, int p){
        ans[i] = dp[i];

        for(auto c : g[i])
                if(c != p){ // not parent
                        dp[i] -= max(0ll, dp[c]);
                        dp[c] += max(0ll, dp[i]);
                        reRoot(c, i);
                        dp[c] -= max(0ll, dp[i]);
                        dp[i] += max(0ll, dp[c]);
                }       
}

int32_t main(){
        
        FIO

        int n; cin >> n;

        g = vector<vi> (n + 1);
        dp = vi(n + 1);
        color = vi(n + 1);
        ans = vi(n + 1);

        l(i, 0, n)
                cin >> color[i + 1];

        l(i, 0, n - 1){
                int u, v; cin >> u >> v;

                g[u].pb(v), g[v].pb(u);
        }

        dfs(1, 0);

        reRoot(1, 0);

        l(i, 1, n + 1)
                cout << ans[i] << ' ';
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/