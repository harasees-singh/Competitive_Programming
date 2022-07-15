// ਹਰਅਸੀਸ ਸਿੰਘ 
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

vector<pii> in;
int zero = 0;
bool good(int k, string &s){
    pii cur;

    int n = sz(in) - 1;
    int cost = infinity;
    for(int i = n - 1; i >= 0; i--){
        int limit = k - cur.ff;

        auto it = upper_bound(all(in), make_pair(limit, infinity)) - in.begin() - 1;
        // 1 based
        if(it > i) continue;

        amin(cost, max(in[it].ff + cur.ff, zero - cur.ss - in[it].ss));

        cur.ff += s[i] == '1';

        cur.ss += s[i] == '0';
    }
    amin(cost, max(cur.ff, cur.ss));
    return (cost <= k);
}
void slv(){
    string s; cin >> s; 
    zero = count(all(s), '0');
    int n = sz(s);
    in = vector<pii> (n + 1);

    for(int i = 1; i <= n; i++){
        in[i] = in[i - 1];

        in[i].ss += s[i - 1] == '0';

        in[i].ff += s[i - 1] == '1';
    }
    int l = 0, r = n;

    while(l <= r){
        int mid = (l + r) / 2;

        if(good(mid, s)) r = mid - 1;

        else l = mid + 1;
    }
    cout << min(l, zero) << endl;
}
int32_t main(){
        FIO 
        w(T)
            slv();
        return 0;
}
