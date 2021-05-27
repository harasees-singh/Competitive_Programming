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
#define debug(a) cout << a << endl;
#define debug_pair(a, b) cout << a << " " << b << endl;
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define space " "
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
string ans_generator(float w, float e){

    vector<vector<vector<float>>> dp(61, vector<vector<float>>(61, vector<float>(61)));
    vector<vector<vector<string>>> strings_dp(61, vector<vector<string>>(61, vector<string>(61)));
    
    float ans=0;
    string to_be_printed;
    
    for(int rock=0; rock<=60; rock++){
        for(int paper=0; paper<=60; paper++){
            for(int scissor=0; scissor<=60; scissor++){
                // cout << "rock paper ";
                // debug_pair(rock, paper);
                // if(rock+paper+scissor==0) continue;
                if(rock+paper+scissor > 60) break;
                if(rock+paper+scissor<=1){
                    // denomi will be zero so will have to do something
                    if(scissor Or paper Or rock) dp[rock][paper][scissor] = w*1/3 + e*1/3; 
                    if(scissor) strings_dp[rock][paper][scissor]="S"; if(rock) strings_dp[rock][paper][scissor]="R"; if(paper) strings_dp[rock][paper][scissor]="P";
                    continue;
                }
                
                float s_expected = 0; float r_expected = 0; float p_expected = 0;
                
                float win_factor = w/(rock+scissor+paper-1.00); float tie_factor = e/(rock+scissor+paper-1.00);

                if(scissor>=1) s_expected = dp[rock][paper][scissor-1] + rock*win_factor + paper*tie_factor;
                
                if(rock>=1) r_expected =  dp[rock - 1][paper][scissor] + paper*win_factor+ scissor*tie_factor;
                
                if(paper>=1) p_expected = dp[rock][paper-1][scissor] + scissor*win_factor + rock*tie_factor;

                float maxi = max(s_expected, max(r_expected, p_expected));

                if(s_expected==maxi){
                    dp[rock][paper][scissor] = s_expected; strings_dp[rock][paper][scissor] = strings_dp[rock][paper][scissor-1]+"S";
                }
                else if(r_expected==maxi){
                    dp[rock][paper][scissor] = r_expected; strings_dp[rock][paper][scissor] = strings_dp[rock-1][paper][scissor]+"R";
                }
                else{
                    dp[rock][paper][scissor] = p_expected; strings_dp[rock][paper][scissor] = strings_dp[rock][paper-1][scissor]+"P";
                }
                // cout << "sum of r, p and s is " << rock + paper +scissor << endl;
                if(rock+paper+scissor == 60){
                    // cout << "answer = " << ans << " my val = " << dp[rock][paper][scissor] << endl;
                    if(dp[rock][paper][scissor] > ans){
                        ans = dp[rock][paper][scissor]; to_be_printed=strings_dp[rock][paper][scissor]; //debug(to_be_printed);
                    }
                }
            }
        }
    }
    return to_be_printed;
}
int32_t main(){
    int case_=0;
    
    int t; cin >> t;
    int expected_val;
    cin >> expected_val;
    while(t--){
        case_++;
        float w, e; cin >> w >> e ;
        string ans = ans_generator(w, e);
        // cout << ans.size() << endl;
        cout << "Case #" << case_ << ":" << space << ans << endl;
    }
}
