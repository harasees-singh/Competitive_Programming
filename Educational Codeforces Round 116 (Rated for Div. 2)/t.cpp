#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void knapsack_less_value()
{
    ll n, w;
    cin >> n >> w;

    vector<ll> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    // vector<ll> dp(n*1000 + 1, vector<ll>(n*1000 + 1, 999999999999));
    // dp[i, v] -> minimum number of wt you should pick upto (i + 1)th choice, to get a profit of v;

    vector<ll> prev(n * 1000 + 1, __LONG_LONG_MAX__ - 1); // replace LONG_LONG_LONG with 999999999 and it works
    vector<ll> cur(n * 1000 + 1, __LONG_LONG_MAX__ - 1); // same as up dem

    // Base-Case
    prev[0] = 0;           // Minimum weight = 0 as value = 0
    prev[val[0]] = wt[0]; // To get value = val[0] from taking only 1-item will add a weight of wt[0]

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n * 1000; j++)
        {
            if (val[i] > j) // exclude
                cur[j] = prev[j];
            else
                cur[j] = min(prev[j], prev[j - val[i]] + wt[i]);
        }
        prev = cur;
        fill(cur.begin(), cur.end(), __LONG_LONG_MAX__ - 1);
    }

    long long ans = 0LL;
    for (ll i = 0; i <= n * 1000; i++)
    {
        if (prev[i] <= w)
            ans = i;
    }
    
    cout << ans;
}

int main()
{
    knapsack_less_value();
    return 0;
}