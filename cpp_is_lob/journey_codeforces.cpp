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
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define pb(n) push_back(n)
using namespace std;
void Print(vi &answer)
{
    for(auto i:answer)
    {
        cout << i << " " ;
    }
    cout << endl;
}
int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        n++;
        string directions;
        cin >> directions;
        vi odd_even(n, 0);
        vector<vi> prefix(2, odd_even);
        vector<vi> suffix(2, odd_even);
        // filling up prefix
        prefix[0][0] = prefix[1][0] = 0;
        loop(i, 1, n)
        {
            if(directions[i-1]=='L') prefix[0][i] = 1 + prefix[1][i-1];
            else prefix[0][i] = 0;
            if(directions[i-1]=='R') prefix[1][i] = 1 + prefix[0][i-1];
            else prefix[1][i] = 0;
        }
        suffix[0][n-1] = suffix[1][n-1] = 0;
        for(int i=n-2; i>=0; i--)
        {
            if(directions[i]=='R') suffix[0][i] = 1 + suffix[1][i+1];
            if(directions[i]=='L') suffix[1][i] = 1 + suffix[0][i+1];
        }
        vi answer(0);
        loop(i, 0, n)
        {
            answer.pb(prefix[0][i] + 1 + suffix[0][i]);
        }
        Print(answer);
    }
}