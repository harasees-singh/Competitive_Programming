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
        vi answer(0);
        vi given(0);
        loop(i, 0, n)
        {
            int temp;
            cin >> temp;
            answer.pb(temp-i);
        }
        int ans=0;
        sort(answer.begin(), answer.end());
        int noob = 1;
        bool parity=true;
        loop(i, 0, n-1)
        {
            // cout << answer[i] << endl;
            if(answer[i] == answer[i+1]){noob++;}
            else {ans += (noob)*(noob-1)/2 ; noob=1; parity=false;}
        }
        // if(parity){cout << (noob)*(noob-1)/2 << endl; continue;}
        cout << ans + (noob)*(noob-1)/2 << endl;
    }
}
