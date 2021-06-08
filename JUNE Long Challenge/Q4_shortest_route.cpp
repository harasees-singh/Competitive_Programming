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
int32_t main(){
    FIO
    test_cases_loop{
        int n, m;
        cin >> n >> m;
        vi stations;
        loop(i, 0, n){
            int temp; cin >> temp; stations.pb(temp);
        }
        vi right_direction_preprocessing(n);
        vi left_direction_preprocessing(n);
        int sum=infinity;
        loop(i, 0, n){
            int curr = stations[i];
            if(curr==1)right_direction_preprocessing[i]=0, sum=0;
            else{
                if(sum==infinity)sum-=1;
                right_direction_preprocessing[i]=sum+1; sum++;
            }
        }
        sum=infinity;
        for(int i=n-1; i>=0; i--){
            int curr = stations[i];
            if(curr==2)left_direction_preprocessing[i]=0, sum=0;
            else{
                if(sum==infinity)sum-=1;
                left_direction_preprocessing[i]=sum+1; sum++;
            }
        }
        loop(i, 0, m){
            int uknowwhat; cin >> uknowwhat;
            if(uknowwhat==1){cout << 0 << space; continue;}
            int print;
            min(left_direction_preprocessing[uknowwhat-1], right_direction_preprocessing[uknowwhat-1]) == infinity ? print = -1: print = min(left_direction_preprocessing[uknowwhat-1], right_direction_preprocessing[uknowwhat-1]);
            cout << print << space;
        }
        cout << endl;
    }
}

