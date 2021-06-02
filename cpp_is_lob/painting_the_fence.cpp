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
#define infinity 8999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define debug(a) cout << a << endl;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define pii pair<int, int>
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
int32_t main(){
    FIO
    int n, q;
    cin >> n >> q ;
    map<int, int> painter_sole_responsibility;
    map<pair<int, int>, int> couple_sole_responsibility;
    map<int, vi> partition_painter_involved;
    int total=0;
    loop(i, 0, q){
        int l, r;
        cin >> l >> r;
        for(int j=l; j<=r; j++){
            if(!sz(partition_painter_involved[j])){total++;}
            if(partition_painter_involved[j].size() <= 2) partition_painter_involved[j].pb(i+1);
            
        }
    }
    for(auto a:partition_painter_involved){
        int partition = a.first; vi &painters = a.second;
        if(sz(painters)==1){painter_sole_responsibility[painters[0]]++;}
        if(sz(painters)==2){
            int small=min(painters[0], painters[1]), large=max(painters[0], painters[1]);
            // painters[0] < painters[1] ? small = painters[0], large = painters[1] : large = painters[0], small=painters[1];

            // cout << "small " << painters[0] << " large " << painters[1] << endl;
            couple_sole_responsibility[{small, large}]++;
        }
    }
    // cout << "debug " <<couple_sole_responsibility[{2, 3}] << endl;
    // cout << partition_painter_involved[2][1] << endl;
    int ans = infinity;
    loop(i, 1, q+1){
        loop(j, i+1, q+1){
            pii couple = {i, j};
            int parity = couple_sole_responsibility[couple] + painter_sole_responsibility[i] + painter_sole_responsibility[j];
            if(parity < ans)ans=parity;
        }
    }
    cout << total - ans << endl;
}