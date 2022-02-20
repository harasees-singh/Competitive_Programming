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

        w(t){
                int n; cin >> n;

                vi in(n);

                for(auto &p : in) cin >> p;

                vector<pii> ans;

                vector<pair<bool, bool>> perm(n + 1);
                int mx = 0;
                set<int> store;

                for(int i = n - 1; i >= 0; i--){
                        store.insert(in[i]); 

                        mx = max(mx, in[i]);

                        if(mx == sz(store) and mx == n - i){
                                perm[i].ss = 1;
                        }
                }
                mx = 0;
                store.clear();
                for(int i = 0; i < n; i++){
                        store.insert(in[i]);

                        mx = max(mx, in[i]);

                        if(mx == sz(store) and mx == i + 1){
                                perm[i].ff = 1;
                        }
                }
                for(int i = 0; i < n; i++){
                        int left = perm[i].ff;

                        int right = perm[i + 1].ss;

                        if(left and right){
                                ans.push_back(make_pair(i + 1, n - i - 1));
                        }
                }

                cout << sz(ans) << endl;

                for(auto p : ans){
                        cout << p.ff << ' ' << p.ss << endl;
                }
        }

        return 0;
}

