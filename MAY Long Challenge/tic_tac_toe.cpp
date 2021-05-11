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
set<vector<string>> hellya;
void recursion(vector<string> chessboard, int xcount, int ocount)
{
    loop(i, 0, 3)
    {
        loop(j, 0, 3)
        {
            if(chessboard[i][j]=='_')
            {
                chessboard[i][j]='X'; hellya.insert(chessboard); recursion(chessboard, xcount+1, ocount);
                if(xcount>ocount)
                {
                    chessboard[i][j]='O'; hellya.insert(chessboard); recursion(chessboard, xcount, ocount+1);
                }
            }
        }
    }
}
int32_t main()
{
    test_cases_loop
    {
        vector<string> chessboard(0);
        loop(i, 0, 3)
        {
            string given;
            cin >> given;
            chessboard.pb(given);
        }
        vector<string> input = {"___", "___", "___"};
        recursion(input, 0, 0);
        for(auto i:hellya)
        {
            loop(j, 0, hellya.size())
            {
                cout << i[j] << endl;
            }
            cout << "------------------------------------" << endl;
        }
        if(hellya.find(chessboard)!=hellya.end()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
