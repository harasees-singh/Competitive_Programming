// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE
int H;
int n;
vi in;
int decrease;
int mn = infinity;

bool good(int mid){
        int rem = H + decrease * mid;
        
        int cnt = mid * n;

        if(rem <= 0){mn = min(mn, cnt); return true;}

        l(i, 0, n){
                cnt++;

                rem += in[i];

                if(rem <= 0) {mn = min(mn, cnt); break;}
        }
        return (rem <= 0);
}

int32_t main(){
        
        FIO

        cin >> H >> n;

        in = vi(n);

        for(auto &p : in) cin >> p;

        decrease = accumulate(all(in), 0ll);

        int beg = 0, end = 1e13;
        if(decrease >= 0) end = 0;
        else end = H/abs(decrease) + 1e5;
        
        while(beg <= end){
                int mid = (beg + end)/2;

                if(good(mid)) end = mid - 1;

                else beg = mid + 1;
        }
        // int rem = H + decrease*beg;
        // int cnt = beg*n;
        // l(i, 0, n){
        //         if(rem <= 0) {mn = min(mn, cnt); break;}

        //         cnt++;

        //         rem += in[i];

        // }
        cout << (mn == infinity ? -1 : mn) << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/