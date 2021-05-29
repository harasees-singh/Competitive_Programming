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
#define debug(a) cout << a << endl;
#define debug_(a, b) cout << a << " " << b << endl;
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
int ans=0;
int solve(int count, int sum, int index, vi &arr){
    if(index==arr.size()){
        if(count>ans){ans=count;}
        return 0;
    }
    if(sum-arr[index]>=0){
        solve(count +1, sum-arr[index], index+1, arr);
        
    }
    
    solve(count, sum, index+1, arr);
    return 0;
}

int32_t main(){
    FIO;
    int n; cin >> n;
    vi arr;
    loop(i, 0, n){
        int temp; cin>> temp; arr.pb(temp);
        // cout << "yes" << endl;
    }
    // cout << arr[0] << arr[1] << endl;
    solve(0, 0, 0, arr);
    cout <<ans << endl;
}