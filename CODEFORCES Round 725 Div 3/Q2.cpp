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
        int n ; cin >> n;
        vi arr;
        int sum=0;
        loop(i, 0, n){
            int temp; cin >> temp;
            arr.pb(temp); sum+=temp;
        }
        sort(all(arr));
        if(sum%n != 0){cout << -1 << endl; continue;}
        int demand=0;
        int val = sum/n;
        loop(j, 0, n){
            if(arr[j] < val){demand+=val-arr[j];}
            else{break;}
        }
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            if(demand){demand-=arr[i]-val; ans++;}
            else{break;}
        }
        cout << ans << endl;
    }
    return 0;
}