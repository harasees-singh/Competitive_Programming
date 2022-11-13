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
#define MOD_DEFINE                      const int MOD = 998244353;
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
// struct mint{ 
// 	int mod = MOD;
// 	int x;
 
// 	mint() : x(0) {}
// 	mint(int _x) {
// 		_x %= mod;
// 		if (_x < 0) _x += mod;
// 		x = _x;
// 	}
 
// 	mint& operator += (const mint &a) {
// 		x += a.x;
// 		if (x >= mod) x -= mod;
// 		return *this;
// 	}
// 	mint& operator -= (const mint &a) {
// 		x += mod - a.x;
// 		if (x >= mod) x -= mod;
// 		return *this;
// 	}
// 	mint& operator *= (const mint &a) {
// 		x = x * a.x % mod;
// 		return *this;
// 	}
// 	mint pow(int pw) const {
// 		mint res = 1;
// 		mint cur = *this;
// 		while(pw) {
// 			if (pw & 1) res *= cur;
// 			cur *= cur;
// 			pw >>= 1;
// 		}
// 		return res;
// 	}
// 	mint inv() const {
// 		assert(x != 0);
// 		int t = x;
// 		int res = 1;
// 		while(t != 1) {
// 			int z = mod / t;
// 			res = res * (mod - z) % mod;
// 			t = mod - t * z;
// 		}
// 		return res;
// 	}
// 	mint& operator /= (const mint &a) {
// 		return *this *= a.inv();
// 	}
// 	mint operator + (const mint &a) const {
// 		return mint(*this) += a;
// 	}
// 	mint operator - (const mint &a) const {
// 		return mint(*this) -= a;
// 	}
// 	mint operator * (const mint &a) const {
// 		return mint(*this) *= a;
// 	}
// 	mint operator / (const mint &a) const {
// 		return mint(*this) /= a;
// 	}
// 	bool operator == (const mint &a) const {
// 		return x == a.x;
// 	}
// 	bool operator != (const mint &a) const {
// 		return x != a.x;
// 	}
// 	bool operator < (const mint &a) const {
// 		return x < a.x;
// 	}
// };
// max over all nodes, sum from all parent nodes - 1 + distance till sink
vector<int> d; 
vector<int> s; 
vector<vector<int>> g; 
vector<vector<int>> grev;
vector<int> val;
int ans = 0;
int dfs(int i){
        if(s[i] != -1) return s[i];

        int put = val[i]; 

        for(auto p : grev[i]){
                put += dfs(p);
        }
        return s[i] = put;
} 
int DFS(int i){
        if(d[i] != -1) return d[i];

        for(auto p : g[i]) amax(d[i], DFS(p));

        ++d[i];

        if(s[i]){
                amax(ans, s[i] - 1 + d[i]);

                // if(ans > 6 * MOD) cout << i << ' ' << ans << endl;
        }
        return d[i];
}
void slv(){
        int n, m; cin >> n >> m; 
        ans = 0;
        d = vector<int> (n + 1, -1);

        s = vector<int> (n + 1, -1);

        g = vector<vector<int>> (n + 1);

        grev = vector<vector<int>> (n + 1);

        val = vector<int> (n + 1);

        for(int i = 1; i <= n; i++) cin >> val[i];

        vector<int> out(n);

        for(int i = 0; i < m; i++){
                int u, v; cin >> u >> v; 

                out[u - 1]++;

                g[u].push_back(v);
                grev[v].push_back(u);
        }       
        int sink = min_element(all(out)) - out.begin() + 1;
        // calc s vector through grev and then ans through g

        dfs(sink);
        // for(auto p : s) cout << p / MOD << ' ';cout << endl;
        d[sink] = 1;

        for(int i = 1; i <= n; i++) DFS(i);

        cout << ans % MOD << endl;
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