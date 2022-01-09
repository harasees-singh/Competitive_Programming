// ਹਰਅਸੀਸ ਸਿੰਘ

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

vi vis;

int32_t main(){
        
        FIO

        w(t){
                int n; cin >> n;

                vi P(n + 1);

                l(i, 1, n + 1) cin >> P[i];

                vis = vi(n + 1, 0);

                vi perm(n + 1);

                l(i, 1, n + 1) cin >> perm[i];

                bool ok = 1;

                l(i, 1, n + 1){
                        int cur = perm[i];

                        if(P[cur] == cur or vis[P[cur]]){
                                vis[cur] = 1;
                        }
                        else 
                                ok = 0;
                }
                if(!ok){
                        cout << -1 << endl; continue;
                }
                int pf = 0;
                vi ans(n + 1);
                vi W(n + 1);
                l(i, 1, n + 1){

                        // cout << pf << ' ';
                        ans[perm[i]] = pf - W[P[perm[i]]];
                        W[perm[i]] = pf;
                        pf++;
                }
                l(i, 1, n + 1) cout << ans[i] << ' ';
                cout << endl;
        }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/