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

void solve(){
        int n; cin >> n; 
        
        vi in(2 * n);

        for(auto &p : in) cin >> p;

        multiset<int> have, cpy; for(auto p : in) cpy.insert(p);
        for(auto remove : in){
                have = cpy;
                vector<pii> store;
                int x = *prev(have.end()) + remove, y;
                y = x;
                l(i, 0, n){
                        // we want the sum to be x;

                        int big = *prev(have.end());

                        int need = x - big;
                        have.erase(have.find(big));

                        if(have.count(need) == 0) break;

                        have.erase(have.find(need));


                        store.push_back(make_pair(need, big));

                        x = big;
                }
                if(sz(store) == n){
                        cout << "YES" << endl;

                        cout << y << endl; 

                        for(auto &p : store) cout << p.ff << ' ' << p.ss << endl;

                        return;
                }
        }
        cout << "NO" << endl; return;
}

int32_t main(){
        
        FIO

        w(t){
                solve();
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