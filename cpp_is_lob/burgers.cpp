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
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

int murder(int a, unordered_set<int> &restricted){
    if(a==0)return -1; if(a==1) return 1;
    int streak = floor(log2(a+1)); int remaining = a - round(pow(2, floor(log2(a+1)))) +1;
    if(restricted.find(streak)!=restricted.end()) return INT64_MIN;
    else restricted.insert(streak);
    return streak + murder(remaining, restricted) + 1;
}
int32_t main(){
    // cout << murder(7) << endl;
    test_cases_loop
    {
        unordered_set<int> restricted;
        int x, y; cin >> x >> y;
        if(y%x != 0){
            cout << -1 << endl;
            continue;
        }
        else{
            int ans=murder(y/x, restricted); if(ans>0) cout << ans << endl; else cout << -1 << endl;
        }
    }
}