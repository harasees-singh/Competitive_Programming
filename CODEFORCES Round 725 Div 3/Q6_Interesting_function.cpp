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
int ans=0;
int recursive(int a, int b){
    if(b/10 == 0){
        ans += b - a;
        return b - a;
    }
    int beef = 10*recursive(a/10, b/10) + b%10 - a%10;
    ans += beef;
    return beef;
}
int32_t main(){
    FIO
    test_cases_loop{
        ans = 0;
        int a, b;
        cin >> a >> b; recursive(a, b);
        cout << ans << endl;
    }
}