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

            umii f;

            int potent = 0;

            l(i, 0, n){
                    cin >> I[i];

                    f[I[i]]++;

                    potent = max(potent, f[I[i]]);
            }

            int ans = 1;
            
            l(i, 1, 27){

                    l(j, 1, 27){
                            if(i==j)
                                continue;

                            int pt1 = 0, pt2 = n - 1;

                            int jcnt = f[j];

                            int icnt = 0;

                            while(pt1 < pt2){
                                    if(I[pt1] == j)
                                            jcnt--;

                                    if(I[pt1] == i){
                                            icnt++;
                                            while(pt1 < pt2 and I[pt2] != i){
                                                    if(I[pt2] == j)
                                                        jcnt--;
                                                    pt2--;
                                            }
                                            
                                            if(pt1 < pt2 and I[pt2] == i)
                                                    ans = max(2*icnt + jcnt, ans), pt2--;
                                            
                                    }
                                    pt1++;
                            }
                    }
            }

            cout << max(ans, potent) << endl;
    }

}
