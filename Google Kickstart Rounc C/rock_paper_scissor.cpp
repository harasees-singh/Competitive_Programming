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
string ans_generator(int w, int e){
    string ans = "RS";
    float r_count=1.0, p_count=1.0, s_count=0.0;
    float r_probability=0.5;
    float p_probability=0.5;
    float s_probability=0;
    for(int i=3;i<=60;i++){
        float s_expected_money = s_probability*e + p_probability*w;
        float r_expected_money = r_probability*e + s_probability*w;
        float p_expected_money = p_probability*e + r_probability*w;

        if(s_expected_money >= max(r_expected_money, p_expected_money)){
            ans = ans+"S"; s_count++;
        }
        else if(r_expected_money >= max(p_expected_money, s_expected_money)){
            ans = ans+"R"; r_count++;
        }
        // if(p_expected_money >= max(r_expected_money, s_expected_money)){
        else{
            ans = ans+"P"; p_count++;
        }


        // if(r_probability <= s_probability And r_probability <= p_probability){
        //     s_count++; ans = ans + "S";
        // }
        // else if(s_probability <= r_probability And s_probability <= p_probability){
        //     p_count++; ans = ans + "P";
        // }
        // else{
        //     r_count++; ans = ans + "R";
        // }
        r_probability = s_count/i; p_probability = r_count/i; s_probability = p_count/i;
    }
    return ans;
}
int32_t main(){
    int case_=0;
    
    int t; cin >> t;
    int expected_val;
    cin >> expected_val;
    while(t--){
        case_++;
        int w, e; cin >> w >> e ;
        string ans = ans_generator(w, e);
        cout << "Case #" << case_ << ":" << space << ans << endl;
    }
}