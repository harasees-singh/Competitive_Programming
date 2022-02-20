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

        w(t){
                int n; cin >> n;

                vi dp(n + 1); // dp[i] stores the number of changes made in order to obtain a permutation {0, 1, ...i - 1}

                vi f(n + 1);

                l(i, 0, n){
                        int t; cin >> t; f[t]++;
                }
                vi have; // have stores our inventory of 'smaller' numbers which we may increment in case i - 1 is not available while we try to make i the mex

                // int it = 0; // iterator over have

                cout << f[0] << ' '; // trivial if mex needs to be zero;

                l(i, 0, f[0] - 1) have.pb(0); bool ok = 1;

                for(int mex = 1; mex <= n; mex++){
                        if(!ok){
                                cout << -1 << ' '; continue;
                        }
                        dp[mex] = dp[mex - 1];

                        if(f[mex - 1]){

                                cout << dp[mex] + f[mex] << ' '; 
                        }
                        else{
                                if(sz(have)){
                                        dp[mex] += mex - 1 - have.back(), have.pop_back();

                                        cout << dp[mex] + f[mex] << ' ';
                                }
                                else cout << -1 << ' ', ok = 0;
                        }
                        l(i, 0, f[mex] - 1) have.pb(mex);
                }
                cout << endl;
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