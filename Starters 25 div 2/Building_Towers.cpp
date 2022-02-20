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
int x, m; 
bool good(int mid){
        // x height, mid towers possible or not
        int blocks = mid * x;

        // check overflow

        int cur = 0;

        while((1ll << cur) < blocks) cur++;

        // cur op to get req blocks

        int need = mid - 1 + cur + 1;

        // mid - 1 op to make towers

        return (need <= m);
}

int32_t main(){
        
        FIO

        w(t){
                cin >> x >> m;

                // int l = 0, r = 1e18/x;

                // while(l <= r){
                //         int mid = (l + r)/2;

                //         if(good(mid))
                //                 l = mid + 1;
                //         else 
                //                 r = mid - 1;
                // }
                // cout << r << endl;

                int cur = 0;

                while((1ll << cur) < x) cur++;

                // need cur + 1 op to get atleast x; 

                cout <<  max(0ll, m - cur - 1 + 1) << endl;
        }

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/