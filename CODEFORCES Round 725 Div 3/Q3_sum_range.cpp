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
int Binary_search_min_index(vi &arr, int curr, int l){
    int left =0; int right = sz(arr);
    while(left < right){
        int mid = (left+right)/2;
        if(curr + arr[mid] >= l){
            right=mid;
        }
        else left=mid+1;
    }
    return left;
}

int Binary_search_max_index(vi &arr, int curr, int r){
    int left = 0; int right=sz(arr)-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(curr + arr[mid] <= r){
            left = mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return right;
}

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
        sort(all(arr));
        if(n==1){cout << 0 << endl; continue;}
        int count = 0;
        vi temp = {1, 2, 3, 4};
        loop(j, 0, n){
            int curr =arr[j];
            
            int ans_r = Binary_search_max_index(arr, arr[j], r);
            
            int ans_l = Binary_search_min_index(arr, arr[j], l);
            
            if(j >= ans_l And j <= ans_r){count++;}
            
            final_ans+= (ans_r - ans_l + 1);
        }
        cout << (final_ans- count)/2  << endl;
    }
    return 0;
}
