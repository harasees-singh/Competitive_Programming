#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define Set                             tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;

MOD_DEFINE

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;

        vi a(n), b(n);

        l(i, 0, n){

            cin >> a[i];
        }

        l(i, 0, n)

            cin >> b[i];


        unordered_map<int ,int> love;

        // store k ya k > element kaha pr hai

        // in even array

        int maxi = 0;

        int index = 0;

        for(int i = 0; i < n; i++){


            love[b[i]/2] = i;
        }

        for(int i = n - 1; i >= 1; i--){

            love[i] = min(love[i], love[i + 1]);
        }

        int ans = infinity;

        l(i, 0, n){

            int curr = a[i];

            int bada = love[(a[i] + 1)/2];

            // suppose 0

            ans = min(ans, i + bada);
        }

        cout << ans << endl;
    }
}