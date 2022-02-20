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
// 2, 3, 4, 5, 7
// coins = 6, k = 2;

// start buying in pairs : {2, 3}, can only buy 2 
// start buying in pairs starting from odd index : {3, 4} can buy 1 pair plus a single 2 so tot 3
// will never buy 2 single entitites coz could club them to reduce cost
// so 1 single + pairs or all pairs, plus can pick pairs greedily from start
// only the first element can be picked without pairing in case we pick one

int32_t main(){
        
        FIO

        w(t){
                int n, p, k; cin >> n >> p >> k;

                vi in(n); for(auto &h : in) cin >> h;

                sort(all(in));

                int cost = 0;

                int mx1 = 0;

                for(int i = 1; i < n; i += 2) if(cost + in[i] <= p) mx1 += 2, cost += in[i];

                int mx2 = (p >= in[0]);

                cost = in[0];

                for(int i = 2; i < n; i += 2) if(cost + in[i] <= p) mx2 += 2, cost += in[i];

                cout << max(mx1, mx2) << endl;

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