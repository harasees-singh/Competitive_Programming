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

            int n, k; cin >> n >> k;

            vi S(2*k + 1);

            vi bothBIG(2*k + 1);
            vi bothSMALL(2*k + 1);

            vi I(n);
            
            for(auto &p : I)    cin >> p;

            l(i, 0, n/2){

                    int a, b;
                    a = I[i], b = I[n - i - 1];

                    S[a + b]++;

                    bothBIG[min(a, b)]++;
                    bothSMALL[max(a, b) + k]++;
            }
            for(int i = k - 1; i >= 1; i--){

                    bothBIG[i] += bothBIG[i + 1];
            }
            l(i, 1, 2*k + 1){
                    bothSMALL[i] += bothSMALL[i - 1];
            }
            int mini = infinity;

            l(i, 1, 2*k + 1){
                    
                    mini = min(n/2 - S[i] + bothBIG[i] + bothSMALL[i - 1], mini);
            }
            cout << mini << endl;
    }

}
