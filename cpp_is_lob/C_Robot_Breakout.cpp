// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        (int)1e5
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
void print(pii p){
        cout << p.ff << ' ' << p.ss << endl;
}
bool bound(vi &plane, int id, int b){
        if(id == 0){
                if(b > plane[2]) return false;

                plane[0] = max(b, plane[0]);
        }
        if(id == 2){
                if(b < plane[0]) return false;

                plane[2] = min(plane[2], b);
        }
        if(id == 1){
                if(b < plane[3]) return false;
                plane[1] = min(plane[1], b);
        }
        if(id == 3){
                if(b > plane[1]) return false;

                plane[3] = max(plane[3], b);
        }
        return true;
}
int32_t main(){
        
        FIO

        // initially bounds are {-inf, +inf, +inf, -inf}

        // shrink this space accord to the constraints

        w(t){
                int n; cin >> n;

                vi plane = {-infinity, infinity, infinity, -infinity};

                vector<pii> grid(n);

                vector<vi> freedom(n, vi(4));

                vector<pii> freedom_id(n);

                l(i, 0, n){
                        int x, y; cin >> x >> y;

                        grid[i] = make_pair(x, y);

                        vi free(4); for(auto &p : free) cin >> p;

                        freedom[i] = free;

                        freedom_id[i] = make_pair(accumulate(all(free), 0ll), i);
                }

                bool ok = 1;

                for(auto p : freedom_id){
                        int id = p.ss;

                        bool left = freedom[id][0], up = freedom[id][1], right = freedom[id][2], down = freedom[id][3];
                        if(not left) ok = ok and bound(plane, 0, grid[id].ff);

                        if(not up) ok = ok and bound(plane, 1, grid[id].ss);

                        if(not right) ok = ok and bound(plane, 2, grid[id].ff);

                        if(not down) ok = ok and bound(plane, 3, grid[id].ss);

                }
                if(ok){
                        cout << 1 << ' ' << plane[0] << ' ' << plane[1] << endl;
                }
                else 
                        cout << 0 << endl;
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