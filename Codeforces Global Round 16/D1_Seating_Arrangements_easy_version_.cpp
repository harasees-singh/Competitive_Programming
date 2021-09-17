#include<bits/stdc++.h>
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
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x

using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
MOD_DEFINE

int32_t main(){
    FIO 

    test_cases_loop{

        int n, m; cin >> n >> m;

        vector<pii> I; 

        unordered_map<int, int> extra;

        l(i, 0, n*m){

            pii temp; cin >> temp.first; temp.second = i;

            I.push_back(temp);

            extra[temp.first]++;
        }

        sort(all(I));

        int cnt = 0;

        // remember to subtract the the cases overcounted due to 1, 1, 1 types

        for(int i = 0; i < n; i++){

            ordered_set order; 

            umii extra;

            for(int j = 0; j < m; j++){

                extra[I[i*m + j].first]++;

                order.insert(I[i*m + j].second);

                cnt += order.order_of_key(I[i*m + j].second);

            }

            for(auto p : extra){

                int x = p.second;

                cnt -= (x*(x - 1))/2;
            }
        }
        
        cout << cnt << endl;
    }
    

    return 0;
}
