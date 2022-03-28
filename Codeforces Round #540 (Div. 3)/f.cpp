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

vector<vi> g;
vi in;
vector<pii> dp; // {red, blue}
pii dfs(int i, int parent){
        pii r_b;
        for(auto p : g[i]){
                if(p != parent){
                        pii ret = dfs(p, i);
                        r_b.ff += ret.ff;
                        r_b.ss += ret.ss;
                }               
        }

        r_b.ff += (in[i - 1] == 1);

        r_b.ss += (in[i - 1] == 2);

        dp[i] = r_b;

        return r_b;
}
int cnt = 0;

void reroot(int i, int p){
        // calc ans of edge b/w i and it's children
        for(auto q : g[i]){
                if(q != p){

                        dp[i].ff -= dp[q].ff; dp[i].ss -= dp[q].ss;
                        // re-root at q
                        cnt += ((dp[i].ff == 0 and dp[q].ss == 0) or (dp[i].ss == 0 and dp[q].ff == 0));

                        dp[q].ff += dp[i].ff; dp[q].ss += dp[i].ss;
                        
                        reroot(q, i);
                        // backtrack

                        dp[q].ff -= dp[i].ff; dp[q].ss -= dp[i].ss;
                        dp[i].ff += dp[q].ff; dp[i].ss += dp[q].ss;
                }
        }

}

int32_t main(){
        FIO 

        int n; cin >> n;

        in = vi(n);

        for(auto &p : in) cin >> p;

        g = vector<vi>(n + 1);

        dp = vector<pii>(n + 1);

        for(int i = 0; i < n - 1; i++){
                int u, v; cin >> u >> v;

                g[u].pb(v);

                g[v].pb(u);
        }

        dfs(1, 0);

        reroot(1, 0);

        cout << cnt << endl;

        return 0;
}
