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
            
            int pt = n - 1;

            set<int> F;

            l(i, 1, n + 1)
                    F.insert(i);

            while(pt >= 0){
                    vi p;
                    int f = *prev(F.end());
                    while(pt >= 0 and I[pt] != f){
                            
                            F.erase(I[pt]);
                            p.push_back(I[pt]);
                            pt--;
                    }
                    pt--;
                    reverse(all(p));
                    F.erase(f);
                    cout << f << space;

                    for(auto q : p)
                            cout << q << space;
            }

            cout << endl;
    }

}