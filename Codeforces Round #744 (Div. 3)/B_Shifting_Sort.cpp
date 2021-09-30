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
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    test_cases_loop{
        int n; cin >> n;

        vi I(n);

        // implement 

        l(i, 0, n)
                cin >> I[i];

        vector<vi> ans;

        l(i, 0, n){

            // place the right element at i;
            int mini = I[i];
            int ind = i;
            l(j, i, n){
                    if(I[j] < mini)
                            mini = I[j], ind = j;
                
            }

            if(i != ind){
                    vi t;
                    int rotate = ind - i;
                    t.pb(i + 1), t.pb(ind + 1), t.pb(rotate);
                    ans.pb(t);
                    // cout << i + 1 << space << ind + 1 << space << rotate << endl;
                    

                    int temp = I[i];
                    I[i] = I[ind];
                    for(int k = i + 1; k < ind + 1; k++){
                        int t;
                        t = I[k];
                        I[k] = temp;
                        temp = t;
                        // I[k] = I[k - 1];
                    }
                    // I[ind] = temp;


                    // for(auto p : I)
                    //     cout << p <<space; cout << endl;
            }
        }
        cout << sz(ans) << endl;

        

        for(auto p : ans){
            cout << p[0] << space << p[1] << space << p[2] << endl;
        }
    }

}
