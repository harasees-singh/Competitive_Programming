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
    int n; cin >>n;
    mii occurances;
    mii indices;                    // STORES THE INDEX OF FIRST OCCURANCE;
    mii arithmetic_difference; int index=0;
    mii last_occurance;
    int copy=n;
    vi lol;
    while (n--)
    {
        int temp; cin >> temp; lol.pb(temp);
        occurances[temp]++; if(occurances[temp]==1)indices[temp]=index;
        if(occurances[temp]==2){arithmetic_difference[temp]=index-indices[temp];}
        index++;
    }
    for(int i=sz(lol)-1; i>=0; i--){if(!last_occurance[lol[i]]) last_occurance[lol[i]] = i;}
    // cout << "debug " << arithmetic_difference[1] << indices[1] << occurances[1] <<endl;
    vector<pii> answer;
    for(auto p:occurances){
        int num = p.first, occurance_count = p.second;
        if(!arithmetic_difference[num]){answer.push_back({num, 0}); continue;}
        if(ceil((last_occurance[num]-indices[num] + 1.00)/arithmetic_difference[num]) == occurance_count){
            bool parity=true;
            int i=indices[num], difference = arithmetic_difference[num], limit = last_occurance[num];
            while(i<= limit){
                if(lol[i]!=num){parity=false; break;}
                i += difference;
            }
            if(parity)answer.push_back({num, difference});
        }
    }
    cout << sz(answer) << endl;
    for(auto a: answer) cout << a.first << space << a.second << endl;
}