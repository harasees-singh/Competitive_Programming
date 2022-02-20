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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

// x row
// y column

vector<pii> ans;

pii fill(int p, int x, int y){
        ans.push_back({x, y});
        for(int i = 0; i < p; i++){
                ans.push_back({x, y + 1});

                ans.push_back({x, y + 2});
                ans.push_back({x, y + 3});

                ans.push_back({x - 1, y + 2});
                ans.push_back({x + 1, y + 2});
                
                ans.push_back({x - 1, y + 3});
                ans.push_back({x + 1, y + 3});

                y = y + 3;
        }       
        ans.push_back({x, ++y});
        ans.push_back({x, ++y});
        return make_pair(x, y);
}

void join(pii a, pii b){
        
        ans.push_back({++a.ff, a.ss});
        ans.push_back({++a.ff, a.ss});
        ans.push_back({++a.ff, a.ss});
        ans.push_back({++b.ff, b.ss});
        ans.push_back({++b.ff, b.ss});
        ans.push_back({++b.ff, b.ss});

        while(++a.ss != b.ss) ans.push_back(a); 
}

void surround(pii a){
        l(i, a.ff - 2, a.ff + 1){
                l(j, a.ss - 2, a.ss + 1){
                        if((i == a.ff and j == a.ss) or (i == a.ff - 1 and j == a.ss - 1)) continue;
                                
                        ans.push_back({i, j});
                }
        }
}

int32_t main(){
        
        FIO

        int n; cin >> n;

        auto ret = fill(n/2, 0, 0);

        join({0, 0}, ret);

        if(n&1){
                surround({0, 0});
        }

        int mini = 0;

        for(auto p : ans) mini = min(mini, p.ss);

        for(auto &p : ans) p.ss += abs(mini);

        mini = 0;

        for(auto p : ans) mini = min(mini, p.ff);

        for(auto &p : ans) p.ff += abs(mini);

        cout << sz(ans) << endl;

        for(auto p : ans) cout << p.ff << ' ' << p.ss << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/