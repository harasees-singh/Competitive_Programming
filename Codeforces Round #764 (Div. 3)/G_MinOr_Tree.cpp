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
int bit[35] = {1};
int n;
vector<tuple<int, int, int>> edges;

bool merge(int id, DisjointSet &D){
        int done = 0;
        vector<tuple<int, int, int>> temp;
        for(auto &p : edges){
                int u, v, w; tie(u, v, w) = p;

                if(((1ll << id) & w) == 0){
                        temp.push_back(p);

                        if(D.findParent(u) != D.findParent(v)){
                                D.Union(u, v); done++;
                        }
                }
        }
        if(done == n - 1){
                edges = temp; return true;
        }
        return false;
}

int32_t main(){
        
        FIO

        w(t){
                l(i, 0, 35) bit[i] = 1;

                int m; cin >> n >> m;

                edges = vector<tuple<int, int, int>>();

                l(i, 0, m){
                        int u, v, w; cin >> u >> v >> w;

                        edges.push_back(make_tuple(u, v, w));
                }
                for(int id = 34; id >= 0; id--){
                        DisjointSet D(n);
                        bit[id] = !(merge(id, D)); 
                }
                int calc = 0; int mul = 1; l(i, 0, 35) calc += mul * bit[i], mul *= 2;
                cout << calc << endl;
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