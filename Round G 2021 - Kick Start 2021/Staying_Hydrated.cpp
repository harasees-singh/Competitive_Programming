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
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    int T; cin >> T;

    l(t, 1, T + 1){

                int k; cin >> k;

                vpii Ix;                       
                vpii Iy; 

                l(i, 0, k){

                        int xl, yl, xr, yr; cin >> xl >> yl >> xr >> yr;

                        Ix.push_back(make_pair(xl, 0)), Ix.push_back(make_pair(xr, 1));
                        
                        Iy.push_back(make_pair(yl, 0)), Iy.push_back(make_pair(yr, 1));
                }

                sort(all(Ix)), sort(all(Iy));

                int left = 0, right = k;

                int X = 0;

                while(right - left > 0){

                        int nxt = Ix[X].ff;

                        while(Ix[X].ff == nxt)
                                right -= !Ix[X].ss, left += Ix[X].ss, X++;
                }

                left = 0, right = k;

                int Y = 0;

                while(right - left > 0){

                        int nxt = Iy[Y].ff;

                        while(Iy[Y].ff == nxt)
                                right -= !Iy[Y].ss, left += Iy[Y].ss, Y++;
                }

                cout << "Case #" << t << ": " << Ix[X - 1].ff << space << Iy[Y - 1].ff << endl;
    }

}
