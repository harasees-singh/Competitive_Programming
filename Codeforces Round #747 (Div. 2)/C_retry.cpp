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

    test_cases_loop{
            int n; cin >> n;

            char t; cin >> t;

            string s; cin >> s;

            if(s == string(n, t)){
                    cout << 0 << endl; continue;
            }

            int pt = n - 1;

            int ans = -1;

            for(; pt >= n/2; pt--){

                    if(s[pt] == t)
                            ans = pt + 1;
            }

            if(ans != -1)
                    cout << 1 << endl << ans << endl;
            
            else 
                    cout << 2 << endl << n - 1 << space << n << endl;
    }

    return 0;
}
