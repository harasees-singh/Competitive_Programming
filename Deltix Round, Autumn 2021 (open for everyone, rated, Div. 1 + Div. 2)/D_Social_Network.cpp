// ਹਰਅਸੀਸ ਸਿੰਘ

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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

struct DisjointSet{
        int N = 5e5;

        DisjointSet(){
			MakeSet();
		}

        DisjointSet(int n){
                N = n;
                MakeSet();
        }
        int *Rank = new int[N + 1];

        int *parent = new int[N + 1];

        void MakeSet(){
                for(int i = 1; i <= N; i++)
                        parent[i] = i;
        }

        int findParent(int v){

                if(parent[v] == v)
                        return v;
                
                return parent[v] = findParent(parent[v]);
        }

        void Union(int u, int v){

                u = findParent(u), v = findParent(v);

                if(Rank[u] > Rank[v])
                        parent[v] = u;
                else if(Rank[u] < Rank[v])
                        parent[u] = v;
                else        
                        parent[v] = u, Rank[u]++;
        }
};

int32_t main(){
        
        FIO

        int n, k; cin >> n >> k;

        DisjointSet ds;

        set<pii> available;

        for(int i = 1; i <= n; i++)
                available.insert({0, i});

        map<int, int> f;
        int free_edges = 0;
        int mx = 0;

        for(int i = 0; i < k; i++){
                int u, v; 

                cin >> u >> v;

                
                if(ds.findParent(u) == ds.findParent(v)){
                        assert(sz(available) >= 2);
                        free_edges++;
                }
                else{        
                        int pu = ds.findParent(u), pv = ds.findParent(v);

                        ds.Union(u, v);
                        available.erase({f[pu], pu});
                        available.erase({f[pv], pv});

                        if(ds.findParent(u) == pu){
                                f[pu] += f[pv] + 1;

                                available.insert({f[pu], pu});
                        }
                        else {
                                f[pv] += f[pu] + 1;

                                available.insert({f[pv], pv});
                        }
                }
                int curmx = 0;
                auto it = available.end();

                for(int i = 0; i <= free_edges; i++){
                        it--;
                        curmx += (*it).ff + 1;
                }
                cout << curmx - 1 << endl;
        }
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/