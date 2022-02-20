// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
// #define ff                              first
// #define ss                              second
// #define infinity                        8999999999999999999
// #define sz(v)                           ((int)(v).size())
// #define all(v)                          (v).begin(),(v).end()
// #define MOD_DEFINE                      const int MOD = 1e9 + 7;
// #define endl                            '\n'
// #define int                             long long
// #define pii                             pair<int, int>
// #define vi                              vector<int>
// #define pb(n)                           push_back((n))
// #define mii                             map<int, int>
// #define umii                            unordered_map<int, int>
// #define w(t)                            int t; cin >> t; while(t--)
// #define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define l(var, initial, final)          for(int var=initial; var < final; var++)
// #define cout                            std::cout
// #define cin                             std::cin
// #define pqb                             priority_queue<int>
// #define pqs                             priority_queue<int, vi, greater<int>>
// #define fps(x, y)                       fixed<<setprecision(y)<<x
// typedef long long ll;
// typedef vector<pii> vpii;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// MOD_DEFINE
int x1,Y, x2,y2, x3,y3, x4,y4, x5,y5, x6,y6;
bool cover(int xl, int yl, int xr, int yr){
        // does this cover x1 Y x2 y2 or not 

        return (xl <= x1 and yl <= Y and xr >= x2 and yr >= y2);
}

int32_t main(){
        
        // FIO

        cin >> x1 >> Y >> x2 >> y2;

        cin >> x3 >> y3 >> x4 >> y4;

        cin >> x5 >> y5 >> x6 >> y6;

        if(cover(x3, y3, x4, y4) or cover(x5, y5, x6, y6)){
                cout << "NO" << endl; return 0;
        }

        if(x3 <= x1 and x4 >= x2){
                // clip from above
                if(y3 <= y2 and y4 >= y2){
                        int t = y2;
                        y2 = y3;

                        if(cover(x5, y5, x6, y6)){
                                cout << "NO" << endl; return 0;
                        }
                        y2 = t;
                }
                // clip down
                if(y3 <= Y and y4 >= Y){
                        int t = Y;
                        Y = y4;

                        if(cover(x5, y5, x6, y6)){
                                cout << "NO" << endl; return 0;
                        }
                        Y = t;
                }
        }     
        if(y3 <= Y and y4 >= y2){
                // clip from right
                if(x3 <= x2 and x4 >= x2){
                        int t = x2;
                        x2 = x3;

                        if(cover(x5, y5, x6, y6)){
                                cout << "NO" << endl; return 0;
                        }
                        x2 = t;
                }
                // clip down
                if(x3 <= x1 and x4 >= x1){
                        int t = x1;
                        x1 = x4;

                        if(cover(x5, y5, x6, y6)){
                                cout << "NO" << endl; return 0;
                        }
                        x1 = t;
                }
        }       
        cout << "YES";

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/