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
#include <functional>
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long  //-2,147,483,648 to 2,147,483,647 is the range of a 4 byte integer;
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
int overhall(int &a , int &b, const int &x, const int &y){
    int big = max(x, y);// cout << big << endl;
    int small = min(x, y);
    int extra = b - a; // cout << "extra " << b - a << endl;
    // cout << a/small << space << extra/ big << endl;
    int subtract = min(a/small, extra/big);
    // cout << "subtract " << subtract << endl;
    // cout << "in func " << a << space << b << endl;
    a -= subtract*small; b -= subtract*big;
    // cout << "after func " << a << space << b << endl;
    return subtract;
}
int32_t main(){
    test_cases_loop{
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int more_candles = max(x, y), less_candles = min(x, y);
        int pairs = 0;
        while(more_candles - less_candles >= max(a, b) And less_candles >= min(a, b))
        {
            // cout << "debug " << more_candles << space << less_candles << endl;
            pairs += overhall(less_candles, more_candles, a, b); 
            // cout << "pairs " <<pairs << endl;
            // cout << "debug " << less_candles << space << more_candles << endl;
        }
        
        // cout << "zero " << less_candles/(a+b) << endl;
        pairs += 2*(less_candles/(a+b));

        
        
        more_candles -= (a+b)*(less_candles/(a+b)); less_candles -= (a+b)*(less_candles/(a+b)); 
        // cout << "parits " << pairs << space << "less "<< less_candles << space << "more " << more_candles << endl;

        // less_candles >= min(a, b) And more_candles >= max(a, b) ? pairs++, less_candles-= min(a, b), more_candles -= max(a, b) : pairs = pairs;

        while(more_candles >= max(a, b) And less_candles >= min(a, b)){
            
            pairs ++; more_candles -= max(a, b); less_candles -= min(a, b);
        }

        cout << pairs << endl;
    }
}