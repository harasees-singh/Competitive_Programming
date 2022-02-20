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

int N;
vi explosion;
int * Rank;
int * parent;
int * treesize;
int findParent(int v){

        if(parent[v] == v)
                return v;
        
        return parent[v] = findParent(parent[v]);
}
int nodecnt(int i){
        i = findParent(i);

        return treesize[i]; // node cnt including the parent itself
}
void MakeSet(){
        for(int i = 0; i < N; i++)
                parent[i] = i, Rank[i] = 0, treesize[i] = 1;
}

void Union(int u, int v){

        u = findParent(u), v = findParent(v);

        if(u == v) return; // already united

        if(Rank[u] > Rank[v])
                parent[v] = u, explosion[u] = min(explosion[u], explosion[v]);
        else if(Rank[u] < Rank[v])
                parent[u] = v, explosion[v] = min(explosion[u], explosion[v]);
        else        
                parent[v] = u, Rank[u]++, explosion[u] = min(explosion[u], explosion[v]);
}

int32_t main(){
        
        FIO

        w(t){
                cin >> N; int k; cin >> k;
                Rank = new int[N];
                parent = new int[N];
                treesize = new int[N];

                explosion = vi(N);
                MakeSet();

                vector<pii> coord;

                // vector<pii> X, Y;       // {x, id} ids are 0 based
                map<int, vector<pii>> X, Y;

                l(i, 0, N){
                        int u, v, t; cin >> u >> v >> t;

                        coord.push_back({u, v}); explosion[i] = t;

                        X[u].push_back({v, i}); Y[v].push_back({u, i});
                }
                for(auto &p : X) sort(all(p.ss));
                for(auto &p : Y) sort(all(p.ss));

                l(i, 0, N){
                        int u, v; tie(u, v) = coord[i];

                        // bin search for v in X[u], take the adj elements and union their ids with i

                        auto it = lower_bound(all(X[u]), make_pair(v, i));

                        if(it != X[u].begin() and abs((*(it - 1)).ff - v) <= k) Union(i, (*(it - 1)).ss);

                        if(it != prev(X[u].end()) and abs((*(it + 1)).ff - v) <= k) Union(i, (*(it + 1)).ss);

                        it = lower_bound(all(Y[v]), make_pair(u, i));

                        if(it != Y[v].begin() and abs((*(it - 1)).ff - u) <= k) Union(i, (*(it - 1)).ss);

                        if(it != prev(Y[v].end()) and abs((*(it + 1)).ff - u) <= k) Union(i, (*(it + 1)).ss);

                }

                vi vis(N);

                vector<pii> time_id; 
                
                l(i, 0, N) time_id.push_back(make_pair(explosion[findParent(i)], i));

                sort(all(time_id));

                reverse(all(time_id));

                int i = 0; int time = 0; 

                for(; i < N; i++){
                        auto p = time_id[i]; 

                        if(vis[findParent(p.ss)]) continue; 

                        if(time > p.ff) break;
                        
                        vis[findParent(p.ss)] = 1;

                        time++;

                }
                cout << time - 1 << endl;

                delete []parent;
                delete []Rank;
                delete []treesize;
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