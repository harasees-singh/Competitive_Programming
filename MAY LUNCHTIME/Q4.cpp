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
void kadane(vector<vi> &mat){
    int curr_sum = 0;
    bool start = true;
    loop(i, 0, mat.size()){
        int ele = mat[i][1];
        // cout << "working on it " << endl;
        if(start){if(ele > 0){start=false;curr_sum=ele;}mat[i][1]=ele;continue;}        // [-1, -2, 3, 4, 5, -660, -1, -2, 3, 4, 5,]
        if(curr_sum+ele > 0)mat[i][1] = curr_sum+ele, curr_sum+=ele; 
        else{mat[i][1]=curr_sum+ele; curr_sum=0; start=true;}
    }
}
void solve(int n, int k, vi &a){
    
    vi dp(k+1);
    dp[1] = a[0]; 
    loop(i, 2, k+1){
        dp[i] = -infinity;
    }
    
    vector<vi> mat(n, vi(k+1, 0));
    loop(i, 0, sz(a)){mat[i][1]=a[i];}
    kadane(mat);                // now we have the entire first column filled 
    loop(i, 2, k+1){mat[0][i]=-infinity;}
    
    loop(i, 1, n){
        loop(j, 2, k+1){
            int j_new_contiguous_block_max = -infinity;
            int to_be_fitted = max(dp[j-1], mat[i-1][j-1]);
            j_new_contiguous_block_max = to_be_fitted;
            dp[j-1]=to_be_fitted;
            
            j_new_contiguous_block_max += j*a[i];

            int j_same_contiguous_block_max = mat[i-1][j] + j*a[i];

            mat[i][j] = max(j_new_contiguous_block_max, j_same_contiguous_block_max);
        }
    }
    int ans=-infinity;
    loop(i, 0, n){
        mat[i][k] > ans ? ans = mat[i][k] : ans = ans;
    }
    cout << ans << endl;
}
int32_t main(){
    FIO
    test_cases_loop{
        int n, k ; cin >> n >> k; vi a; loop(i, 0, n){int temp; cin >> temp; a.pb(temp);}       // input 
        solve(n, k, a);
    }
    return 0;
}

