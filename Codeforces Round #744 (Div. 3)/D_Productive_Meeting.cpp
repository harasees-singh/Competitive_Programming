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
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;

        set<pii> I;

        l(i, 0, n){
            int t; cin >> t;

            I.insert({t, i + 1});
        }

        vector<pii> ans;
        
        while(true){

            int f, s, F, S;

            tie(f, s) = (*--I.end());
            tie(F, S) = (*(--(--I.end())));

            if(f and F){

                // cout << s << space << S << endl;
                ans.push_back({s, S});
                
                I.erase({f, s});
                I.insert({f - 1, s});
                I.erase({F, S});
                I.insert({F - 1, S});
            }

            else break;
        }

        cout << sz(ans) << endl;

        for(auto p : ans)
                cout << p.ff << space << p.ss << endl;
    }

}
