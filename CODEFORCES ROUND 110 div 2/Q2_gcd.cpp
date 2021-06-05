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
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
// using namespace __gnu_pbds;
int gcdcall(int a, int b)
{
    if (a == 0)
        return b;
    return gcdcall(b % a, a);
}
// euclidean algo O(1)
int32_t main(){
    FIO
    test_cases_loop{
        int n; cin >> n;
        vi arr;
        loop(i, 0, n){
            int temp; cin >> temp; arr.pb(temp);
        }
        int ans=0;
        // sort(all(arr), greater<int>());
        // cout << arr[0] << space << arr[1] << endl;
        loop(i, 0, n){
            loop(j, i+1, n){
                int a = arr[i], b = arr[j];
                // if(a%2==0){ans++; continue;}
                int gcd1 = gcdcall(a, 2*b);
                int gcd2 = gcdcall(2*a, b);
                if(gcd1>1 Or gcd2>1)ans++;
            }
            // cout << __gcd(2, 6) << endl;
        }
        cout << ans << endl;
    }  
    return 0;
}

