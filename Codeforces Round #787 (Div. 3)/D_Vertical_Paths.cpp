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
vector<vi> paths; 
vector<vi> g;
void dfs(int i, vi &path){
        path.push_back(i);
        if(sz(g[i])==0){
                paths.push_back(path); path.pop_back(); return;
        }
        int child = g[i][0];

        dfs(child, path);

        vi t;

        for(int j = 1; j < sz(g[i]); j++)
                dfs(g[i][j], t);
        path.pop_back();
}
int32_t main(){
        
        FIO

        w(T){
                paths.clear();
                int n; cin >> n; 
                g = vector<vi> (n + 1);
                int root = -1;
                for(int i = 0; i < n; i++){
                        int t; cin >> t; 
                        if(i + 1==t){
                                root=i + 1; continue;
                        }
                        g[t].pb(i + 1);
                }
                // for(auto p : g){ for(auto q : p) cout << q << ' '; cout << endl;}
                assert(root!=-1);
                // cout << "YES" << endl; cout.flush();
                vi t;
                dfs(root, t);
                cout << sz(paths) << endl;
                for(auto &p : paths){
                        cout << sz(p) << endl; for(auto q : p) cout << q << ' '; cout << endl;
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