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
#define int long long
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
    FIO MOD_DEFINE
    test_cases_loop{
        int n, l, r;
        cin >> n >> l >> r;
        int final_ans = 0;
        vi arr;
        loop(i, 0, n){
            int temp; cin >> temp;
            arr.pb(temp);
        }
        sort(all(arr));                 // nlong worth of preprocessing; sort the array so that we can use binary search and calculate lower bound and upper bound in logn
        if(n==1){cout << 0 << endl; continue;}
        if(arr[0]+arr[1] > r Or arr[n-1]+arr[n-2] < l){cout << 0 << endl; continue;}        // this is not corner case handling; this is just an obvious fact.
        loop(j, 0, n)
        {
            int count = 0;

            int curr =arr[j];
            
            int ans_r = (int)(upper_bound(all(arr), r - arr[j]) - arr.begin());     // this spits the index of the first number that when added to arr[j] will produce a sum strictly greater than r
            
            int ans_l = (int)(lower_bound(all(arr), l - arr[j]) - arr.begin());     // this spits the index of the left most index that when added to arr[j] will produce a sum greater than or equal to l
        
            if(j >= ans_l And j < ans_r){count++;}                                  // to avoid pairs like (j, j) where j is an index so just subtract these quietly.
            
            final_ans += (ans_r - ans_l - count);                                   // add all the pairs to final_ans;
        }
        cout << (final_ans)/2  << endl;                                             // hold up kiddo! u counted every pair twice; ez divide by 2 and u r good to go.
    }
    return 0;
}
