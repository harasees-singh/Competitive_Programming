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

mii id = {{4, 1}, {8, 2}, {15, 3}, {16, 4}, {23, 5}, {42, 6}};

int32_t main(){
        
        FIO

        int n; cin >> n;

        vector<vi> pos(7);

        for(int i = 0; i < n; i++){
                int t; cin >> t;

                pos[id[t]].pb(i);
        }
        vector<vi> rem(pos); for(auto &p : rem) for(auto &q : p) q = 0;

        // for(int i = 1; i<= 6; i++){
        //         vi p = pos[i];
        //         for(auto q : p) cout << q << ' '; cout <<endl;
        // }

        vi pt(7);

        for(int i = 0; i < 5e5 + 5; i++){
                int last = -infinity;
                for(int i = 1; i <= 6; i++){
                        while(pt[i] < sz(pos[i]) and pos[i][pt[i]] < last) rem[i][pt[i]] = 1, pt[i]++;

                        if(sz(pos[i]) == pt[i]){
                                break;
                        } 
                        else{
                                last = pos[i][pt[i]]; 

                                pt[i]++;
                        }
                }
        }

        int mn = infinity;

        for(int i = 1; i <= 6; i++){
                vi &p = rem[i];
                int cnt = count(all(p), 0ll);

                mn = min(mn, cnt);
        }

        cout << n - (mn * 6) << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/