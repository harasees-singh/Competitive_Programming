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

vpii treespace;
int m;

bool good(int k){
    // atmost k on left and right of each tree;
    int cnt = 0;

    for(int i = 1; i < treespace.size(); i++){
        pii p = treespace[i];
        cnt += min(p.ff, k);
        cnt += min(p.ss, k);
    }

    return (cnt >= m);
}

int32_t main(){
    FIO

    int n; cin >> n >> m;
    treespace = vpii(n + 1);
    vi T(n + 2);

    T[0] = -infinity;
    T[n + 1] = infinity;

    l(i, 1, n + 1) cin >> T[i];

    sort(all(T));

    l(i, 1, n + 1){
        treespace[i].ff = (T[i] - T[i - 1] - 1)/2;
        treespace[i].ss = (T[i + 1] - T[i])/2;
    }
    int l = 1, r = m;

    while(l < r){
        int mid = (l + r)/2;
        if(good(mid)) r = mid - 1;
        else l = mid + 1;
    }
    vi ans;
    int cnt = 0;
    l(i, 1, n + 1){
        l(j, 0, min(l, treespace[i].ff)){
            cnt++;

        }
        l(j, 0, min(l, treespace[i].ss)){
            cnt++;

        }
    }
    int diff = cnt - m;

    l(i, 1, n + 1){
        if(!diff)break;
        treespace[i].ff = min(treespace[i].ff, l);
        treespace[i].ss = min(treespace[i].ss, l);

        if(treespace[i].ff == l and diff) treespace[i].ff--, diff--;
        if(treespace[i].ss == l and diff) treespace[i].ss--, diff--;
    }
    int cost = 0;
    l(i, 1, n + 1){
        l(j, 0, min(l, treespace[i].ff)){
            // cout << T[i] - j - 1 << space;
            cost += j + 1;
            ans.pb(T[i] - j - 1);
        }
        l(j, 0, min(l, treespace[i].ss)){
            // cout << T[i] + j + 1 << space;
            cost += j + 1;
            ans.pb(T[i] + j + 1);
            // if(cnt == m) break;
        }
    }
    cout << cost << endl;
    for(auto p : ans) cout << p << space; 
    cout << endl;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/