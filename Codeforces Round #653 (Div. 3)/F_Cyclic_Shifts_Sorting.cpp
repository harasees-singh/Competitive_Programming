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

            vi I(n);

            for(auto &p : I) cin >> p;

            vi cpy(I);

            sort(all(cpy));
            int pt = n;

            vi ans;

            // int limit = 500;

            // int lcnt = 0;

            bool ok = 1;

            while(pt > 0){
                    // auto shift = max_element(I.begin(), I.begin() + pt);

                    int shift = -1;

                    int maxi = 0;

                    l(i, 0, pt) if(I[i] >= maxi) maxi = I[i], shift = i;

                    if(shift + 1 == pt)
                            pt--;
                    
                    else{
                            int idx = shift;

                            if(idx + 2 >= pt){

                                    // 1 3 2 4 5

                                    // shift 3

                                    if(idx - 1 < 0){
                                            ok = 0; break;
                                    }

                                    ans.pb(idx);

                                    int t = I[idx + 1];

                                    I[idx + 1] = I[idx];

                                    I[idx] = I[idx - 1];

                                    I[idx - 1] = t;
                            }

                            else{
                                    // 1 3 2 1 5

                                    int t = I[idx + 2];

                                    I[idx + 2] = I[idx + 1];

                                    I[idx + 1] = I[idx];

                                    I[idx] = t;

                                    ans.pb(idx + 1);
                            }
                    }   

                    // lcnt++;
                    // if(lcnt > 500)
                    //     if(cpy == I) break;
                    for(auto p : I)
                            cout << p << space; cout << endl; cout.flush();
            }

            if(ok){
                    cout << sz(ans) << endl; for(auto p : ans) cout << p << space; cout << endl;
            }
            else cout << -1 << endl;
    }

}
