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

int32_t main(){
        
        FIO

        w(t){
                int n, ll, r, s; cin >> n >> ll >> r >> s;

                vi vis(n + 1);

                vi ans(n + 1);

                l(i, ll, r + 1) ans[i] = i - ll + 1, vis[i - ll  + 1] = 1;

                int cnt = r - ll + 1;

                int cursum = (cnt*(cnt + 1))/2;

                int need = s - cursum;

                if(need < 0){
                        cout << -1 << endl; continue;
                }
                int delta = n - cnt;
                int id = r;
                while(need and id >= ll){
                        if(need > delta){
                                vis[ans[id]] = 0;
                                ans[id] += delta;
                                need -= delta;
                                
                        }
                        else{
                                vis[ans[id]] = 0;
                                ans[id] += need;
                                need = 0;
                        }
                        vis[ans[id]] = 1;
                        id--;
                }
                int pt = 1;
                if(need){
                        // cout << "hogya" << endl; cout.flush();
                        cout << -1 << endl; continue;
                }
                else{
                        
                        for(int i = 1; i <= n; i++){
                                while(pt <= n and ans[pt]) pt++;
                                if(!vis[i] and pt <= n) ans[pt] = i;
                        }
                }
                l(i, 1, n + 1) cout << ans[i] << ' '; cout << endl;

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