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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
        
        FIO

        w(t){
                int n; cin >> n;
                
                string s; cin >> s;

                vi ans;

                for(auto p : s){
                        if(p == '*')
                                ans.pb(0);
                }
                if(sz(ans) == 0){
                        cout << 0 << endl; continue;
                }

                // find the sz(ans)/2 th star
                int cnt = 0;
                int j = 0;
                l(i, 0, sz(ans)/2 + 1){
                        while(s[j] != '*')
                                j++;
                        j++;
                }
                // j-- will have the pos of the mid sheep

                int sheep = sz(ans)/2;
                l(k, j, n){
                        // assert(sheep < sz(ans) - 1);
                        if(s[k] == '.')
                                cnt++;
                        else            
                                ans[sheep + 1] = ans[sheep] + cnt, sheep++, cnt = 0;
                }
                cnt = 0;
                sheep = sz(ans)/2;
                for(int k = j - 2; k >= 0; k--){
                        if(s[k] == '.')
                                cnt++;
                        else    
                                ans[sheep - 1] = ans[sheep] + cnt, sheep--, cnt = 0;
                }
                cout << accumulate(all(ans), 0ll) << endl;

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