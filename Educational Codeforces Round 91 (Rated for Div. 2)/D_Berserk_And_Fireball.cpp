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
#define w(T)                            int T; cin >> T; while(T--)
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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE
int MAXN = 200000;

int t[800001];

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2 + 1, tl, tm);
        build(a, v*2 + 2, tm+1, tr);
        t[v] = max(t[v*2 + 1], t[v*2 + 2]);
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return -infinity;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum(v*2 + 1, tl, tm, l, min(r, tm)) ,sum(v*2 + 2, tm + 1, tr, max(l, tm + 1), r));
}
// void update(int v, int tl, int tr, int pos, int new_val) {
//     if (tl == tr) {
//         t[v] = new_val;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v*2 + 1, tl, tm, pos, new_val);
//         else
//             update(v*2 + 2, tm + 1, tr, pos, new_val);
//         t[v] = (t[v*2 + 1], t[v*2 + 2]);
//     }
// }


int n, m; 
int x, k, y; 
vi a, b; 

int usek(int i, int j){
    int rem = (j - i + 1) % k;

    int out = ((j - i + 1) / k) * x;

    bool can = 1;
    int mn = infinity;
    for(int it = 0; it < rem; it++){
        amin(mn, max(sum(0, 0, n - 1, i, i + it - 1), sum(0, 0, n - 1, j - rem + it + 1, j)));
    }

    int l = (i == 0 ? -infinity : a[i - 1]);

    int r = (j == n - 1 ? -infinity : a[j + 1]);

    amax(l, r); 
    
    if(rem)
        can = l > mn;
    if(not can) return infinity;
    
    out += rem * y;

    return out;
}

int clearseg(int i, int j){
    if(i > j) return 0;
    int op1 = usek(i, j);

    int op2; 

    int op3;

    int l = (i == 0 ? -infinity : a[i - 1]);

    int r = (j == n - 1 ? -infinity : a[j + 1]);

    int wall = max(l, r);

    int start = -1, end = -1;

    for(int it = i; it <= j; it++){
        if(a[it] > wall) if(start == -1) start = it; else end = it;
    }

    int segs = (end - start + 1 + k - 1) / k;

    if(sum(0, 0, n - 1, i, j) > max(l, r)){
        op2 = infinity;
    }
    else op2 = (j - i + 1) * y;

    amin(op1, op2);

    return op1;
}
vector<int> segs = {-1};
void solve(){
    int out = 0;

    for(int i = 1; i < sz(segs); i++){
        // cout << segs[i - 1] + 1 << ' ' << segs[i] - 1 << ' ';
        int cost = clearseg(segs[i - 1] + 1, segs[i] - 1); 
        // cout << cost << endl;
        if(cost == infinity){
            cout << -1; return;
        }
        out += cost;
    }
    cout << out;
}
int32_t main(){
        
        FIO

        cin >> n >> m;


        cin >> x >> k >> y;

        a = vi(n); b = vi(m);

        for(auto &p : a) cin >> p; for(auto &p : b) cin >> p;

        build(a, 0, 0, n - 1);
        // cout << sum(0, 0, n - 1, 0, 2) << endl;
        
        int i = 0, j = 0;
        for(; (i < n) and (j < m); i++){
            int need = b[j];

            int have = a[i];

            if(need == have) j++, segs.push_back(i);
        }
        segs.push_back(n);
        if(j != m){
            cout << -1; return 0;
        }
        solve();

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/