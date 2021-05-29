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
int32_t main(){
    test_cases_loop{
        int n; cin >> n;
        vi store;
        n=n*2;
        loop(i, 0, n){
            int temp; cin >> temp;
            store.pb(temp);
        }
        sort(store.begin(), store.end());
        int mid_index = n/2;            // 3 for the case 6;
        loop(i, 0, mid_index){
            cout << store[i] << " " << store[i+mid_index] << " ";
        }
        cout << endl;
    }
}