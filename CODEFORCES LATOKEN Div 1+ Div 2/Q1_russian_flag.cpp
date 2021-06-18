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
#define invert(x, a, b) x == a ? x = b : x = a;
using namespace std;
int __gcd(int a, int b){
    if(b==0) return a;
    return __gcd(b, a%b);
}
MOD_DEFINE
int32_t main(){
    FIO
    test_cases_loop{
        int n, m; cin >> n >> m;
        vector<string> input; 
        loop(i, 0, n){
            string temp; cin >> temp; input.pb(temp);
        }
        pii indices_of_w = {-1, -1}, indices_of_r = {-1, -1};
        loop(i, 0, n){
            loop(j, 0, m){
                if(input[i][j] == 'W') {indices_of_w = {i, j}; break;}
                if(input[i][j] == 'R') {indices_of_r = {i, j}; break;}
            }
        }
        bool put_w_start = false;
        if(indices_of_w.first != -1){
            // found w;
            if(indices_of_w.second%2){
                // odd column number
                if(indices_of_w.first%2){put_w_start = true;}
                else{put_w_start = false;}
            }
            else{
                if(indices_of_w.first%2){put_w_start = false;}
                else{put_w_start = true;}
            }
        }
        else if(indices_of_r.first != -1){
            // consider R
            if(indices_of_r.second%2){
                // odd column number
                if(indices_of_r.first%2){put_w_start = false;}
                else{put_w_start = true;}
            }
            else{
                if(indices_of_r.first%2){put_w_start = true;}
                else{put_w_start = false;}
            }
        }
        else{put_w_start = true;}
        // cout << "parity " << put_w_start << endl;
        char start;
        bool ans=true;
        put_w_start ? start = 'W' : start = 'R'; char curr = start;
        loop(i, 0, n){
            // start == 'W' ? start = 'R' : start = 'W';
            loop(j, 0, m){
                if(input[i][j] == curr Or input[i][j] == '.'){curr == 'W' ? curr = 'R' : curr = 'W'; continue;}
                else{ans = false; break;}
            }
            if(m%2 == 0) curr == 'W' ? curr = 'R' : curr = 'W';
        }
        // cout << "answer " << ans << endl;
        if(ans){
            cout << "YES" << endl;
            char start;
            put_w_start ? start = 'W' : start = 'R';
            loop(i, 0, n){
                loop(j, 0, m){
                    cout << start; start == 'W' ? start = 'R' : start = 'W';
                }
                cout << endl;
                if(m%2 == 0) start == 'W' ? start = 'R' : start = 'W';
            }
        }
        else cout << "NO" << endl;
    }
    return 0;
}