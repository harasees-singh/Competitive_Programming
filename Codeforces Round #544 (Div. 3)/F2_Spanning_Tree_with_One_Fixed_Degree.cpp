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
struct DisjointSet{
        int N;

        int * Rank;
        int * parent;
        int * treesize;

        DisjointSet(int n){
                N = n;
                Rank = new int[N + 1];
                parent = new int[N + 1];
                treesize = new int[N + 1];
                MakeSet();
        }
        

        void MakeSet(){
                for(int i = 1; i <= N; i++)
                        parent[i] = i, Rank[i] = 0, treesize[i] = 1;
        }

        int findParent(int v){

                if(parent[v] == v)
                        return v;
                
                return parent[v] = findParent(parent[v]);
        }

        bool Union(int u, int v){

                u = findParent(u), v = findParent(v);

                if(u == v) return false;

                if(Rank[u] > Rank[v])
                        parent[v] = u, treesize[u] += treesize[v];
                else if(Rank[u] < Rank[v])
                        parent[u] = v, treesize[v] += treesize[u];
                else        
                        parent[v] = u, Rank[u]++, treesize[u] += treesize[v];

                return true;
        }
        int nodecnt(int i){
                i = findParent(i);

                return treesize[i]; // node cnt including the parent itself
        }
        ~DisjointSet(){
                delete []parent;
                delete []Rank;
                delete []treesize;
        }
};
int32_t main(){
        
        FIO

        int n, m, D; cin >> n >> m >> D;

        DisjointSet dsu(n);

        vector<pii> edges;

        vector<pii> one_adj; 
        int unite = 0;
        vector<vi> g(n + 1);
        l(i, 0, m){
                int u, v; cin >> u >> v;

                if(u == 1 or v == 1) one_adj.push_back(make_pair(u, v));

                else{
                        // g[u].pb(v);
                        // g[v].pb(u);
                        edges.push_back(make_pair(u, v));
                        unite += dsu.Union(u, v);
                }
        }

        int connected_components = n - 1 - unite;

        if(sz(one_adj) < D or connected_components > D){
                cout << "NO" << endl; return 0;
        }

        unite = 0;
        vector<pii> ans;
        vector<int> vis(sz(one_adj));
        DisjointSet DSU(n);

        int it = 0;

        for(auto p : one_adj){
                if(dsu.Union(p.ff, p.ss)){
                        unite++;

                        DSU.Union(p.ff, p.ss);
                        ans.push_back(p);

                        vis[it] = 1;

                        // g[p.ff].push_back(p.ss);
                        // g[p.ss].push_back(p.ff);
                }
                it++;
        }

        int need = D - unite;
        it = 0;
        for(auto p : one_adj){
                if(vis[it]){it++; continue;}
                if(not need) break;
                need--;

                DSU.Union(p.ff, p.ss);

                ans.push_back(p);

                it++;
                
        }
        for(auto p : edges){
                if(DSU.Union(p.ff, p.ss)) 
                        ans.push_back(p);
        }
        cout << "YES" << endl; 

        for(auto p : ans)
                cout << p.ff << ' ' << p.ss << endl;



        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/