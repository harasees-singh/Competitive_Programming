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
int n;
vi in;
// 1 based;
vi vis;

int dfs(int i){

    if(i > n) return 0;

    if(vis[i] != -1) return vis[i];

    if(in[i] == 1) return vis[i] = dfs(i + 1);
    
    return vis[i] = 1 + dfs(i + in[i]);
}

void update(int i){
    if(i > n) return;

    int jump = in[i];

    in[i] = max(1ll, in[i] - 1);

    update(i + jump);
}

int32_t main(){
    FIO

    w(t){
        cin >> n;
        in = vi(n + 1);

        l(i, 1, n + 1) cin >> in[i];
        int cnt = 0;

        while(true){
            int mx = 0;

            int id = -1;
            vis = vi(n + 1, -1);

            l(i, 1, n + 1){
                int ret;

                ret = dfs(i);

                if(ret > mx)
                        
                        mx = ret, id = i;
            }
            if(mx == 0){
                break;
            }
            // cout << id << endl;
            cnt++;

            update(id);

            // l(i, 1, n + 1){
            //     cout << in[i] << space; 
            // }
            // cout << endl;
            
        }
        cout << cnt << endl;
    }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/