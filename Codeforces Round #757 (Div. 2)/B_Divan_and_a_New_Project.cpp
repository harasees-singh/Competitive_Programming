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
                int n; cin >> n;

                vpii visit(n);

                l(i, 0, n){
                        pii t;
                        int p; cin >> p;

                        t.ff = p; t.ss = i;

                        visit[i] = t;
                }

                sort(all(visit));

                reverse(all(visit));

                vi ans(n);

                int cur = 1;
                // bool parity = 1;
                int cursum = 0;

                l(i, 0, n){
                        int id = visit[i].ss;

                        int mul = visit[i].ff;

                        cursum += 2*abs(cur)*mul;

                        ans[id] = cur;

                        if(cur > 0) 
                        
                                cur = -cur;

                        else 
                                cur = (-cur) + 1;
                }
                cout << cursum << endl;
                cout << 0 << space; 
                for(auto p : ans) cout << p << space; cout << endl;
        }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/