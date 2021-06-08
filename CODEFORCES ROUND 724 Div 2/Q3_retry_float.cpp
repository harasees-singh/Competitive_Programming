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
int __gcd(int a, int b){
    if(b==0) return a;
    return __gcd(b, a%b);
}
int32_t main(){
    FIO;
    test_cases_loop{
        unordered_map<long double, int> hardware;
        int n; cin >> n;
        string s; cin >> s;
        long double d=0, k=0;
        for(auto a:s){
            if(a=='D'){d++;} else{k++;}
            long double fraction;
            k==0 ? fraction=-1 : fraction=d/k;
            // if(k==0) fraction=infinity; else fraction = d/k;
            hardware[fraction]++; cout << hardware[fraction] << space;
        }
        cout << endl;
    }
    return 0;
}