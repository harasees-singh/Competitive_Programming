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
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE
vector<map<int, int>> dp;
vector<int> s;
vector<vector<int>> g;
int k;

int dfs(int i, int put){
        // return the mx ans of the subtree if i put the value 'put' on the ith node.
        if(dp[i].count(put)) return dp[i][put];

        int children = g[i].size();

        if(children == 0) return dp[i][put] = put * s[i];

        int base = put / children;

        int rem = put % children;

        vector<int> diff;

        dp[i][put] = put * s[i];

        for(auto p : g[i]){
            diff.push_back(- dfs(p, base) + (rem ? dfs(p, base + 1) : dfs(p, base)));

            dp[i][put] += dfs(p, base + (int)((bool)rem));
        }
        sort(all(diff));

        for(int j = 0; j < children - rem; j++){
            dp[i][put] -= diff[j];
        }
        return dp[i][put];
}

void slv(){
        int n; cin >> n >> k; 

        g = vector<vector<int>> (n + 1);
        s = vector<int> (n + 1);

        dp = vector<map<int, int>> (n + 1);

        for(int i = 2; i <= n; i++){
            int t; cin >> t; 

            g[t].push_back(i);
        }
        for(int i = 1; i <= n; i++) cin >> s[i];

        cout << dfs(1, k) << endl;

        for(auto p : dp) assert(p.size() < 3);
        // for(auto p : dp){
        //     cout << "--------------" << endl;
        //     for(auto q : p) cout << q << endl;
        //     cout << "--------------" << endl;
        // }
}

int32_t main(){
        
        FIO

        w(T) 
                slv();
        
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/