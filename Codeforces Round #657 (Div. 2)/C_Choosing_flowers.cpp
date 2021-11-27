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

            vpii I; 

            vi primFlower(m);

            
            l(i, 0, m){
                    int a, b; cin >> a >> b;

                    primFlower[i] = a;

                    I.pb(make_pair(a, b));
            }
            sort(all(primFlower));

            vi suff(m);

			suff[m - 1] = primFlower[m - 1];

            for(int i = m - 2; i >= 0; i--){
                    suff[i] = suff[i + 1] + primFlower[i];
            }

            int ans = suff[max(0ll, m - n)];

            l(i, 0, m){
                int a = I[i].ff, b = I[i].ss;

                int summ = a + (n - 1)*b;

                int idx = (lower_bound(all(primFlower), b) - primFlower.begin());

                int remove = m - idx;
                if(remove > n - 1){
                    remove = n - 1; idx = m - (n - 1);
                }
                summ -= remove*(b);
                if(remove){
                        if(primFlower[idx] <= a) summ += b, summ -= a;
                        summ += suff[idx];
                }
                ans = max(ans, summ);
            }
			cout << ans << endl;
    }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/