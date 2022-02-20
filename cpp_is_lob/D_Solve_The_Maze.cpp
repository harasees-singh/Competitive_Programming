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
vector<string> mat;
bool block(int i, int j){
        int n = sz(mat), m = sz(mat[0]);

        if(i > 0 and mat[i - 1][j] == 'G') return false;
        if(i > 0 and mat[i - 1][j] != 'B') mat[i - 1][j] = '#';

        if(i < n - 1 and mat[i + 1][j] == 'G') return false;
        if(i < n - 1 and mat[i + 1][j] != 'B') mat[i + 1][j] = '#';

        if(j > 0 and mat[i][j - 1] == 'G') return false;
        if(j > 0 and mat[i][j - 1] != 'B') mat[i][j - 1] = '#';

        if(j < m - 1 and mat[i][j + 1] == 'G') return false;
        if(j < m - 1 and mat[i][j + 1] != 'B') mat[i][j + 1] = '#';

        return true;
}
vector<vi> vis;
// issue with dp, not sure why it won't work, alternative: could imple a bfs from {n, m}
// 4 4
// #GG.
// ..#G
// #G#.
// .#G.
// found the issue, the 'G' at {3, 2} will be assigned dp value = 0 while dfsing for 'G' at {1, 2}; 
void dfs(int i, int j){
        int n = sz(mat), m = sz(mat[0]);
        if(i < 0 or j < 0 or i == sz(mat) or j == sz(mat[0])) return;

        if(mat[i][j] == '#') return;

        if(vis[i][j]) return;

        vis[i][j] = 1;

        dfs(i + 1, j), dfs(i - 1, j), dfs(i, j - 1), dfs(i, j + 1);

        return;
}
int32_t main(){
        
        FIO

        w(t){
                int n, m; cin >> n >> m;

                mat = vector<string>(n);

                for(auto &p : mat) cin >> p;
                vis = vector<vi> (n, vi(m));

                bool ok = 1;
                for(int i = 0;i < n; i++)
                        for(int j = 0; j < m; j++)
                                {
                                        
                                        if(mat[i][j] == 'B') ok = ok and block(i, j); 
                                        
                                        // if(mat[i][j] == '#') dp[i][j] = 0;
                                
                                }
                dfs(n - 1, m - 1);
                for(int i = 0;i < n; i++){
                        for(int j = 0; j < m; j++){
                                if(mat[i][j] == 'G') ok = ok and vis[i][j];
                        }
                // cout << "YES" << endl; cout.flush();
                }
                
                cout << (ok ? "Yes" : "No") << endl;
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