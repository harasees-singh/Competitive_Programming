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

// size[i] -> size of ith node's subtree
// sizes of each child's subtree ✔️
// if ith node is the root, size of the subtree which contains i's parent = n - (total number of nodes in i's subtrees) - 1
// take max over all subtree sizes and then minimize it
// assuming at max 2 centroids, incase there are 2 they will have an edge in between
// take a subtree of one of the centroids and join it to the other
vector<vi> g;
int n;
vi subsize;

int dfs(int i, int p){
        int cnt = 0;

        for(auto &x : g[i]){
                if(p != x) cnt += dfs(x, i); 
        }
        subsize[i] = cnt;

        return 1 + cnt;
}

vi centroids;

int mn;

void rerootdfs(int i, int p, int parentsubtree){
        // parentsubtree -> size of parent's subtree if i is the root

        int mx = parentsubtree;

        for(auto &c : g[i]){
                if(c != p){
                        mx = max(mx, 1 + subsize[c]);

                        rerootdfs(c, i, n - subsize[c] - 1);
                }
        }
        if(mx < mn){
                centroids = vi();
                centroids = {i};
                mn = mx;
        }
        else if(mx == mn) centroids.pb(i);
}

int32_t main(){
        
        FIO

        w(t){
                cin >> n;

                mn = infinity;

                subsize = vi(n + 1);

                g = vector<vi> (n + 1);

                l(i, 0, n - 1){
                        int u, v; cin >> u >> v;

                        g[u].pb(v);
                        g[v].pb(u);
                }
                dfs(1, 0);
                rerootdfs(1, 0, 0);

                assert(sz(centroids) <= 2);

                if(sz(centroids) == 2){
                        int u = centroids[0];
                        int v = centroids[1];

                        for(auto p : g[u]){
                                if(p != v){
                                        cout << u << ' ' << p << endl;
                                        cout << v << ' ' << p << endl; break;
                                }
                        }
                }
                else{
                        int u = centroids[0];

                        cout << u << ' ' << g[u][0] << endl;
                        cout << u << ' ' << g[u][0] << endl;
                }
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