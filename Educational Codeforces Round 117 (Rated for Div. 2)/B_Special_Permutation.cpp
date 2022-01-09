// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
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
#define fps(x,y)                        fixed<<setprecision(y)<<x
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

        w(t){
                int n, a, b; cin >> n >> a >> b;

                // n ele, a min of first half, b max of second half;

                int done = 0;

                int todo = n/2 - 1;
                
                vi ans;

                for(int i = n; i >= 1; i--){
                        if(done == todo or i == a) break;

                        if(i == b) continue;

                        done++;

                        ans.pb(i);
                }
                ans.pb(a);

                done = 0;

                for(int i = 1; i <= n; i++){
                        if(done == todo or i == b) break;

                        if(i == a) continue;

                        done++;

                        ans.pb(i);
                }
                ans.pb(b);

                if(ans.size() == n){
                        for(auto p : ans) cout << p << space;
                }
                else 
                        cout << -1;
                        
                cout << endl;
        }       

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/