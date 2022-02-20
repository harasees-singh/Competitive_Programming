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

        // abs(a - b) < 2;

        // a + b < n - 1;

        w(t){
                int n, a, b; cin >> n >> a >> b;

                if(abs(a - b) > 1 or a + b > n - 2){
                        cout << -1 << endl; continue;
                }
                vi perm(n);

                for(int i = 0; i < n; i++) perm[i] = i + 1;

                if(a >= b){
                        for(int i = 1; b; i+=2){
                                b--; a--;

                                swap(perm[i], perm[i + 1]);
                        }
                        if(a){
                                swap(perm[n - 1], perm[n - 2]);
                        }
                }
                else{
                        for(int i = 0; b; i += 2){
                                b--;

                                swap(perm[i], perm[i + 1]);
                        }
                }
                for(auto p : perm) cout << p << ' '; cout << endl;
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