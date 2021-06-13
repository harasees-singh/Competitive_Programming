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
#define int long long  //-2,147,483,648 to 2,147,483,647 is the range of a 4 byte integer;
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
void add_key(string var, string value, map<string , string> &dict){
    dict[var] = value;
}
inline int max_(int a, int b){if(a >= b)return a; return b;}
inline char invert(char in){if(in == 'h')return 'a'; return 'h';}
int32_t main(){
    FIO
    test_cases_loop{
        int n; cin >> n;
        map<string, string> var_string;
        string last;
        loop(i, 0, n){
            bool addition = false;
            string input; cin >> input;
            string concatenate1, concatenate2, plus;
            string sign; cin >> sign ; 

            if(sign[0]==':'){cin >> concatenate1;}

            else{cin >> concatenate1; cin >> plus; cin >> concatenate2; }

            // cout << input << endl;
            
            
            if(sign[0]==':'){add_key(input, concatenate1, var_string);}
            else{
                string curr = var_string[concatenate1] + var_string[concatenate2];
                
                add_key(input, curr, var_string);
            }
            last = input;
        }
        var_string[last]+='0';
        int ans=0;
        
        // cout << "debug " << var_string[last] << endl;

        int i=0; 
        string op = var_string[last];
        while(i<sz(op)){
            char curr = op[i];
            if(curr == 'h'){
                // bool parity=true;
                i++;
                int count=1;
                while(i<sz(op)){
                    // cout << "curr " << var_string[last][i] << space << invert(curr)<< endl;
                    if(op[i] == invert(curr)){curr = op[i]; count++;}
                    else{
                        
                        if(count%2){count--;}
                        ans+= max_(((count/2) - 1), 0); count = 0;
                        break;
                    }
                    i++;
                }
                // if(count%2){count=0;}
                // else {ans+= max_(((count/2) - 1), 0); count = 0;}
            }
            else{
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}