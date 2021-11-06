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

            mii f;

            l(i, 0, n){
                    int t; cin >> t;

                    int j = 0;

                    while((1ll << j) <= t){
                            if(t&(1ll << j))
                                    f[j]++; 
                        j++;
                    }
            }

            if(!f.size()){
                    l(i, 1, n + 1)
                            cout << i << space; cout << endl; continue;
            }

            int gcd = (*f.begin()).ss;

            for(auto p : f)
                    gcd = __gcd(gcd, p.ss);

            vi div;

            for(int i = 1; i <= sqrt(gcd); i++){
                    if(gcd%i == 0){
                            if(i == sqrt(gcd))
                                    div.pb(i);
                            else    

                                    div.pb(i), div.pb(gcd/i);
                    }
            }
            sort(all(div));

            // cout << sz(div) << endl;

            for(auto p : div)
                    cout <<  p << space; cout << endl;
    }

}
