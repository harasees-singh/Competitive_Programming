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

// vector<vi> dp(101, vi(2e5 + 1, 0));

bool dp[101][(int)2e5 + 1];

int32_t main(){
    FIO

    int n; cin>> n;

    int I[n];

    int S = 0;

    l(i, 0, n){  

        cin >> I[i]; S += I[i];}

    // dp[i][s] will be 1 if s sum is possible by including some elements till and including index i

    // dp[i][s] = (dp[i - 1][s] or dp[i - 1][s - arr[i]])

    // range of sums is from 1 to 2e5

    dp[0][0] = 1;

    l(i, 1, n + 1)

        l(j, 1, 2e5 + 1){

            // dp[i][I[i]] = 1;

            dp[i][j] = dp[i - 1][j];

            dp[i][0] = 1;

            if(j - I[i] >= 0)

                dp[i][j] |= dp[i - 1][j - I[i]];
        }

    if(S%2 or dp[n][S/2] == 0){

        cout << 0 << endl; 

        return 0;
    }

    int gcd = I[0];

    l(i, 0, n)

        gcd = __gcd(I[i], gcd);

    int odd;

    for(int i = 0; i < n; i++){

        if((I[i]/gcd)%2) odd = i + 1;
    }
    cout << 1 << endl << odd << endl;

    return 0;
}