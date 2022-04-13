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
// #define int                             long long
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
        ~DisjointSet(){
                delete []parent;
                delete []Rank;
                delete []treesize;
        }
};


int32_t main(){
        
        FIO

        int n; cin >> n;

        set<pii> have; // {start, id};

        vector<int> end(2 * n + 1, -1), beg(n), END(n); // end -> id;

        vector<pii> in(n); 

        vi iterate;


        for(int i = 1; i <= n; i++){
            pii t; cin >> t;
            iterate.push_back(t.ff);
            iterate.push_back(t.ss);
            beg[i - 1] = t.ff;
            end[t.ss] = i - 1;
            END[i - 1] = t.ss;
            in[i - 1] = {t.ff, i - 1}; 
        }
        sort(all(iterate));
        
        int cnt = 0;

        vector<pii> g;

        sort(all(in));

        int pt = 0;

        for(int i = 1; i <= 2 * n and cnt < n; i++){
            // seg starting at i
            
            if(end[i] != -1){
                // cout << i << ' '<< 2 * n << ' ';
                int id = end[i];
                
                assert(have.count({i, id}));

                have.erase({i, id});
            }
            else if(in[pt].ff == i){
                for(auto p : have){

                    if(p.ff > END[in[pt].ss] or cnt > n - 1) break;

                    g.push_back(make_pair(in[pt].ss, p.ss));

                    cnt++;
                }
                
                have.insert({END[in[pt].ss], in[pt].ss});

                pt++;
            }
        }
        beg.clear(); end.clear(); END.clear(); in.clear();
        DisjointSet dsu(n);

        // for(auto p : g) cout << p << endl; cout.flush();

        for(auto &p : g){
            if(dsu.findParent(p.ff) == dsu.findParent(p.ss)){
                cout << "NO"; return 0;
            }
            dsu.Union(p.ff, p.ss);
        }    
        cout << (sz(g) == n - 1 ? "YES" : "NO");

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/