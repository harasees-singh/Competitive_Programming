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
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE
vector<vi> g;
int n, m;
int32_t main(){
        
        FIO

        w(t){
                cin >> n >> m; g = vector<vi>(n + 1);

                l(i, 0, m){
                        int u, v; cin >>u >> v;
                        g[u].pb(v);
                        g[v].pb(u);
                }

                vi col(n);

                queue<int> q;

                vi vis(n + 1);

                q.push(1); int black = 1; col[0] = 1;
                vis[1] = 1;
                // 1 means black

                while(q.empty() == false){

                        int s = q.size();
                        black = black ^ 1;

                        while(s--){
                                int t = q.front();

                                q.pop();

                                for(auto p : g[t]){
                                        if(not vis[p]){
                                                vis[p] = 1; col[p - 1] = black;

                                                q.push(p);
                                        }
                                }
                        }
                }
                int cnt = count(all(col), 1);
                // for(auto p : col) cout << p << ' '; cout << endl;
                if(cnt <= n/2){
                        cout << cnt << endl;
                        for(int i = 0; i < n; i++) 
                                if(col[i])
                                        cout << i + 1 << ' ';
                        
                }
                else{
                        cout << n - cnt << endl;
                        for(int i = 0; i < n; i++)
                                if(col[i] == 0)
                                        cout << i + 1 << ' ';
                }
                cout << endl;
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