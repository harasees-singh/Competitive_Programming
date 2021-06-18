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
MOD_DEFINE
int32_t main(){
    FIO
    test_cases_loop{
        int n; cin >> n;
        vi input = {0};
        int cost = 0;
        loop(i, 1, n+1){
            int temp; cin >> temp; input.pb(temp);
            cost += abs(temp - input[i-1]);
        }
        cost += input[sz(input)-1];
        input.pb(0);
        loop(j, 1, n+1){
            int back = input[j-1];
            int front = input[j+1];
            int curr = input[j];
            curr > front And curr > back ? cost -= min(curr - back, curr - front) : cost = cost ;
        }
        cout << cost << endl;
    }
    return 0;
}