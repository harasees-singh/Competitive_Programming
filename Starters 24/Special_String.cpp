// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        INT32_MAX
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
// #define int                             long long
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
string s;
vector<vector<pii>> u;
int M;
int query(int id, int m){
        int cpy = id;
        if(m == 1) return 0;
        m--;
        int cost = 0;
        while(m){
                // loop invariant : jump won't make me cross m

                int jump = 0;

                while((1ll << (jump + 1)) <= m) jump++;

                pii go = u[id][jump];

                if(go.ff == -1) return infinity;

                id = go.ff;

                cost += go.ss;

                m -= (1ll << jump);
        }

        return cost;
}

int32_t main(){
        
        FIO

        // with binary lifting source: https://cp-algorithms.com/graph/lca_binary_lifting.html
        w(t){
                int n; cin >> n;

                cin >> s;

                cin >> M; 

                u = vector<vector<pii>> (n, vector<pii>(21, {-1, -1})); // {id, cost}

                vector<vi> nxt(n + 1, vi(26, -1)); 

                for(int i = n - 1; i >= 0; i--){
                        for(int j = 0; j < 26; j++)
                                nxt[i][j] = nxt[i + 1][j];
                        nxt[i][s[i] - 'a'] = i;
                }

                for(int i = n - 1; i >= 0; i--){
                        int go = nxt[i][((s[i] - 'a') + 1) % 26];

                        if(go == -1) continue;

                        u[i][0] = make_pair(go, go - i - 1);

                        for(int j = 1; j < 22; j++){

                                pii t = u[u[i][j - 1].ff][j - 1];

                                if(t.ff == -1) break;

                                u[i][j] = make_pair(t.ff, u[i][j - 1].ss + t.ss);
                        }
                }
                // for(auto p : u){
                //         for(auto q : p)
                //                 cout << q.ff << ' ' << q.ss << endl; cout << endl;
                // }
                // should be working
                int mn = infinity;

                for(int i = 0; i < n; i++){
                        if(s[i] == 'a') 
                                mn = min(mn, query(i, M));
                }
                cout << (mn == infinity ? -1 : mn) << endl;
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