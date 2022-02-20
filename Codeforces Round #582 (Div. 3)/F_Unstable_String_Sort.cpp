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

int32_t main(){
        
        FIO

        int n, k; cin >> n >> k;

        vi P1(n), P2(n), color(n);

        for(auto &p : P1) cin >> p; for(auto &p : P2) cin >> p;

        vi pos(n + 1); 
        
        l(i, 0, n) pos[P2[i]] = i;

        int cnt = 0;

        int boundary = 0, seg = 0;

        int last_boundary = -1;

        l(i, 0, n){
                seg++; boundary = max(boundary, pos[P1[i]]);

                color[P1[i] - 1] = cnt;

                if(seg == boundary - last_boundary){
                        seg = 0; cnt++; last_boundary = boundary;
                }
        }
        if(cnt >= k){
                cout << "YES" << endl; 
                for(auto &c : color) cout << (char)(min(c, 25ll) + 'a');
        }
        else cout << "NO" << endl; 

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/