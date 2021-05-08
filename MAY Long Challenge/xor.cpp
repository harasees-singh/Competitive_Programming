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
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
void fastscan_integer(int &number)      // for fastest possible integer input
{   
    bool negative = false; register int c; number = 0; c = getchar();
    if (c=='-') negative = true, c = getchar();
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;      
}
using namespace std;

int list_[100001];

void pow(){
    int mod = 1000000000+7;
    int n = 100000;
    list_[1] = 1;
    list_[2] = 2;
    int cnt = 4;
    loop(i, 3, n+1){
        list_[i] = (cnt)%mod;
        cnt *= 2;
        cnt %= mod;
    }
    return;
}
int32_t main(){
    pow();
    test_cases_loop{
        int n;
        cin>>n;
        cout<<list_[n]<<endl;
    }
    return 0;
}