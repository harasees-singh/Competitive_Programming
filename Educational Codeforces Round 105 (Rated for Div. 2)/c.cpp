#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
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

    test_cases_loop{
            int n, m; cin >> n >> m;

            vi I1; vi m1; vi I2; vi m2;
            
            l(i, 0, n){
                    int t; cin >> t; 

                    if(t < 0) I2.pb(abs(t)); else I1.pb(t);
            }
            l(i, 0, m){
                    int t; cin >> t; 

                    if(t < 0) m2.pb(abs(t)); else m1.pb(t);
            }

            sort(all(I2)); sort(all(m2));

            m1.pb(infinity), m2.pb(infinity);

            int sp1 = 0, sp2 = 0;

            int p = 0;

            l(i, 0, sz(m1)){
                    while(p < sz(I1) and I1[p] < m1[i]) p++;

                    if(p == sz(I1)) break;

                    if(I1[p] == m1[i]) sp1++;
            }
            p = 0;
            l(i, 0, sz(m2)){
                    while(p < sz(I2) and I2[p] < m2[i]) p++;

                    if(p == sz(I2)) break;

                    if(I2[p] == m2[i]) sp2++;
            }


            int len = 1;

            int Mex1 = sp1, Mex2 = sp2;

            l(i, 0, sz(I1)){
                    
                    int id = lower_bound(all(m1), I1[i]) - m1.begin(); 

                    if(m1[id] == I1[i]){
                            sp1--;
                    }

                    Mex1 = max(Mex1, sp1 + (int)(upper_bound(all(m1), I1[i]) - lower_bound(all(m1), I1[i] - len + 1)));

                    len++;
            cout << "YES" << endl; cout.flush();
            }
            p = 0;
            while(p < sz(m1) and sz(I1) and m1[p] <= I1[I1.size() - 1]) p++;

            l(i, p, sz(m1)){
                    Mex1 = max(Mex1, sp1 + (int)(upper_bound(all(m1), m1[i]) - lower_bound(all(m1), m1[i] - len + 1)));
            }

            len = 1;

            l(i, 0, sz(m2)){
                    
                    int id = lower_bound(all(m2), I2[i]) - m2.begin(); 

                    if(m2[id] == I2[i]){
                            sp2--;
                    }

                    Mex2 = max(Mex2, sp2 + (int)(upper_bound(all(m2), I2[i]) - lower_bound(all(m2), I2[i] - len + 1)));

                    len++;
            }
            p = 0;
            while(p < sz(m2) and sz(I2) and m2[p] <= I2[I2.size() - 1]) p++;

            l(i, p, sz(m2)){
                    Mex1 = max(Mex2, sp2 + (int)(upper_bound(all(m2), m2[i]) - lower_bound(all(m2), m2[i] - len + 1)));
            }

            cout << Mex1 + Mex2 << endl;

    }

    return 0;
}
