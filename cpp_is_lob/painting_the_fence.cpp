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
    vi partition_frequency(n+2);
    vector<pii> input(q+1);
    int total=0;
    loop(i, 0, q){
        int l, r;
        cin >> l >> r;
        partition_frequency[l]++; partition_frequency[r+1]--;
        pii temp={l, r};  input[i+1]=temp;
    }
    int sum=0;
    vi prefix_1s(n+1);
    vi prefix_2s(n+1);
    int prefix_sums_1=0, prefix_sums_2=0;
    loop(i, 0, n+1){
        partition_frequency[i]=sum+partition_frequency[i]; sum=partition_frequency[i]; if(sum > 0){total++;}
        if(sum==1){
            prefix_sums_1++;
        }
        prefix_1s[i]=prefix_sums_1;
        if(sum==2){
            prefix_sums_2++;
        }
        
        prefix_2s[i]=prefix_sums_2;
    }
    
    // debug(prefix_1s[1]) debug(prefix_1s[2]) 
    int ans = infinity;
    loop(i, 1, q+1){
        loop(j, i+1, q+1){

            pii range1 = input[i], range2 = input[j];
            // cout << "input " << j << input[j].first << space << input[j].second << endl;
            // cout << "ranges " << range1.first << space << range1.second << space <<  range2.first << space << range2.second << endl;
            int loss = 0; 
            loss += (prefix_1s[range1.second]-prefix_1s[range1.first-1]);
            // cout << "loss 1s " << loss << endl;
            loss += (prefix_1s[range2.second]-prefix_1s[range2.first-1]);
            // cout << "i = " << i << " j = " << j << endl;
            // cout << "loss 1s + 2s " << loss << endl;
            
            pii common_range = {max(range1.first, range2.first), min(range1.second, range2.second)};
            loss += max(0, (int32_t)(prefix_2s[common_range.second]- prefix_2s[common_range.first-1]));
            // cout << "total loss " << loss << endl;
            if(loss < ans)ans=loss;
        }
    }
    cout << total - ans << endl;
}
    
   