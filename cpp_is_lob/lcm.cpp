#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x

using namespace std;
MOD_DEFINE

int lcm(int a, int b){return (a*b)/__gcd(a, b);}

int32_t main(){
    FIO 

    // jump n times

    // number of times x%m = i for i = 0 to m - 1;

    // jump by k, 0, k, 2k, 3k and so on
    // do the algo for 0, k, 2k, ..... till LCM(k, m) - k;

    // from LCM it will repeat

    int n, m, k; cin >> n >> k >> m;

    vi ans(m);

    for(int i = 0; i < m; i++){

        int rem_req = i;

        int cnt = 0;

        for(int j = 0; j < (k*m)/__gcd(k, m); j+= k){

            cnt += (bool)(j%m == i);
        }

        ans[i] = cnt*((n*k)/(lcm(m, k)));

        for(int j = ((n*k)/(lcm(m, k)))*(lcm(m, k)); j <= n*k; j += k){

            ans[i] += (bool)(j%m == i);
        }
    }

    for(auto p : ans) cout << p << space; cout << endl;

    return 0;
}
