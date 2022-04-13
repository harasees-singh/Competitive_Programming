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
vector<vi> g; // tree
vi MX;
vi in;
int cnt = 0;

int dfs(int i){
    int mn = infinity;
    if(g[i].size() == 0) return in[i];

    for(auto p : g[i]){
        int ret = dfs(p);

        cnt += ret;

        amin(mn, ret);
    }

    cnt -= mn;

    return max(in[i], mn);
}

int32_t main(){
        FIO 

        int t; cin >> t;
        for(int T = 1; T <= t; T++){
            cout << "Case #" << T << ": ";

            int n; cin >> n;

            g = vector<vi> (n + 1);

            vi roots; 

            cnt = 0; in = vi(n + 1); MX = vi(n + 1);

            for(int i = 1; i <= n; i++) cin >> in[i];

            for(int u = 1; u <= n; u++){
                int v; cin >> v;

                // edge from v to u;

                if(not v){
                    roots.push_back(u);
                }
                else g[v].pb(u);
            }

            for(auto p : roots) cnt += dfs(p);

            cout << cnt << endl;
        }

        return 0;

}
