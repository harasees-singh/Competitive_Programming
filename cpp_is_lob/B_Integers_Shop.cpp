// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        99999999999999999
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

        w(t){
                set<vi> seg;

                // {l, r, c}

                int n; cin >> n;

                pii L = {infinity, infinity}, R = {-infinity, -infinity};
                int lcost = infinity, rcost = infinity;

                for(int i = 0; i < n; i++){
                        int l, r, c; cin >> l >> r >> c;

                        if(l <= L.ff and r >= R.ss){
                                if(l == L.ff and r == R.ss){
                                        // same seg 
                                        if(c < lcost + rcost){
                                                L = {l, r}; lcost = c; 
                                                R = {r, r}; rcost = 0;
                                        }
                                }
                                else{
                                        L = {l, r}; lcost = c;
                                        R = {r, r}; rcost = 0;
                                }
                        }
                        else{
                                if(l > L.ff and r < R.ss);

                                else if(r == R.ss) rcost = min(rcost, c);
                                else if(l == L.ff and rcost) lcost = min(lcost, c);

                                else if(r > R.ss){
                                        R = {l, r};
                                        rcost = c;
                                }
                                else if(l < L.ff){
                                        // check if pseudo seg or not
                                        if(rcost == 0){
                                                // pseudo seg
                                                R = L;
                                                L = {l, r};
                                                rcost = lcost;
                                                lcost = c;
                                        }
                                        else{
                                                L = {l, r};
                                                lcost = c;
                                        }
                                }
                        }
                        cout << lcost + rcost << endl;
                }
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