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
int MOD = 1000000007;
int __gcd(int a, int b){
    if(b==0) return a;
    return __gcd(b, a%b);
}
int32_t main(){
    FIO
    test_cases_loop{
        int n; cin >> n;
        vi a, b;
        unordered_map<int, int> atob;
        loop(i, 0, n){
            int temp; cin >> temp; a.pb(temp);
        }
        loop(i, 0, n){
            int temp; cin >> temp; b.pb(temp);
            atob[a[i]] = temp;
        }
        int ans=1;
        vi visited(n+1, 0);
        loop(j, 0, n){
            if(visited[a[j]])continue;
            int first = a[j];
            int second = a[j];
            bool run=false;
            while(atob[first]!=second){
                visited[first]=1;
                first = atob[first];
                run=true;
            }
            visited[first]=1;
            if(run)ans=(ans << 1)%MOD;
        }
        cout << ans%MOD << endl;
    }
    return 0;
}