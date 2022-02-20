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
string ans;
vi vis;
void dfs(int i){
        if(vis[i]) return;

        vis[i] = 1;
        ans[i] = '1';

        for(auto &p : g[i]){
                dfs(p);
        }       
}
int32_t main(){
        
        FIO

        w(t){
                int n; cin >> n;

                vis = vi(n);

                ans = string(n, '0');

                vpii a(n);

                l(i, 0, n){
                        int t; cin >> t; a[i] = {t, i};
                }
                vpii b(n);

                l(i, 0, n){
                        int t; cin >> t; b[i] = {t, i};
                }

                sort(a.rbegin(), a.rend());

                sort(b.rbegin(), b.rend());

                g = vector<vi>(n);

                for(int i = 0; i < n - 1; i++){
                        int u, v; u = a[i].ss, v = a[i + 1].ss;

                        g[u].pb(v);
                }
                for(int i = 0; i < n - 1; i++){
                        int u, v; u = b[i].ss, v = b[i + 1].ss;

                        g[u].pb(v);
                }
                vector<vi> t(n);

                for(int i = 0; i < n; i++){
                        for(auto &p : g[i]){
                                t[p].pb(i);
                        }
                }
                g = t; // reverse the directed edges

                dfs(b[0].ss);

                cout << ans << endl;
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