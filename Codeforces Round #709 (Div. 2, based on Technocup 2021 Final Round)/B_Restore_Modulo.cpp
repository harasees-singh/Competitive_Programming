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

            vi I(n); for(auto &p : I) cin >> p;

        //     if(n == 1){cout << 0 << endl; continue;}

            int pos = -1, neg = 1;

            bool ok = 1;

            l(i, 1, n){
                    int diff = I[i] - I[i - 1];
                    
                    if(diff > 0){
                            if(pos == -1) pos = diff;

                            else if(diff != pos) {ok = 0; break;}
                    }
                    else{
                            if(neg == 1) neg = diff;

                            else if(neg != diff) {ok = 0; break;}
                    }
            }
            if(ok and (neg == 1 or pos == -1)){
                    cout << 0 << endl; continue;
            }
            if(!ok){
                    cout << -1 << endl; continue;
            }
            int mod = pos + abs(neg);

            int cmodm = I[1] - I[0];

            int cur = I[0];

            l(i, 0, n){
                    if(cur%mod != I[i]){ok = 0; break;}

                    cur += cmodm + mod;
            }

            if(ok){
                    cout << mod << space << (cmodm + mod)%mod << endl;
            }
            else cout << -1 << endl;
    }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/