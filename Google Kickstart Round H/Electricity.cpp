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

void prn() {}
template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE
vector<int> in;
vector<int> dp1;
vector<int> root_dp;
vector<vector<int>> g;
void fill_dp1(int i, int p){
    for(auto des: g[i]) 
        if(des != p) 
            fill_dp1(des, i), dp1[i] += (in[des] < in[i] ? dp1[des] : 0);

    dp1[i] ++; // itself
}
void re_root(int i, int p){
    // root at i
    
    if(in[p] < in[i]){
        // root_dp[i] += parent_ans;
        root_dp[i] = root_dp[p] + dp1[i];
    }
    else{
        root_dp[i] = dp1[i];
    }
    for(auto q : g[i]){
        if(q != p)
            re_root(q, i);
    }
}
void slv(){
        int n; cin >> n;

        in = vector<int> (n + 1);
        for(int i= 1; i <= n; i++) cin >> in[i];
        dp1 = vector<int> (n + 1);
        root_dp = vector<int> (n + 1);
        g = vector<vector<int>> (n + 1);
        for(int i = 0; i < n - 1; i++){
            // tree given in limits

            int u, v; cin >>u >> v; 

            g[u].push_back(v); 
            g[v].push_back(u); 
        }
        fill_dp1(1, 0);
        // cout << dp1;
        root_dp[1] = dp1[1];
        for(auto p : g[1]) re_root(p, 1);

        cout << *max_element(all(root_dp)) << endl;
}

int32_t main(){
        
        FIO

        int T = 1;

        int t; cin >> t;

        for(; T <= t; T++){
            cout << "Case #" << T << ": ";
            
            slv();
        }
        
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/