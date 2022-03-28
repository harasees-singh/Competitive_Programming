// do it for the fam
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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

vector<vi> g;
int n, m, s, t; 
vi d, ways, vis, D; 
vi from_desti;
void bfs(){
    queue<int> Q;

    vis = vi(n + 1);

    vis[t] = 1;

    Q.push(t);

    while(Q.empty() == false){
        int top = Q.front();
        Q.pop();    
        for(auto p : g[top]){
            if(not vis[p]){
                from_desti[p] = from_desti[top] + 1;

                vis[p] = 1;

                Q.push(p);
            }
        }
    }
}
void bfs_shortest_path(){
    queue<int> Q;

    vis = vi(n + 1);

    vis[s] = 1;

    Q.push(s);

    while(Q.empty() == false){
        int top = Q.front();
        Q.pop();    
        for(auto p : g[top]){
            if(not vis[p]){
                d[p] = d[top] + 1;

                vis[p] = 1;

                Q.push(p);
            }
        }
    }    
}
void bfs_ways(){

    queue<int> Q; 
    
    Q.push(s); 

    while(Q.empty() == false){
        int top = Q.front();

        Q.pop();

        for(auto p : g[top]){
            int distance = D[top] + 1;

            // cout << p << ' ' << top << ' ' << distance << endl;

            if(distance + from_desti[p] > d[t] + 1) continue;

            D[p] = D[top] + 1;

            Q.push(p);

            ways[p] += ways[top];

            ways[p] %= MOD;
        }
    }
}
int32_t main(){
        
        FIO

        int T; cin >> T;
        while(T--){

            cin >> n >> m;

            from_desti = vi(n + 1);

            d = vi(n + 1); 
            D = vi(n + 1); 
            
            ways = vi(n + 1);

            g = vector<vi> (n + 1);

            cin >> s >> t;
            ways[s] = 1;
            for(int i = 0; i < m; i++){
                int u, v; cin >> u >> v;

                g[u].pb(v);
                
                g[v].pb(u);

                // cout << "ok" << endl; cout.flush();
            }

            bfs();

            bfs_shortest_path();

            bfs_ways();

            cout << ways[t] << endl;
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