#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

int32_t main(){
    FIO 

    int n, k; cin >> n >> k;

    mii vis;

    int cnt = 0;

    int done = 0;

    queue<pii> q;

    vi ans;

    l(i, 0, n){
        int t; cin >> t;
        q.push(make_pair(t, 0));
        vis[t]=1;
    }
    while(done < k){
        pii t = q.front();

        q.pop();

        if(!vis[t.ff + t.ss + 1] and done < k) {
            done++;
            q.push(make_pair(t.ff, t.ss + 1));
            ans.pb(t.ff + t.ss + 1);
            vis[t.ff + t.ss + 1] = 1;
            cnt += (abs(t.ss) + 1);
        
        }
        if(!vis[t.ff + t.ss - 1] and done < k){
            done++;
            q.push(make_pair(t.ff, t.ss - 1));
            ans.pb(t.ff + t.ss - 1);
            vis[t.ff + t.ss - 1] = 1;
            cnt += (abs(t.ss) + 1);
        }
    }

    cout << cnt << endl;
    for(auto p : ans) cout << p << ' ';
    return 0;
}
