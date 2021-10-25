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

    w(t){

        int n; cin >> n;

        vector<vi> I(n, vi(5));

        l(i, 0, n){

                l(j, 0, 5)
                        cin >> I[i][j];
        }
        bool ok = 0;

        l(i, 0, 5){

                l(j, i + 1, 5){

                        int common = 0, icnt = 0, jcnt = 0;

                        l(r, 0, n){

                                if(I[r][i] == 1 and I[r][j] == 1)
                                        common++;
                                else if(I[r][i] == 1)
                                        icnt++;
                                else if(I[r][j] == 1)
                                        jcnt++;

                        }

                        int x = max(0ll, n/2 - icnt);

                        if(common >= x)
                                common -= x;
                        else 
                                continue;
                        
                        int y = max(0ll, (n/2 - jcnt));
                        
                        if(common >= y)
                                ok = 1;
                }   
        }

        cout << (ok ? "YES": "NO") << endl;
    }

}
