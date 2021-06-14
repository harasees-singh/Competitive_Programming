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
    test_cases_loop{
        bool yeas = true;
        int n; cin >> n;
        vi input;
        set<int> tree_set;
        // int median = -infinity;
        // int front = infinity; int front_to_front = infinity;
        // int back; int back_to_back;
        loop(i, 0, n){
            int temp;cin >>  temp;
            input.pb(temp);
        }
        tree_set.insert(input[0]);
        loop(i, 1, n){
            int element = input[i];
            int previous_median = input[i-1];
            set<int>::iterator it = tree_set.upper_bound(previous_median);
            
            if(it != tree_set.end() And *it < element And element > previous_median)
            {
                yeas = false; break;
            }

            it = tree_set.lower_bound(previous_median);

            if(it != tree_set.begin() And *(--it) > element And element < previous_median)
            {
                yeas  = false; break;
            }
            tree_set.insert(element);
        }
        if(yeas)cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
}