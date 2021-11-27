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

                string s; cin >> s;

                vi blue(n), red(n);


                bool ok = 1;

                l(i, 0, n){
                        if(s[i] == 'B' and I[i] <= 0) ok = 0;

                        if(s[i] == 'R' and I[i] > n) ok = 0;
                }
                if(!ok){cout << "NO" << endl; continue;}

                l(i, 0, n){
                        if(s[i] == 'B') blue[min(I[i] - 1, n - 1)]++;
                        
                        else red[max(I[i] - 1, 0ll)]++;
                }
                int pt = 0;

                l(i, 0, n){
                        if(pt > i) {ok = 0; break;}

                        pt += blue[i];
                }

                int pt2 = n - 1;

                for(int i = n - 1; i >= 0; i--){
                        if(pt2 < i) {ok = 0; break;}

                        pt2 -= red[i];
                }

                cout << (ok ? "YES" : "NO") << endl;
    }

}
