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
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

vector<vi> adj(500000 + 1);

int color = 1;

int f[500000 + 1];

void dfs(int curr){

    for(int i = 0; i < sz(adj[curr]); i++)

        if(f[adj[curr][i]] == 0){

            f[adj[curr][i]] = color;

            dfs(adj[curr][i]);
        }

    return;
}

int32_t main(){
    FIO

    int n, m; cin >> n >> m;
    // size = 5*1e5 + 1
    l(i, 0, m){

        int k; cin >> k;

        vi I(k);

        l(j, 0, k){

            cin >> I[j];
        }

        l(it, 0, k - 1){

            int c = I[it], p = I[it + 1];

            adj[c].pb(p), adj[p].pb(c);
        }
    }
    for(int i = 0; i < n; i++){

        if(f[i + 1] == 0){

            ++color;

            f[i + 1] = color;

            dfs(i + 1);
        }   
    }
    unordered_map<int, int> freq;

    for(auto &p : f)

        freq[p]++;

    l(i, 1, n + 1)

        cout << freq[f[i]] << space; cout << endl;
}
