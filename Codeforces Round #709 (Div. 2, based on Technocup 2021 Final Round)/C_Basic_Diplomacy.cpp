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

            vi f(n + 1);

            vector<vi> mat;

            l(i, 0, m){
                    int q; cin >> q;

                    int t; 
					vi T;
					l(i, 0, q){
						cin >> t;
						T.pb(t);
					}
                    if(q == 1) f[t]++;
					mat.pb(T);
                    
            }
            vi ans(m);

            bool ok = 1;

            for(auto p : f) ok = ok and (p <= (m + 1)/2);

            if(ok){
                    cout << "YES" << endl;

					l(i, 0, m) ans[i] = mat[i][0];

					mii F;

					for(auto p : ans) F[p]++;

					int remove = -1;
					int todo = 0;

					for(auto p : F) if(p.ss > (m + 1)/2) {remove = p.ff; todo = p.ss - (m + 1)/2; break;}

					l(i, 0, m){
							if(!todo) break;
							if(ans[i] == remove and sz(mat[i]) > 1) ans[i] = mat[i][sz(mat[i]) - 1], todo--;
					}

					for(auto p : ans) cout << p << ' ';

					cout << endl;
                    
            }
            else cout << "NO" << endl;
    }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/