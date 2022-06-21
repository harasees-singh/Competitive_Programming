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
#define w(T)                            int T; cin >> T; while(T--)
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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE
struct DisjointSet{
        int N;

        vector<int> Rank, parent, treesize;

        DisjointSet(int n){
                N = n;
                Rank = vector<int>(n + 1);
                parent = vector<int>(n + 1);
                treesize = vector<int>(n + 1);
                
                MakeSet();
        }
        

        void MakeSet(){
                for(int i = 0; i <= N; i++)
                        parent[i] = i, Rank[i] = 0, treesize[i] = 1;
        }

        int findParent(int v){

                if(parent[v] == v)
                        return v;
                
                return parent[v] = findParent(parent[v]);
        }

        void Union(int u, int v){

                u = findParent(u), v = findParent(v);

                if(Rank[u] > Rank[v])
                        parent[v] = u, treesize[u] += treesize[v];
                else if(Rank[u] < Rank[v])
                        parent[u] = v, treesize[v] += treesize[u];
                else        
                        parent[v] = u, Rank[u]++, treesize[u] += treesize[v];
        }
        int nodecnt(int i){
                i = findParent(i);

                return treesize[i]; // node cnt including the parent itself
        }
};
vector<vpii> U; // u[i][j] {max edge, node no.} on a path from i to it's ancestor at a distance 1 << j;
vector<vi> edges;

vector<vi> MST;

int kruskal(int n, vector<vi> edges){
    int ret=0;

    sort(all(edges));

    DisjointSet dsu(n);

    for(auto p : edges){
        if(dsu.findParent(p[1]) != dsu.findParent(p[2])){
            dsu.Union(p[1], p[2]);
            ret += p[0];
            MST.push_back(p);
        }
    }
    return ret;
} 
vector<vpii> g;
vi tin, tout;
int t=0;
int height=0;
void dfs(int i, int p, int w){
    tin[i] = t++;

    U[i][0] = {w, p};   
    for(int j=1; j<=height; j++){
        int parent = U[U[i][j-1].ss][j-1].ss;
        int W = max(U[U[i][j-1].ss][j-1].ff, U[i][j-1].ff);

        U[i][j] = {W, parent};
    }
    for(auto q : g[i]){
        if(q.ff != p){
            dfs(q.ff, i, q.ss);
        }
    }

    tout[i] = t++;
}
bool isParent(int u, int v){
    if(!u) return true;
    return (tin[u] <= tin[v] and tout[u] >= tout[v]);
}
int32_t main(){
        
        FIO

        int n, m; cin >> n >> m; 

        tin = vi(n + 1), tout = vi(n + 1);

        for(int i=0; i<m; i++){
            int u, v, w; cin >> u >> v >> w; 

            edges.push_back({w, u, v});
        }
        int W = kruskal(n, edges);
        // MST filled;
        while((1<<height) < n) height++;

        U = vector<vpii> (n + 1, vpii(height + 1));

        g = vector<vpii> (n + 1);
        for(auto p : MST){
            g[p[1]].push_back({p[2], p[0]});
            g[p[2]].push_back({p[1], p[0]});
        }
        
        dfs(1, 0, 0);

        // for(int i=0; i <= n; i++){
        //     cout << i << " :" << endl;

        //     for(int j=0; j < sz(U[i]); j++){
        //         cout << U[i][j] << endl;
        //     }
        //     cout << endl;
        // }
        // binary lifiting working
        for(auto p : edges){
            // add this edge to mst;

            int w = p[0];

            int mx=0;
            int u = p[1], v = p[2];
            // cout << u << ' ' << v << endl;
            int t=u;
            for(int i=height; i>=0; i--){
                if(!isParent(U[t][i].ss, v)) {
                    // cout << "nxt : " << t << endl;    

                    amax(mx, U[t][i].ff), t = U[t][i].ss;

                }
            }
            // cout << endl;
            if(!isParent(t, v)){
                amax(mx, U[t][0].ff);
            }
            t=v;

            for(int i=height; i>=0; i--){
                if(!isParent(U[t][i].ss, u)){ 
                    // cout << "nxt : " << t << endl;
                    amax(mx, U[t][i].ff), t = U[t][i].ss;
                
                }
            }
            if(!isParent(t, u)){
                amax(mx, U[t][0].ff);
            }
            // cout << mx << ' ' << w << endl;
            cout << W - mx + w << endl;
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