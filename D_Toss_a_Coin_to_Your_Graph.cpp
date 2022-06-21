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
vector<vi> g;
vi in;
bool ok=0;
vi vis;
vi dp; 
void dfs(int i, int mx, int depth){
    if(in[i] > mx) return;
    if(vis[i]==2){
        if(dp[i] > depth){
            ok=1; 
        }
        return;
    }

    if(depth==0 or vis[i]==1){

        ok=1; return;
    }
    vis[i]=1;

    for(auto p : g[i]){
        
        dfs(p, mx, depth - 1);
        amax(dp[i], dp[p]);
    }
    dp[i]++;
    vis[i]=2;
}
void solve(){
    int n, m, k; cin >> n >> m >> k;

    g = vector<vi> (n + 1);

    in=vi(n + 1); for(int i=1; i <= n; i++) cin >> in[i];

    for(int i=1; i <= m; i++){
        int u, v; cin >> u >> v;

        g[u].pb(v);
    }
    int l=0, r=1e9;

    while(l <= r){
        int mid = (l + r)/2;

        vis = vi(n + 1);

        dp = vi(n + 1);

        ok = 0;

        for(int i=1; i<=n; i++)
            if(not ok)
                dfs(i, mid, k-1);

        if(ok) r = mid - 1;
        else l = mid + 1;
    }
    cout << (l > 1e9 ? -1 : l) << endl;
}

int32_t main(){
        
        FIO
        solve();
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/