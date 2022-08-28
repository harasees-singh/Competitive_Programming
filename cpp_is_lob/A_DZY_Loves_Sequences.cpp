// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
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
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
        
        FIO

        int n; cin >> n;

        vi in(n); for(auto &p : in) cin >> p;

        in.pb(-infinity);

        vi pref(n + 1, 1), suff(n + 2, 1);

        suff[n + 1] = pref[0] = 0;

        l(i, 1, n) 
                if(in[i] > in[i - 1]) pref[i + 1] += pref[i];

        for(int i = n - 2; i >= 0; i--)
                if(in[i] < in[i + 1]) suff[i + 1] += suff[i + 2];

        int mx = 1 + suff[2];

        // for(auto p : pref) cout << p << ' '; cout << endl;
        // for(auto p : suff) cout << p << ' '; cout << endl;

        for(int i = 1; i < n; i++){
                // cout << in[i - 1] << ' ' << in[i + 1] << endl;
                if(in[i - 1] < in[i + 1] - 1) mx = max(mx, 1 + pref[i] + suff[i + 2]);

                else mx = max(mx, 1 + max(pref[i], suff[i + 2]));
                // cout << mx << endl;
        }
        cout << mx << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/