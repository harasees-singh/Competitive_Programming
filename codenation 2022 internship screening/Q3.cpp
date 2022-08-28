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
struct mint{ 
	int mod = MOD;
	int x;
 
	mint() : x(0) {}
	mint(int _x) {
		_x %= mod;
		if (_x < 0) _x += mod;
		x = _x;
	}
 
	mint& operator += (const mint &a) {
		x += a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &a) {
		x += mod - a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator *= (const mint &a) {
		x = x * a.x % mod;
		return *this;
	}
	mint pow(int pw) const {
		mint res = 1;
		mint cur = *this;
		while(pw) {
			if (pw & 1) res *= cur;
			cur *= cur;
			pw >>= 1;
		}
		return res;
	}
	mint inv() const {
		assert(x != 0);
		int t = x;
		int res = 1;
		while(t != 1) {
			int z = mod / t;
			res = res * (mod - z) % mod;
			t = mod - t * z;
		}
		return res;
	}
	mint& operator /= (const mint &a) {
		return *this *= a.inv();
	}
	mint operator + (const mint &a) const {
		return mint(*this) += a;
	}
	mint operator - (const mint &a) const {
		return mint(*this) -= a;
	}
	mint operator * (const mint &a) const {
		return mint(*this) *= a;
	}
	mint operator / (const mint &a) const {
		return mint(*this) /= a;
	}
	bool operator == (const mint &a) const {
		return x == a.x;
	}
	bool operator != (const mint &a) const {
		return x != a.x;
	}
	bool operator < (const mint &a) const {
		return x < a.x;
	}
};
string C; 
vector<vector<int>> g;
vector<vector<int>> U;
vector<vector<mint>> HASH_UP;
vector<vector<mint>> HASH_DOWN;
int lg;
int T = 0;
vi tin, tout;
void dfs(int i, int p){
    tin[i] = T++;

    for(auto q : g[i]){
        if(q != p)
            dfs(q, i);
    }
    tout[i] = T++;
}
bool isAncestor(int p, int x){
    return tin[p] <= tin[x] and tout[p] >= tout[x];
}
int BIN_LIFT(int i, int p){
    U[i][0] = p;

    HASH_UP[i][0] = 26 * (C[i] - 'a') + C[p] - 'a';
    HASH_DOWN[i][0] = 26 * (C[p] - 'a') + C[i] - 'a';

    for(int j = 1; j <= lg; j++){
        U[i][j] = U[U[i][j - 1]][j - 1];

        HASH_UP[i][j] = HASH_UP[i][U[i][j - 1]] - mint(26).pow((1 << (j - 1))) * (C[U[i][j - 1]] - 'a') + HASH_UP[i][j - 1] * mint(26).pow((1 << (j - 1)));

        HASH_DOWN[i][j] = HASH_DOWN[i][U[i][j - 1]] * mint(26).pow((1 << (j - 1))) + HASH_DOWN[i][j - 1] - mint(26).pow((1 << (j - 1))) * (C[U[i][j - 1]] - 'a');
    }
    for(auto q : g[i])
        if(q != p)
            BIN_LIFT(q, i);
}
void slv(){
        int n; cin >> n; 

        vector<vector<int>> B(2, vector<int> (n - 1));
        for(int j = 0; j < 2; j++)
            for(int i = 0; i < n - 1; i++)
                cin >> B[j][i];
            
        cin >> C; C = "a" + C;  // make it 1 based

        g = vector<vector<int>> (n + 1); tin = vi(n + 1); tout = vi(n + 1); 

        for(int i = 0; i < n - 1; i++){
            int u = B[0][i], v = B[1][i];

            g[u].pb(v), g[v].pb(u);
        }

        lg = 1; 

        for(; (1 << lg) <= n; lg++);

        U = vector<vector<int>> (n + 1, vector<int> (lg));
        HASH_UP = vector<vector<mint>> (n + 1, vector<mint> (lg)); // string starting from bottom
        HASH_DOWN = vector<vector<mint>> (n + 1, vector<mint> (lg)); // string starting from top


        dfs(1, 0); // assume any node as the root doesn't matter
        
        BIN_LIFT(1, 0);

        // for(auto p : U) cout << p; ok

        int q; cin >> q; 
        set<int> s;
        vector<vector<int>> D(2, vi(q));
        for(int j = 0; j < 2; j++)
            for(int i = 0; i < q; i++) cin >> D[j][i];
        
        for(int i = 0; i < q; i++){
            int u = D[0][i], v = D[1][i];

            
        }
}

int32_t main(){
        
        FIO

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