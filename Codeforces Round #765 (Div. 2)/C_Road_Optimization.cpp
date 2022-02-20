// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        INT32_MAX
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
// for this id, for this value at that id, for this k 
// ans = dp[id][val][k];
// n*n*k
vector<map<int, mii>> dp;
int n;
vi timeperunit;
vi dist;
int dfs(int i, int k){
        if(i == n - 1)
                return (dist[n] - dist[n - 1]) * (timeperunit[i]);
        
        if(dp[i].count(timeperunit[i]) and dp[i][timeperunit[i]].count(k))
                return dp[i][timeperunit[i]][k];

        int store = timeperunit[i + 1];

        timeperunit[i + 1] = timeperunit[i];

        int x = timeperunit[i] * (dist[i + 1] - dist[i]), y = timeperunit[i] * (dist[i + 1] - dist[i]);

        if(k and timeperunit[i] < store)
                x += dfs(i + 1, k - 1);
        else 
                x = infinity;

        timeperunit[i + 1] = store;

        y += dfs(i + 1, k);

        return dp[i][timeperunit[i]][k] = min(x, y);
}

int32_t main(){
        
        FIO
        int l, k; cin >> n >> l >> k;

        timeperunit = vi(n); 

        dist = vi(n);

        for(auto &p : dist) cin >> p;

        for(auto &p : timeperunit) cin >> p;

        dist.pb(l);

        dp = vector<map<int, mii>> (n);

        cout << dfs(0, k) << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/