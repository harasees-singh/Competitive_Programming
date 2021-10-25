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

            vi I(n);

            for(auto &p : I)
                    cin >> p;
            
            // I.push_back(-1);
            
            vi top(n), bottom(n);

            for(auto &p : top)
                    cin >> p; 
            
            for(auto &p : bottom)
                    cin >> p;
            
            l(i, 0, n){
                    if(top[i] > bottom[i])
                            swap(top[i], bottom[i]);
            }
            
            int F[n] = {0};

            int a = 0, b = 0;

            for(int i = n - 2; i >= 0; i--){

                    if(a == b)
                            F[i] = I[i + 1] - 1 + 2 - top[i + 1] + bottom[i + 1];

                    else{
                            F[i] = max(I[i + 1] - 1 + 2 - top[i + 1] + bottom[i + 1], F[i + 1] + I[i + 1] - 1 - 2*(b - a) + 2 - top[i + 1] + bottom[i + 1]);
                    } 

                    a = top[i + 1], b = bottom[i + 1];
            }

            cout << *max_element(F, F + n) << endl;
    }

}
