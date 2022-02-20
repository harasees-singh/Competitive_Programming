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
#define W(t)                            int t; cin >> t; while(t--)
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
        int N = 1e5;

        int * Rank;
        int * parent;
        int * treesize;

        DisjointSet(){
		MakeSet();
	}

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
        ~DisjointSet(){
                delete []parent;
                delete []Rank;
                delete []treesize;
        }
};


int nC2(int n){
        if(2 > n) return 0;

        return (n * (n - 1))/2;
}

int increment(int u, int v, DisjointSet &D){
        return nC2(D.nodecnt(u) + D.nodecnt(v)) - nC2(D.nodecnt(u)) - nC2(D.nodecnt(v)); 
}

int32_t main(){
        
        FIO

        int n, q; cin >> n >> q;

        DisjointSet D(2e5);

        vector<vi> edges;

        l(i, 0, n - 1){
                int u, v, w; cin >> u >> v >> w;

                edges.push_back({w, u, v});
        }
        sort(all(edges));

        vi ans(2e5 + 1);
        int it = 0;
        l(w, 1, 2e5 + 1){
                // will calculate ans[w];
                ans[w] = ans[w - 1];

                while(it < n - 1 and edges[it][0] <= w){
                        int u, v;

                        u = edges[it][1], v = edges[it][2];

                        ans[w] += increment(u, v, D);

                        D.Union(u, v);

                        it++;

                }
        }
        l(i, 0, q){
                int t; cin >> t;

                cout << ans[t] << ' ';
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