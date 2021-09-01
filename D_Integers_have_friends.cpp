#include <stack>
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
#include <climits>
#include <functional>

#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
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
#define ff first
#define ss second
using namespace std;
template<typename T>
void print(array<T,2> &arr);
template<typename T>
void print(vector<T> &v);
template<typename T>
void print(deque<T> &v); 
template<typename T>
T _gcd(T a, T b);
template<typename T>
vector<T> sieve(T n);
template<typename T>
T power(T x, T y, int p = LLONG_MAX);
int nxt();
// Returns n^(-1) mod p 
template<typename T>
T modInverse(T n, T p);
int gcd(vector<int> &diff);
bool isPowerof2(int x);
vector<int> divisors(int n){
	vector<int> ans;
	for(int i = 2;i<=sqrt(n);i++){
		if(n % i ==0){
			ans.pb(i);
			if(n/i != i) ans.pb(n/i);
		}
	}
	ans.pb(1);
	return ans;
}
int gcd(int a, int b){
    if (a< b){
        return gcd(b, a);
    }
    if (b==0){
        return a;
    }
    if (a==b){
        return a;
    }
    return gcd(b, a%b);
}


int findRangeGcd(int l, int r, int arr[], int n, vector<vi>& table){

    int nn=1;

    int count = 1;

    while(nn<<1 < (r-l+1)) nn <<= 1, count++;

    return __gcd(table[count-1][l], table[count-1][r - nn + 1]);
}

  
int good(int length, int arr[], int n, vector<vi>& table){
    int l(1);

    int r = l + length - 1; 
    
    while(r < n+1){
    
        if (findRangeGcd(l, r, arr, n, table) != 1){

            return true;
        }
        l++;
        r++;
    }
    return false;
}

int32_t main(){
    FIO
	test_cases_loop{
        int n; cin>>n;
        int arr[n];
        int consec = 0;
    
        loop(i, 0, n){
            cin>>arr[i];
        }

        if (n==1){
            cout<<1<<endl; continue;
        }

        int diff[n-1];
    
        loop(i, 0, n-1){
            diff[i] = abs(arr[i] - arr[i+1]);
        }

        int nn=1;

        int count = 1;

        while(nn<<1 < n-1) nn <<= 1, count++;

        nn=count;
    
        vector<vi> sparseTable(nn + 1, vi(n));

        loop(i, 1, n){sparseTable[0][i] = diff[i - 1];}

        // 1 based indexing
        loop(i, 0, nn)
    
            loop(j, 1, n-(1<<i)){

                sparseTable[i+1][j] = __gcd(sparseTable[i][j], sparseTable[i][j + (1<<i)]);
            } 


        int ans = 0;
    
        int lo(1), hi(n);
    
        while (lo<=hi){
    
            int mid = lo + (hi-lo)/2;
    
            if (good(mid, diff, n-1, sparseTable)){
    
                lo = mid+1;
                ans = mid;
            }
            else{
                hi = mid-1;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
