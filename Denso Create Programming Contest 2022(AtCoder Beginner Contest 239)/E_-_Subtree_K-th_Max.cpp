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

MOD_DEFINE
vector<multiset<int>> store;

vector<vi> g;

int n;

vi X;

multiset<int> dfs(int i, int parent){
        multiset<int> ret;

        for(auto p : g[i]){
                if(p != parent){
                        auto have = dfs(p, i);

                        for(auto p : have){
                                ret.insert(p);

                                if(sz(ret) > 20) ret.erase(ret.begin());
                        }
                }
        }
        ret.insert(X[i]);
        store[i] = ret;


        if(sz(ret) > 20) ret.erase(ret.begin());

        return ret;
}
int32_t main(){
        
        FIO

        cin >> n;
        int q; cin >> q;

        g = vector<vi> (n + 1);

        store = vector<multiset<int>> (n + 1);

        X = vi(n + 1);
        for(int i = 1; i <= n; i++) cin >> X[i];

        for(int i = 0; i < n - 1; i++){
                int u, v; cin >> u >> v;

                g[u].pb(v);
                g[v].pb(u);
        }
        dfs(1, 0);
        l(i, 0, q){
                int v, k; cin >> v >> k;

                auto it = prev(store[v].end());

                for(int i = 0; i < k - 1 and it != store[v].begin(); i++, it--){}

                cout << *it << endl;
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