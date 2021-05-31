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
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
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
vi is_prime(10000000+1, 1);
vi dp(10000000+1);
void sieve() {
    // We cross out all composites from 2 to sqrt(N)
    int N = 10000000;
    int i=2;
    // This will loop from 2 to int(sqrt(x))
    while(i*i <= N) {
        // If we already crossed out this number, then continue
        if(is_prime[i] == 0) {
            i++;
            continue;
        }
        int j = 2*i;
        while(j < N) {
            // Cross out this as it is composite
            is_prime[j] = 0;
            // j is incremented by i, because we want to cover all multiples of i
            j += i;
        }
        i++;
    }
}
void solve(){
    // count prime numbers strictly greater than a/2 till a
    int top = 10000000+1;
    int curr = 0;

    for(int i=2; i<10000000+1; i+=1){
        if(is_prime[i]){curr++;}
        dp[i] = curr;
    }
    // dp[n] stores the number of primes till n found including n;
}
int32_t main(){
    FIO
    sieve();
    solve();
    dp[1]=1;
    // cout << "yeh";
    // cout << dp[2] << space << dp[1]<< endl;
    // cout << is_prime[97] << endl;
    test_cases_loop{
        int n; cin >> n;
        // 2 to n total n-1 numbers
        
        
        cout << dp[n]- dp[n/2]+1 << endl;
        
    }
}

