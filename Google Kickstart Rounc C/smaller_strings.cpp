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
#define And &&
#define Or ||
#define int long long
#define space " "
#define vi vector<int>
#define pb(n) push_back(n)
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
MOD_DEFINE
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2)%MOD;
    else
        return x * power(x, y / 2) * power(x, y / 2)%MOD;
}    
bool str_parity(string &s){
    // bool palindrome=false; 
    int mid_index = ceil(s.size()/2.0)-1;
    loop(i, mid_index+1, s.size()){
        if(s[i]<s[s.size()-i-1]){
            return false;
        }
        else if(s[i]==s[s.size()-i-1]){
            continue;
        }
        else{
            // palindrome=false;
            return true;
        }
    }
    return false;
}
int32_t main(){
    FIO
    int case_=0;
    test_cases_loop
    {   
        case_++;
        int n, k; cin >> n >> k;
        string s; cin>> s;
        int ans = 0;
        // if(s.length()) cout << "success " << endl;
        int mid_index = ceil(s.size()/2.0)-1;
        loop(i, 0, mid_index+1){
            ans += ((s[i]-'a')*power(k, mid_index-i)%MOD)%MOD;
            ans%=MOD;
        }
        // if(n>1)
            // if((n%2==0 And s[mid_index] < s[mid_index+1]) Or (n%2!=0 And s[mid_index-1] < s[mid_index+1]))
        if(str_parity(s))
        {
            ans++;
        }    
        cout << "Case #" << case_ << ":" << space << ans << endl;
    }
}