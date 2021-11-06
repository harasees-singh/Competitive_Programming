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

    
            int n,k; cin >> n >> k;

            vi alice, bob;

            vi both;

            l(i, 0, n){
                    int t, a, b; cin >> t >> a >> b;

                    if(a and b) both.pb(t);

                    else if(a) alice.pb(t);

                    else if(b) bob.pb(t);
            }

            sort(all(alice)), sort(all(bob)), sort(all(both));

            int len = min(sz(alice), sz(bob));

            if(sz(both) + len < k){
                    cout << -1 << endl; return 0;
            }

            int ans = 0;

            int pt1 = 0;

            int pt2 = 0;

            int done = 0;

            while(done < k){
                    int indivi = infinity;

                    if(pt1 < len) indivi = alice[pt1] + bob[pt1];

                    int bothlike = infinity;

                    if(pt2 < sz(both)) bothlike = both[pt2];

                    if(indivi < bothlike) ans += indivi, pt1++;

                    else ans += bothlike, pt2++;

                    done++;
            }

            cout << ans << endl;

            // cout << accumulate(alice.begin(), alice.begin() + len, 0ll) + accumulate(bob.begin(), bob.begin() + len, 0ll) + accumulate(both.begin(), both.begin() + k - len, 0ll) << endl;
    

}
