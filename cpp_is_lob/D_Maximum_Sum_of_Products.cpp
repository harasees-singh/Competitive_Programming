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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int mx = 0;

vi pref, suff, a, b;
int n; 
void propagate(int cur, int l, int r){
        while(l >= 0 and r <= n + 1){
                mx = max(mx, cur + pref[l] + suff[r]);

                cur += a[l]*b[r] + b[l]*a[r];

                l--; r++;
        }
}

int32_t main(){
        
        FIO

        cin >> n;

        // vi a(n + 1), b(n + 1);
        a = vi(n + 2); b = vi(n + 2);

        l(i, 1, n + 1) cin >> a[i];
        l(i, 1, n + 1) cin >> b[i];
        
        // vi pref(n + 1), suff(n + 1);
        pref = vi(n + 1); suff = vi(n + 2);
        suff[n] = a[n]*b[n];

        l(i, 1, n + 1) pref[i] = pref[i - 1] + a[i]*b[i];

        for(int i = n; i > 0; i--) suff[i] = suff[i + 1] + a[i]*b[i];

        l(i, 1, n + 1){
                propagate(a[i]*b[i], i - 1, i + 1);
        }
        l(i, 1, n){
                propagate(a[i]*b[i + 1] + a[i + 1]*b[i], i - 1, i + 2);
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