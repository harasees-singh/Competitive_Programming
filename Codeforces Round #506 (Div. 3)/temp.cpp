#include<bits/stdc++.h>

using i64 = long long; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 a, b;
    std::cin >> a >> b;
    
    i64 x = a + b;
    i64 ans = 2 * x;

    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            ans = std::min(ans, 2LL * (i + (x / i)));
    }
    
    std::cout << ans << "\n";

    return 0;
}