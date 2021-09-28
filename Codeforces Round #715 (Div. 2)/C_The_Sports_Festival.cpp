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
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

const int N = 2000;

vector<vi> dp(N, vi(N, -1));

int rec(vi &I, int l, int r){
    if(l == r)
        return 0;
    if(dp[l][r] == -1)
        return dp[l][r] = I[r] - I[l] + min(rec(I, l, r - 1), rec(I, l + 1, r));
    return dp[l][r];
}

int32_t main(){
    FIO 

    int n; 
    cin >> n;

    vi I(n);
    l(i, 0, n)
            cin >> I[i];
    sort(all(I));

    cout << rec(I, 0, n - 1) << endl;

    return 0;
}
