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
int32_t main(){
    int case_ = 0;
    // cout << parity << endl;
    test_cases_loop
    {
        case_++;
        int n; cin>> n;
        n*=2;
        int count=0;
        for(int i=1; i<round(pow(n, 0.5))+1; i++){
            if(n%i == 0){
                if((i%2 == 0 And (n/i) % 2 !=0) Or (i%2!=0 And (n/i)% 2==0)){
                    count++;
                }
            }
        }
        cout << "Case #" << case_ << ":" << " "  << count << endl;
    }
}