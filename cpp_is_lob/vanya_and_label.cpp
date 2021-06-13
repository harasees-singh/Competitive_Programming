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
MOD_DEFINE
int raised_to_power(int a, int b){
    if(b==0)return 1;
    if(b%2)return (raised_to_power(a, b/2)%MOD * (raised_to_power(a, b/2) * a)%MOD)%MOD;
    return (raised_to_power(a, b/2)%MOD * raised_to_power(a, b/2)%MOD)%MOD;
}
int onbits_generator(int someval){
    int ans=0;
    while(someval){
        ans += (someval&1); someval = someval>>1;
    }
    return ans;
}
unordered_map<char, int> dict;
int32_t main(){
    FIO
    int hash=0;
    dict['_'] = 63; dict['-'] = 62;
    loop(i, 48, 58){
        dict[i]=hash;
        hash++;
    }
    loop(i, 65, 91){
        dict[i]=hash;
        hash++;
    }
    loop(i, 97, 123){
        dict[i]=hash;
        hash++;
    }
    // cout << dict['V'] << space << dict['_'] << endl;
    string input;
    cin >> input;
    int offbits = 0;
    for(int i=sz(input)-1; i>=0; i--){
        // cout << "working " << endl;
        char curr = input[i]; int hash_value = dict[curr];
        offbits += 6 - onbits_generator(hash_value);
    }
    cout << raised_to_power(3, offbits)%MOD << endl;
}

