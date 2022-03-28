// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

map<pii, pair<int, pii>> dp;
map<pii, bool> vis;

vector<set<int>> gx, gy;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int dfs(int x, int y){
    // assert(x >= 0 and y >= 0);
    if(gx[x].count(y) == 0) {
        dp[{x, y}] = {0, {x, y}};

        return 0;
    }

    if(dp.count({x, y})) return dp[{x, y}].ff;

    if(vis[{x, y}]) return infinity;
    vis[{x, y}] = 1;

    int mn = infinity;

    vi ret(4);
    int id;
    for(int i = 0; i < 4; i++){
        ret[i] = 1 + dfs(x + dx[i], y + dy[i]);

        if(ret[i] < mn){
            mn = ret[i]; id = i;
        }
    }

    dp[{x, y}] = {ret[id], dp[{x + dx[id], y + dy[id]}].ss};
    
    return ret[id];
}

int32_t main(){
        FIO 

        int n; cin >> n;
        vector<pii> in(n);
        gx = vector<set<int>> (2e5 + 2);
        gy = vector<set<int>> (2e5 + 2);

        for(int i = 0;i < n;i++){
            cin >> in[i];
            int x, y; tie(x, y) = in[i];

            gx[x].insert(y); 

            gy[y].insert(x);
        }

        for(auto p : in){
            dfs(p.ff, p.ss);

            cout << dp[p].ss << endl;
        }

        return 0;
}

