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

        int n = 2e5;

        // save 1, 2, 3 and 9 and n itself;

        w(t){
                cin >> n;
                vector<pii> ans;
                int cpy = n;
                if(n < 10){
                        for(int i = 3; i <= n - 1; i++){
                                ans.push_back(make_pair(i, i + 1));
                        }
                        while(n > 1){
                                ans.push_back(make_pair(cpy, 2));

                                n = (n + 1)/2;
                        }
                }       
                else{
                        for(int i = 4; i <= 8; i++) ans.push_back(make_pair(i, n));

                        for(int i = 10; i <= n - 1; i++) ans.push_back(make_pair(i, n));

                        while(n > 1){
                                n = (n + 8)/9;

                                ans.push_back(make_pair(cpy, 9));
                        }
                        ans.push_back({9, 3});
                        ans.push_back({9, 3});

                        ans.push_back({3, 2});
                        ans.push_back({3, 2});
                }
                assert(sz(ans) <= (cpy + 5));

                cout << sz(ans) << endl;

                for(auto p : ans) cout << p.ff << ' ' << p.ss << endl;
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