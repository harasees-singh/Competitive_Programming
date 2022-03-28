// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
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

MOD_DEFINE

void solve(int n, int k){

        if(k * (k - 1) < n){
                // cout << "NO" << endl;

        }
        // cout << "YES" << endl;
        int cnt = 0;
        vector<pii> store = {{0, 0}};
        for(int i = 1; i <= k and cnt < n; i++){
                for(int j = i + 1; j <= k; j++){
                        pii t = store.back();

                        assert(t.ff != i and t.ss != j);
                        // cout << i << ' ' << j << endl; 

                        cnt++;

                        if(cnt == n) break;
                        store.push_back({j, i});

                        cnt++;

                        // cout << j << ' ' << i << endl;
                }
        }
}

int32_t main(){
        FIO

        for(int n = 2; n < 1000; n++){
                for(int k = 2; k < n; k++){
                        solve(n, k);
                }
        }
        cout << "Stress testing successful" << endl;

        return 0;
}
