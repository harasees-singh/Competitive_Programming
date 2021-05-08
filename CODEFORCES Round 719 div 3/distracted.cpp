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
        vi alphabets(26, 0);
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool parity=true;
        string processed="";
        processed.push_back(s[0]);
        char curr=s[0];
        loop(i, 0, s.size())
        {
            if (curr==s[i]) continue;
            else processed.push_back(s[i]), curr = s[i];
        }
        for(auto ch:processed)
        {
            if(alphabets[ch-65]) {cout << "NO" << '\n', parity=false; break;}
            else alphabets[ch-65]=1;
        }
        if(parity) cout << "YES" << '\n';
    }
}