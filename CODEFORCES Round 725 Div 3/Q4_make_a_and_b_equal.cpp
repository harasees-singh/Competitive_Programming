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
// #define int long long -2,147,483,648 to 2,147,483,647 is the range of a 4 byte integer;
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
// defining int as long long in this particular question leads to tle; 
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}
int getp(int x){
	int y = x;
	int ans = 0;
	while(y%2 == 0){
		y/=2;
		ans++;
	}
	for(int i = 3; i <= sqrt(x);i+=2){
		while(y%i == 0){
			y/=i;
			ans++;
		}
	}
	if(y!=1) ans++;
	return ans;
}
 
int32_t main(){
    FIO MOD_DEFINE
    
    test_cases_loop{
        int a, b, k;
        cin >>  a >> b >> k;
        // a= 45, b=9;
        int a_fact, b_fact;
        int __gcd = gcd(a, b);
        a/=__gcd; b/=__gcd;
        // cout << primeFactors(48) << endl;
        int primes_of_a = getp(a), primes_of_b = getp(b);
        // cout << primeFactors(9) << endl;
        int upper_limit = primes_of_b + primes_of_a;
        upper_limit += 2*getp(__gcd);
        if(a==b){
            if(k==1){cout << "NO" << endl; continue;}
        }
        if(1 == a Or 1 == b){
            if(k <= upper_limit){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
            continue;
        }
        k <= upper_limit And k >= 2 ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}