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
        int n; cin >> n;
        int least=infinity; int greatest = -infinity;
        int less_index, greater_index;
        vi arr;
        loop(i, 0, n){
            int temp; cin >> temp;
            arr.pb(temp);
            if(temp < least){least = temp; less_index = i;}
            if(temp > greatest){greater_index = i; greatest = temp;}
        }
        if(less_index < n/2 And greater_index < n/2){cout << max(less_index, greater_index)+1 << endl;}
        else if(less_index >= n/2 And greater_index >= n/2){cout << n-min(less_index, greater_index) << endl;}
        else{
            int index = min(less_index, greater_index);
            int index2 = max(less_index, greater_index);
            int potent_answer = min(n-index, index2+1);
            int another_answer = min(less_index+1, n-less_index) + min(greater_index+1, n-greater_index);
            cout << min(potent_answer, another_answer) << endl;
        }
        // cout << min(less_index+1, n-less_index) + min(greater_index+1, n-greater_index) << endl;
    }
    return 0;
}