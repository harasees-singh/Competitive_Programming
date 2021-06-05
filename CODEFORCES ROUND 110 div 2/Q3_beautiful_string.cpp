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
char invert(char a){
    char ans;
    a=='1'? ans= '0':ans= '1'; return ans;
}
int32_t main(){
    FIO
    test_cases_loop{
        string s;
        cin >> s;
        int ans=0;
        int contiguous_count=1;
        char last = s[0];
        bool parity=false; if(last=='?')parity=true;
        int i=1;
        int subtract=0;
        while(i<sz(s)){
            char consideration = s[i];
            // cout << i << endl;
            // cout << "yo" << endl;

            if(consideration=='?'){parity=true; contiguous_count++; last=invert(last);i++; continue;}
            if(consideration==invert(last)){contiguous_count++; last=consideration; parity=false;}
            else if(parity){
                ans+= contiguous_count*(contiguous_count+1)/2;
                contiguous_count=0; last=consideration; subtract+=1; parity=false; i-=1; while(s[i]=='?' And i>0)i--;
            }
            else{
                ans+= contiguous_count*(contiguous_count+1)/2; contiguous_count=1;last=consideration; parity=false;
            }
            i+=1;
        }
        ans+= contiguous_count*(contiguous_count+1)/2;
        cout << ans - subtract<< endl;
    }
}

