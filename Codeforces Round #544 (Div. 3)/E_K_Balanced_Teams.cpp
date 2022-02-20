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
int n;
vector<vi> dp;
vi mx_seg;       // max possible seg len from id i

vi in;

void compute_mx_seg(){
        int i = 0, j = 0;

        in.push_back(infinity);

        for(; j < n + 1; j++){

                while(in[j] - in[i] > 5){
                        if(not mx_seg[i])
                                mx_seg[i] = mx_seg[i - 1] - 1; 
                        i++;
                }
                mx_seg[i] = j - i + 1;
        }
        in.pop_back();
}

int32_t main(){
        
        FIO

        int k;

        cin >> n >> k;

        mx_seg = vi(n + 1);

        dp = vector<vi> (n + 1, vi(k + 1));

        in = vi(n); 

        for(auto &p : in) cin >> p;

        sort(all(in));

        compute_mx_seg();

        // for(auto p :  mx_seg) cout << p << ' '; cout << endl;

        for(int i = n - 1; i >= 0; i--){
                for(int j = 1; j <= k; j++){
                        dp[i][j] = max(dp[i + 1][j], mx_seg[i] + dp[mx_seg[i] + i][j - 1]);
                }
        }
        // for(auto p : dp){
        //         vi cpy(p);

        //         // for(auto q : p) cout << q << ' '; cout << endl;

        //         sort(all(cpy));

        //         assert(cpy == p);
        // }
        cout << dp[0][k] << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/