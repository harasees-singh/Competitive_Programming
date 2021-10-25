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
#define space                           " "
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
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

vi vis;

vector<set<int>> g;

vi depth;

int bfs(int n){

        queue<int> Q;

        vis[1] = 1;

        int d = 0;

        Q.push(1);

        while(!Q.empty()){

                int x = Q.front(); Q.pop();

                for(auto p : g[x]){

                        if(p == n)
                                return ++depth[x];

                        if(!vis[p])
                                vis[p] = 1, Q.push(p), depth[p] = 1 + depth[x];
                }

        }
        return -1;
}


int32_t main(){
    FIO

    int n, m; cin >> n >> m;
    
    depth = vi(n + 1);

    g = vector<set<int>> (n + 1);

    bool ok = 0;

    l(i, 0, m){
            int u, v; cin >> u >> v;

            ok = ok or (u == 1 and v == n or v == 1 and u == n);

            g[u].insert(v), g[v].insert(u); 
    }

    vis = vi(n + 1);

    if(ok){
            l(i, 1, n + 1){
                    set<int> t;

                    l(j, 1, n + 1)
                            if(g[i].count(j) == 0)
                                    t.insert(j);
                    
                    g[i] = t;
            }

    }

    // l(i, 1, n + 1){
    //         for(auto p : g[i])
    //                 cout << p << space; cout << endl;
    // }

    cout << bfs(n) << endl;

    return 0;

}
