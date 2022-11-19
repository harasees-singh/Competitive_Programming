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
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE
vector<vector<pair<int, int>>> g;
void slv(){
        int n, m; cin >> n >> m;

        g = vector<vector<pair<int, int>>> (2 * n + 1);

        for(int i = 0; i < m; i++){
            int u, v, w; cin >> u >> v >> w;

            g[u].push_back(make_pair(v, w));

            g[v + n].push_back(make_pair(u + n, w));

            g[u].push_back(make_pair(u + n, 0));
            g[v].push_back(make_pair(v + n, 0));
        }
        set<pair<int, int>> D; // {w, u};

        D.insert(make_pair(0, 1));

        vector<int> d(2 * n + 1, infinity);

        d[1] = 0;

        vector<bool> vis(2 * n + 1);

        for(; D.empty() == false; ){
            auto top = *D.begin();

            D.erase(D.begin());

            int w = top.first; 

            int v = top.second;

            if(vis[v]) continue;

            vis[v] = 1;

            d[v] = w;

            for(auto p : g[v]){
                if(d[p.first] > p.second + d[v]){
                    // relax
                    d[p.first] = p.second + d[v];

                    D.insert(make_pair(d[p.first], p.first));
                }
            }
            cout << endl;
        }
        for(int i = 2; i <= n; i++){
            cout << (d[i + n] == infinity ? -1 : d[i + n]) << " \n"[i == n];
        }
}

int32_t main(){
        
        FIO

                slv();
        
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/