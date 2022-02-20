// ਹਰਅਸੀਸ ਸਿੰਘ
// had seen the tut before, not my solution :__:
// ignore virtual rank 
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
                int n, k; cin >> n >> k;

                if(k == n - 1){
                        if(n < 8){
                                cout << -1 << endl; continue;
                        }
                        cout << n - 2 << ' ' << n - 1 << endl;

                        cout << 0 << ' ' << 2 << endl;

                        cout << 1 << ' ' << n - 3 << endl;

                        for(int i = 3; i < n/2; i++){
                                cout << i << ' ' << n - i - 1 << endl;
                        }
                        continue;
                }

                for(int i = 1; i < n/2; i++){
                        if(i != k and i != n - k - 1){
                                cout << i << ' ' << n - i - 1 << endl;
                        }
                }
                cout << k << ' ' << n - 1 << endl;

                if(k){
                        cout << 0 << ' ' << n - k - 1 << endl;
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