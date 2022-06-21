#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7, inf = 1e18;


void solve()
{
    int n, q, f1, f2, a, b, l, r;
    cin >> n >> q >> f1 >> f2 >> a >> b;

    int x[n + 3], y[n + 3]{0}, f[n + 3];
    f[0] = 0, f[1] = f1, f[2] = f2;

    for (int i = 1 ; i < n + 1; i++) cin >> x[i];

    for (int i = 3 ; i < n + 1; i++)    
        f[i] = ((a * f[i - 2])%mod + (b * f[i - 1])%mod) % mod;

    while (q--)
    {    
        cin >> l >> r;

        if(!(r - l))
        {    
            y[l] += f[1];
            y[l + 1]  = (y[l + 1] - (b * f[1])%mod + mod) % mod;
            y[l + 2]  = (y[l + 2] - (a * f[1])%mod + mod) % mod;
            continue;
        }

        y[l] += f[1];
        y[l + 1] = (y[l + 1] + f[2] - (b * f[1])%mod + mod)  % mod;  
        y[r + 1] = (y[r + 1] - f[r - l + 2] + mod)     % mod;
        y[r + 2] = (y[r + 2] - (a * f[r - l + 1])%mod + mod) % mod;

    }

    for (int i = 2 ; i < n + 1; i++)
        y[i] = (y[i] + (a * y[i - 2])%mod + (b * y[i - 1])%mod) % mod;

    for (int i = 1 ; i < n + 1; i++)    
        x[i] = (x[i] + y[i]) % mod,
        cout << x[i] << " ";

    return;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    // solve();
    cout << (-6)%5 << endl;
    
    return 0;
}