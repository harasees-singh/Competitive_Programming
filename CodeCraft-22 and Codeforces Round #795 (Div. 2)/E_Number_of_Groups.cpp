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

        vi Rank, parent, treesize;

        DisjointSet(int n){
                N = n;
                Rank = vi(n + 1);
                parent = vi(n + 1);
                
                MakeSet();
        }
        

        void MakeSet(){
                for(int i = 0; i <= N; i++)
                        parent[i] = i, Rank[i] = 0;
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
void solve(){
    int n; cin >> n; 
    DisjointSet dsu(n);
    vector<vi> in;

    for(int i=  0; i < n; i++){
        int c, l, r; cin >> c >> l >> r; 

        in.push_back({l, r, c});
    }
    sort(all(in));
    // red is 0, blue is 1

    set<pii> RED, BLUE; // red contains red segments in the format {r, group id}
    
    // algorithm : iterate over segments in the sorted order, 
    // suppose u get a red segment, go to BLUE and delete all the BLUE segs which end before l
    // those left must intersect with our red segment and can be united into one seg with ending as the max of all the endings of the united blue segs
    // put this red seg in RED. 

    // repeat for all segs in the in vector

    for(int i = 0; i < n; i++){
        auto cur = in[i];
        bool blue = cur[2];

        if(!blue){
            // red segment 
            int l = cur[0];
            int mx=0;
            for(auto p: BLUE){

                if(p.ff >= l){
                    amax(mx, p.ff);
                    dsu.Union(p.ss, i);
                }
            }
            BLUE.clear();
            if(mx){
                // if mx==0 no unions took place, in short no segments intersected with this red one so remove them all 
                // as they won't intersect with any further red segs as well
                BLUE.insert({mx, dsu.findParent(i)});
            }
            RED.insert({cur[1], dsu.findParent(i)}); // {r, id}
        }
        else{
            // blue segment
            int l = cur[0];
            int mx=0;
            for(auto p : RED){
                if(p.ff >= l){
                    amax(mx, p.ff);
                    dsu.Union(p.ss, i);
                }
            }
            RED.clear();
            if(mx){
                RED.insert({mx, dsu.findParent(i)});
            }
            BLUE.insert({cur[1], dsu.findParent(i)}); // {r, id}
        }
    }
    vi vis(n);
    for(int i=0; i < n;i++) 
        vis[dsu.findParent(i)]=1;
    cout << accumulate(all(vis), 0ll) << endl;

}
int32_t main(){
        
        FIO
        w(T){
            solve();
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