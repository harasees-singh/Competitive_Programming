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
int paint(pii &u){
        return u.ss == 0 ? 0 : 1;
}
vector<vpii> g;
vi vis;
int c[2];
bool ok;
void dfs(int id, int color){
        
        for(auto p : g[id]){
                int col = (color^paint(p));
                if(vis[p.ff] != -1){
                        if(vis[p.ff] != col){
                                ok = 0;
                        }
                }
                else{    
                        vis[p.ff] = col,
                        c[col]++;
                        dfs(p.ff, col);
                }
        }
}

int32_t main(){
    FIO

    w(t){

                int n, m; cin >> n >> m;
                ok = 1;

                g = vector<vpii>(n + 1);
                vis = vector<int>(n + 1, -1);

                l(i, 0, m){
                        int u, v; cin >> u >> v;
                        string s; cin >> s;
                        
                        

                        // if a says b's a crewmate => they r on the same team => add edge with weight zero
                        // else add an edge with weight 1
                        // color nodes, if colors collide print -1 and call it a day.

                        if(s == "imposter")
                                g[u].push_back(make_pair(v, 1)), g[v].push_back(make_pair(u, 1));

                        else    
                                g[u].push_back(make_pair(v, 0)), g[v].push_back(make_pair(u, 0));
                        
                        
                }

                int cnt = 0;

                l(i, 1, n + 1){

                        c[0] = c[1] = 0;

                        if(vis[i] == -1){
                                vis[i] = 0, c[0] = 1;

                                dfs(i, 0);
                        }
                        cnt += max(c[0], c[1]);
                }
                if(!ok){
                        cout << -1 << endl; continue;
                }

                cout << cnt << endl;

             
    }

}
