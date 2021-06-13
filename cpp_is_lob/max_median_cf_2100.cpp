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
#define debug(a) cout << "debug " <<a << endl;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
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
    int n, k; 
    cin >> n >> k;
    vi arr(1, 0);
    loop(i, 0, n){
        int t; cin >> t; arr.pb(t);
    }
    
    vi copy(arr);
    sort(all(copy));
    
    int ans=0;
    int left=1, right=n;
    while(left <= right){
        // cout << "left = " << left << " right " << right << endl;
        // choose a possible median;
        int mid_  = (right-left)/2 + left;
        vi processed_vector(1, 0);
        vi prefix_min(1, 0);
        int min_ = infinity;
        int sum=0;
        int mid = copy[mid_];
        // cout << "mid " << mid << endl;
        // 1 based indexing 
        loop(j, 1, n+1){
            arr[j]>=mid ? sum+=1:sum-=1; processed_vector.pb(sum);
            if(sum<min_){prefix_min.pb(sum);min_=sum;}
            else{prefix_min.pb(min_);}
        }
        // we have found a solution if for a given r processed_vector[r] - processed_vector[l-1] >= 0 and simultaneously r-l+1 >= k;
        // using prefix min this can be found out in linear time;
        // for every r from 1 to n both inclusive check if prefix min array has and index l such that the above condiiton is satisfied or not 
        // in other words prefix_min[r-k+1] <= processed_vector[r];
        bool parity=true;
        loop(r, k, n+1){
            int l = r-k;
            // cout << "prefix_min for " << l << space << prefix_min[l] << " processed_vector for r " << processed_vector[r] << endl;
            if(prefix_min[l] < processed_vector[r]){
                // found a median which is atleast = mid;
                left = mid_+1; ans = mid;
                parity=false; break;
            }
        }
        if(parity)right=mid_-1;
    }
    cout << ans << endl;
}