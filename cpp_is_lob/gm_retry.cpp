// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
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

MOD_DEFINE

int32_t main(){
        FIO 

        w(t){
                int n; cin >> n;

                vector<pii> a(n), b(n);

                vi aa(n), bb(n);

                l(i, 0, n){
                        int t; cin >> t; a[i] = make_pair(t, i);
                        aa[i] = t;

                }
                l(i, 0, n){
                        int t; cin >> t; b[i] = make_pair(t, i);
                        bb[i] = t;

                }
                sort(a.rbegin(), a.rend());
                sort(b.rbegin(), b.rend());

                string ans(n, '0');

                ans[a[0].ss] = '1'; ans[b[0].ss] = '1';

                int A = aa[b[0].ss], B = bb[a[0].ss];

                for(int i = 1; i < n; i++){
                        if(a[i].ff > A){
                                B = min(B, bb[a[i].ss]);
                        }
                        if(b[i].ff > B){
                                A = min(A, aa[b[i].ss]);
                        }
                        if(a[i].ff > A){
                                ans[a[i].ss] = '1';
                        }
                        if(b[i].ff > B){
                                ans[b[i].ss] = '1';
                        }
                }
                cout << ans << endl;
        }       

        return 0;
}
