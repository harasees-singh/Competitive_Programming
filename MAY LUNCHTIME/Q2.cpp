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
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

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
    FIO
    test_cases_loop{
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int init_dist=0;
        vi list;
        for(int i=0; i<s.size(); i++){
            char curr = s[i];
            curr == '0' ? list.pb(0) :list.pb(1);
        }
        int curr_list = list[0];
        loop(j, 1, list.size()){
            curr_list^list[j]? init_dist+=1:init_dist+=2;
            curr_list = list[j];
        }
        // cout << "curr " << init_dist << endl;
        loop(j, 0, k){
            int temp;
            cin >> temp;
            temp--;
            int ele = list[temp];
            if(temp<sz(list)-1 And temp){
                int first = ele^list[temp+1];
                int second = ele^list[temp-1];
                first ? init_dist+=1:init_dist-=1;
                second? init_dist+=1:init_dist-=1;
                // cout << "if";
            }
            else if(temp==0 And sz(list)>1){
                int first = ele^list[temp+1];
                // int second = ele^list[temp-1];
                first ? init_dist+=1:init_dist-=1;
                // second? init_dist+=1:init_dist-=1;
                // cout << "1";
            }
            else if(temp+1==sz(list) And sz(list)>1){
                // int first = ele^list[temp+1];
                int second = ele^list[temp-1];
                // first ? init_dist+=1:init_dist-=1;
                second? init_dist+=1:init_dist-=1;
                // cout << '2';
            }
            list[temp]=list[temp]^1;
            cout << init_dist << endl;
        }
        

    }
}

