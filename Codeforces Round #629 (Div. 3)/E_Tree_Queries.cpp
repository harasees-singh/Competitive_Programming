#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
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
#define fps(x,y)                        fixed<<setprecision(y)<<x
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int P[200000 + 1];
int tin[200000 + 1];
int tout[200000 + 1];

int d[200000 + 1];

int t = 0;

vector<vi> g;

void dfs(int i){
    ++t;
    tin[i] = t;
    for(auto c : g[i]){
        if(c != P[i]){
            d[c] = d[i] + 1;
            P[c] = i;
            dfs(c);
        }
    }
    tout[i] = t;
}

bool cmp(int n1, int n2){
    return d[n1] < d[n2];
}

bool isAncestor(int u, int v){
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int32_t main(){
    FIO

    P[1] = 1;

    int n, m; cin >> n >> m;

    g = vector<vi>(n + 1);

    l(i, 0, n - 1){
        int u, v; cin >> u >> v;

        g[u].pb(v), g[v].pb(u);
    }
    dfs(1);
    l(i, 0, m){
        int k; cin >> k;
        vi I(k);
        l(i, 0, k){
            int t; cin >> t;
            I[i] = P[t];
        }
        sort(all(I), cmp);
        
        bool ok = 1;
        l(i, 1, k){
            if(!isAncestor(I[i - 1], I[i])){
                ok = 0; break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/