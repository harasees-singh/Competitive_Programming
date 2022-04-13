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
vi in; 
vi N;
vi sub; 
vector<vi> g;
int check(int tot, int diff){
    // cout << tot << ' ' << diff << endl;
    if((tot - diff) % 2 or tot < diff or abs(diff) > tot) return -1;

    return (tot - diff) / 2;
}
bool dfs(int i, int parent){
    int sad = check(sub[i], in[i]);

    if(sad == -1) return false;
    int total_sad = 0;
    bool ok = 1;
    for(auto p : g[i]){
        if(p == parent) continue;

        total_sad += check(sub[p], in[p]);

        ok = ok and dfs(p, i);
    }
    int peeps = N[i];

    // assume all peeps to be sad for optimal answer
    int rem_sad = max(0ll, sad - peeps);
    if((sz(g[i]) > 1 or i == 1) and total_sad < rem_sad){
        // cout << i << ' ' << total_sad << ' ' << sad << endl; 
        
        return false;
    }

    return ok;
}
void fill(int i, int parent){

    for(auto p : g[i]) if(p != parent) fill(p, i), sub[i] += sub[p];

    sub[i] += N[i];
}
int32_t main(){
        
        FIO

        w(T){
            int n, m; cin >> n >> m;

            in = vi(n + 1); N = vi(n + 1);

            for(int i = 1; i <= n; i++) cin >> N[i];
            for(int i = 1; i <= n; i++) cin >> in[i];

            sub = vi(n + 1);

            g = vector<vi> (n + 1);

            for(int i = 0;i < n - 1; i++){
                int u, v; cin >>u >> v; 

                g[u].pb(v); g[v].pb(u);
            }
            fill(1, 0);

            cout << (dfs(1, 0) ? "YES" : "NO") << endl;
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