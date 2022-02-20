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

bool cycle = false;
vi vis;
vector<vi> g;
void dfs(int i, int parent){
        if(vis[i] == 2){
                return;
        }
        if(vis[i] == 1){
                cycle = true; return;
        }
        vis[i] = 1;
        for(auto p : g[i])
                if(p != parent)
                        dfs(p, i);
        vis[i] = 2;
}

int32_t main(){
        
        FIO

        int n, m; cin >> n >> m;
        g = vector<vi> (n + 1);
        vis = vi(n + 1);
        mii f;

        l(i, 0, m){
                int u, v; cin >> u >> v;
                g[u].pb(v);
                g[v].pb(u);
                f[u]++;

                f[v]++;
        }
        bool ok = 1;

        for(auto p : f){
                ok = ok & (p.ss < 3);
        }

        l(i, 1, n + 1){
                if(!vis[i])
                        dfs(i, 0);
        }

        cout << (ok and !cycle ? "Yes" : "No") << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/