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
vector<vi> g;
vi a; 
bool ok;
int dfs(int i, int parent, int mid){
    if(not ok) return 0;
    // return vacancy

    // if after adding up all vacancies of children need is not satisfied, mark ok as 0

    if(i != 1 and sz(g[i]) == 1){
        // leaf
        if(mid < a[i]) {ok = 0; return 0;}

        return mid - a[i];
        
    }
    int have = 0;    
    for(auto p : g[i]){
        if(p != parent){
            have += dfs(p, i, mid); amin(have, 2e14);
        }
    }
    if(have < a[i]) {ok = 0; return 0;}
    return have - a[i]; // itne bach gye
}   
int32_t main(){
        
    FIO

    int n; cin >> n; 
    g = vector<vi> (n + 1);

    for(int i = 2; i <= n; i++){
        int t; cin >> t;

        g[i].pb(t); g[t].pb(i);
    }

    a = vi(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 0, r = 1e9 * 2e5;

    while(l <= r){
        int mid = (l + r)/2;

        ok = true;

        dfs(1, 0, mid);

        if(not ok) l = mid + 1;

        else r = mid - 1;
    } 
    assert(l <= (1e9 * 2e5));
    cout << l;
    return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/