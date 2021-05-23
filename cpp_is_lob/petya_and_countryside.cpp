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
int32_t main(){
    int n; cin >> n;
    int copy=n;
    vi city(0);
    while(copy--)
    {
        int temp; cin >> temp;
        city.pb(temp);
    }   
    vi prefix;
    vi suffix;
    int count=0;
    int curr=INT32_MAX;
    for(auto a:city){
        if(a>=curr){
            count++;
        }
        else{
            count=0; 
        }
        prefix.pb(count);
        curr =a;
    }      
    int curr_ = INT32_MAX; 
    count=0;         
    for(int i=n-1; i>=0; i--){
        if(city[i]>=curr_){
            count++;
        }
        else{
            count=0;
        }
        suffix.pb(count);
        curr_ = city[i];
    }     
    int ans=INT32_MIN;
    loop(i, 0, n){
        // cout << "prefix =" << space << prefix[i] << " suffix " << suffix[i] << endl;
        int potent_answer = prefix[i]+suffix[n-1-i]+1;
        if(potent_answer>ans){
            ans = potent_answer;
        }
    }    
    cout << ans << endl;
}

