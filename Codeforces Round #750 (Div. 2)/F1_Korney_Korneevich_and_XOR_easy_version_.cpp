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

    int i = 1;

    while((1 << i) < 500) i++;

    int n; cin >> n;

    vector<vi> F((1 << i), vi(n + 1, -1));

    F[0][0] = 0;

    l(i, 1, n + 1){
            int t; cin >> t;

            l(j, 0, F.size())

                F[j][i] = F[j][i - 1];

            l(j, 0, F.size())

                if(t > F[j][i - 1] and F[j][i - 1] != -1){

                    if(F[j xor t][i] == -1)

                            F[j xor t][i] = t;
                    
                    else 
                            
                            F[j xor t][i] = min(t, F[j xor t][i]);
                }
                
    }

    vi ans;

    l(i, 0, F.size())

        if(F[i][n] != -1)

            ans.push_back(i);
    
    cout << ans.size() << endl;

    for(auto p : ans)
            cout << p << space; cout << endl;
    
}
