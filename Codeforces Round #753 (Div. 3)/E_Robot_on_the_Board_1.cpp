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
            int n, m; cin >> n >> m;

            string s; cin >> s;

            int x = 1, xmax = 0, move = 0;

            for(auto p : s){
                    if(p == 'L'){
                            move--;

                            if(x + move >= 1) continue;

                            if(x + xmax < m) x++;

                            else break;
                    }
                    else if(p == 'R'){
                            move++; xmax = max(xmax, move);

                            if(xmax + x > m) break;
                    }
            }
            int y = 1, ymax = 0; move = 0;

            for(auto p : s){
                    if(p == 'U'){
                            move--;

                            if(y + move >= 1) continue;

                            if(y + ymax < n) y++;

                            else break;
                    }
                    else if(p == 'D'){
                            move++, ymax = max(ymax, move);

                            if(ymax + y > n) break;
                    }
            }

            cout << y << space << x << endl;
    }

}
