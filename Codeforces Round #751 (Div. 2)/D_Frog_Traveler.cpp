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
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    int n; cin >> n;

    vi j, d; 

    l(i, 0, n){
            int t; cin >> t; j.pb(t);
    }
    l(i, 0, n){
            int t; cin >> t; d.pb(t);
    }
    queue<int> Q;

    vi child(n + 1);

    child[0] = -1;

    Q.push(n);

    vi depth(n + 1, -1);

    depth[n] = 0;

    while(Q.empty() == false){

            int f = Q.front();
            
            Q.pop();

            int jump = j[f - 1 + d[f - 1]];

            if(f - jump + d[f - 1] <=  0){
                    child[0] = f; break;
            }

            l(i, 1, jump + 1){
                    int dnew = f - i + d[f - 1];

                    if(depth[dnew] == -1)

                            depth[dnew] = depth[f] + 1, child[dnew] = f, Q.push(dnew);
            }
            int godown = f + d[f - 1];

            if(godown <= n and depth[godown] == -1)
                    depth[godown] = depth[f] + 1, child[godown] = f, Q.push(godown); 
    }

    vi ans;

    int curr = 0;

    if(child[0] == -1)
            {cout << -1 << endl; return 0;}

    while(curr != n)
            ans.pb(curr), curr = child[curr];
    cout << sz(ans) << endl;

    for(int i = sz(ans) - 1; i >= 0; i--)
            cout << ans[i] << space; cout << endl;
}
