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
vi in;
int n;
vector<pii> seg;
vector<int> store;
vector<int> ans;
int get(int i, int j){  // 1 based
        // mn at i and mx at j
        int dec = 0;
        for(int it = 0; it < sz(seg); it++){
                auto p = seg[it];
                int l, r; tie(l, r) = p;

                if(j >= l and j <= r){
                        continue;
                }
                if(i >= l and i <= r){
                        dec++;

                        store.push_back(it + 1);
                }
        }  
        return dec;
}
int32_t main(){
        
        FIO

        int m; cin >> n >> m;

        in = vi(n);

        for(auto &p : in) cin >> p;

        int val = 0;
        seg = vector<pii> (m);

        for(auto &p : seg){
                cin >> p.ff >> p.ss;
        }

        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        store.clear();

                        int ret = get(i, j);

                        // cout << i << ' ' << j << " " << ret << endl; for(auto p : store) cout << p.ff << ' ' << p.ss << endl;

                        int diff = abs(in[i - 1] - ret - in[j - 1]);

                        if(diff > val){
                                val = diff; ans = store;
                        }
                        store.clear();

                        ret = get(j, i);

                        diff = abs(in[j - 1] - ret - in[i - 1]);

                        if(diff > val){
                                // cout << i << ' ' << j << endl;
                                val = diff; ans = store;
                        }
                }       
        }
        cout << val << endl;
        cout << ans.size() << endl;

        for(auto p : ans) cout << p << ' '; cout << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/