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

vi in;
int n;
vi ans;
vi depth;
vi visited;
vector<vector<int>> g;

void bfs(int parity){
        queue<int> q;

        l(i, 0, n){
                
                if(in[i] % 2 == parity) visited[i] = 1, q.push(i);
        }

        while(q.empty() == false){
                int top = q.front(); q.pop();

                for(auto p : g[top]){
                        if(!visited[p]){
                                visited[p] = 1;
                                depth[p] = depth[top] + 1;

                                if(in[p] % 2 == (parity ^ 1)) ans[p] = depth[p];

                                q.push(p);
                        }
                }
        }
}

int32_t main(){
        
        FIO

        cin >> n; in = vi(n);

        g = vector<vector<int>> (n);

        for(auto &p : in) cin >> p;

        depth = vi(n);

        ans = vi(n, -1);

        visited = vi(n, 0);

        l(i, 0, n){
                int cur = in[i];

                if(i - cur >= 0) g[i].pb(i - cur);

                if(i + cur < n) g[i].pb(i + cur);
        }
        vector<vector<int>> g_ (n);

        l(i, 0, n){
                l(j, 0, sz(g[i])){
                        g_[g[i][j]].pb(i);
                }
        }
        g = g_;

        bfs(0);

        depth = vi(n);

        visited = vi(n);

        bfs(1);

        for(auto p : ans) cout << p << ' '; cout << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/