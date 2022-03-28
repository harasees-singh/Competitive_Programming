// ਹਰਅਸੀਸ ਸਿੰਘ
// do it for the fam 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE
// use berzerk x mod k times
// now remaining is multiple of k
// if the max ele is < boundary then can use all berzerk else will need atleast 1 fireball

int x, k, y;
int n, m; 
vi a, b; 
vi segs = {-1};
int boundary(int i, int j){
    int l = (i == 0 ? -infinity : a[i - 1]);

    int r = (j == n - 1 ? -infinity : a[j + 1]);

    return max(l, r);
}
int smallseg(int i, int j){
    assert(j - i + 1 < k);

    int mx = 0;

    for(int it = i; it <= j; it++) amax(mx, a[it]);

    if(mx > boundary(i, j)) return infinity;

    return y * (j - i + 1);
}
int clearseg(int i, int j){
    
    if(i > j) return 0;

    int len = j - i + 1;

    if(len < k){
        return smallseg(i, j);
    }

    // int ret = (len % k) * y;

    int mx = 0;

    for(int it = i; it <= j; it++) amax(mx, a[it]);

    int out = (len % k) * y; // mandatory berzerk

    int mn = (len / k) * x;

    if(mx < boundary(i, j)){

        // can use berzerk for all the ele

        amin(mn, y * (len - (len % k)));
    }
    int tot = len / k;

    amin(mn, (tot - 1) * k * y + x);

    return out + mn;
}
void solve(){
    int out = 0;
    for(int i = 1; i < sz(segs); i++){
        int ret = clearseg(segs[i - 1] + 1, segs[i] - 1);

        if(ret == infinity){
            cout << -1; return;
        }

        out += ret;
    }
    cout << out;
}
int32_t main(){
        FIO 

        cin >> n >> m;

        cin >> x >> k >> y;

        a = vi(n);
        b = vi(m);

        for(auto &p : a) cin >> p; 
        for(auto &p : b) cin >> p; 

        int i = 0, j = 0;
        for(; (i < n) and (j < m); i++){
            int need = b[j];

            int have = a[i];

            if(need == have) j++, segs.push_back(i);
        }
        if(j < m){
            cout << -1; return 0;
        }
        segs.push_back(n);

        solve();

        return 0;
}
