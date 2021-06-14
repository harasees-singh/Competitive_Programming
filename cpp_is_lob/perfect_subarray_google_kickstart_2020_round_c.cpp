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
#include <numeric>
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
MOD_DEFINE
int __gcd(int a, int b){
    if(b==0) return a;
    return __gcd(b, a%b);
}
vi reusable(1e8, 0);
int32_t main(){
    FIO
    loop(i, 0, 3163){
        reusable[i*i + (int)1e7]=1;
    }
    int case_ = 0;
    test_cases_loop{
        int number_of_zeroes=0;
        int n; cin >> n; vi arr(n+1);
        int ans=0;
        // reusable[0 + (int)1e7]=1;
        bool parity=true;
        loop(i, 1, n+1){
            int temp; cin >> temp;
            arr[i] = temp; // sqrt(temp)==(int)sqrt(temp) And parity ? number_of_zeroes++ : parity=false;
            arr[i]+=arr[i-1];
            loop(j, 0, 3163)
            {
                reusable[arr[i] + j*j + (int) 1e7]++;
            }
        } 
        // cout << arr[1] << space << arr[2] << space << arr[3] << endl;
        // cout << reusable[6] << endl;
        loop(it, 1, n+1)
        {
            
            // cout << reusable[arr[it] + (int)1e7] << endl;
            ans += reusable[arr[it] +(int) 1e7];
        }
        loop(i, 1, n+1){
            loop(j, 0, 3163)
            {
                reusable[arr[i] + j*j +(int) 1e7] = 0;
            }
        } 
        case_++;
        cout << "Case #" << case_ << ':' << space << ans - n - number_of_zeroes << endl;
    }
}