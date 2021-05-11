#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
void fastscan_integer(int &number)      // for fastest possible integer input
{   
    bool negative = false; register int c; number = 0; c = getchar();
    if (c=='-') negative = true, c = getchar();
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;      
}
using namespace std;
int factor_count(int b, int limit)
{
    int count=0;
    loop(i, 1, (int) pow(b, 0.5)+1)
    {
        if(limit%i==0){
            if(limit%(b/i)==0){
                continue;
            }
            else if(i<limit){
                count--;
            }
        }
        else if(limit%(b/i)==0 && limit> b/i) count--;
        if (b/i < limit && i<limit){
            count+=2; 
            if(i==b/i)count--;
        }
        else if(i < limit) count++;
    
    }
    return count;
}
int find_factors(int m, int n)
{
    int i=1;
    int ans=0;
    if(n>m){
        n=m;
    }
    while(n/i > 1)
    {
        ans+=(n/i)-1; i++;
    }
    return ans;
}
int32_t main()
{
    FIO
    
    test_cases_loop
    {
        int fans=0;
        int n; cin >> n;
        int m; cin >> m;
        loop(b, 1, (m+1)/2+2)
        {
            if(b>n) break;
            int ans = factor_count(m/b, b);
            fans+=ans;
        }
        // cout << "factor count " << factor_count(36, 10) << endl;
        if(n>m){
            fans+=(n-m)*(n+m-1)/2;
        }
        fans+=find_factors(m, n);
        cout << fans << endl;
    }
    
}