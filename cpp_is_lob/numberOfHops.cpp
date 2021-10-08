#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x


const int n = 1e6;

int T[4*n];

void build(vi &a, int v, int tl, int tr){
    // v being the current tree node number.
    // tl and tr being the left and right boundaries of indices that node v will store the answer to
    if(tl == tr)
            T[v] = a[tl];
    
    else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);

            T[v] = min(T[v*2], T[v*2 + 1]);
    }
}

int QuerySum(int v, int tl, int tr, int l, int r){

        if(tl >= l and tr <= r) 
                return T[v];
        if(tr < l or tl > r)
                return INT32_MAX;
                
        int mid = (tl + tr)/2;

        return min(QuerySum(2*v, tl, mid, l, r), QuerySum(2*v + 1, mid + 1, tr, l, r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) 
                T[v] = new_val;

        else{
                int tm = (tl + tr) / 2;

                if (pos <= tm)
                        update(v*2, tl, tm, pos, new_val);
                else
                        update(v*2+1, tm+1, tr, pos, new_val);
                        
                T[v] = min(T[v*2], T[v*2+1]);
        }
}

int min(int a, int b){

        return (a < b ? a : b);
}

int solve(vector<int>& nums) {

    if(nums.size() == 1)
            return 0;
    vector<int> dp(nums.size() + 1); // 1 based indexing for segment tree;

    build(dp, 1, 1, nums.size());

    for(int i = nums.size() - 2; i >= 0; i--){

            int hop = nums[i];

            int end = min(nums.size(), i + hop + 1);

            dp[i + 1] = 1 + QuerySum(1, 1, nums.size(), i + 2, end);

            update(1, 1, nums.size(), i + 1, dp[i + 1]);
    }    

    return dp[1];
}
MOD_DEFINE

int32_t main(){
    FIO 

    vi curr = {2, 0, 0};

    cout << solve(curr) << endl;

    return 0;
}
