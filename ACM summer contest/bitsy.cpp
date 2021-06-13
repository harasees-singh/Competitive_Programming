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
int32_t main(){
    FIO
    int n, k; cin >> n >> k;
    int copy = n;
    int ans = n;
    int conversions=0;
    while(n>1)
    {   
        conversions++;
        int setbit_ = 0;
        while(copy%2==0){
            copy=copy/2;
            setbit_++;
        }
        
        loop(i, 0, setbit_+1){
            n = n ^ (1<<i);
            
        }
        
        ans = n;
        n -= k; 
    }
    n < 1 ? ans = ans: ans = n;
    cout << ans << space << conversions << endl;
}