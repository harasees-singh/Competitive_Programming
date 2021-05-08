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
int32_t main()
{
    test_cases_loop
    {
        int n;
        cin >> n;
        int ten_power = 1;
        int count=0;
        while(n/ten_power)
        {
            ten_power*=10;
            count++;
        }
        int all_ones_number=0;
        int temp=1;
        // cout << "no of digits = " << count << endl;
        
        loop(i, 0, count)
        {
            all_ones_number += temp;
            temp *= 10;
        }
        int ans=0;
        ten_power=ten_power/10;
        // cout << "temp all ones = " << all_ones_number << endl;
        // cout << "ten power = " << ten_power << endl;
        ans += n/all_ones_number;               // this gives the count of 111, 222, 333, 444 in case of 576;
        ans += (count-1)*9;
        cout << ans << endl;
    }
}