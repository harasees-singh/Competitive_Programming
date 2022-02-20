// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
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

MOD_DEFINE

int32_t main(){
        FIO 

        int n; cin >> n;

        vi in(n); for(auto &p : in) cin >> p;

        vi f(2e5 + 1);

        for(auto p : in) f[p]++;

        int mx = 0;

        for(auto p : in) if(f[p] > f[mx]) mx = p;

        // mx is the most freq element

        int id = find(all(in), mx) - in.begin();

        vector<vi> ans;

        // cout << id << endl;

        // 1 is addition, 2 is sub

        for(int i = id + 1; i < n; i++){
                // id - 1 will always have desired val

                int need = in[i] - in[i - 1];

                if(need == 0) continue;
                if(need > 0){
                        ans.push_back({2, i + 1, i});
                }
                else{
                        ans.push_back({1, i + 1, i});
                }
                in[i] = in[i - 1];
        }
        for(int i = id - 1; i >= 0; i--){
                int need = in[i] - in[i + 1];

                if(need == 0) continue;
                if(need > 0){
                        ans.push_back({2, i + 1, i + 2});
                }
                else{
                        ans.push_back({1, i + 1, i + 2});
                }
                in[i] = in[i + 1];
        }
        cout << sz(ans) << endl;

        for(auto &p : ans){
                for(auto q : p) cout << q << ' '; cout << endl;
        }

        return 0;
}

