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
struct FenwickTree{
    // zero based indexing
    // use query(l, r) to get the sum of elements in range[l, r]
    // exceptions handled when l = 0; (read(-1) returns 0)
    // increase and query take logn time and constant space.
    // constructor takes vector<int> input (a const reference) to construct the tree (ft) in nlogn time.

    vector<int> ft;

    FenwickTree(vector<int> I){
        ft.assign(I.size(), 0);

        for(int i = 0; i < I.size(); i++){
            increase(i, I[i]);
        }
    }

    int read(int idx){
        if(idx < 0) return 0;

        int ret = 0;

        for(int i = idx; i >= 0; i = (i&(i + 1)) - 1){
            ret += ft[i];
        }
        return ret;
    }

    void increase(int i, int delta){
        for(int j = i; j < ft.size(); j = j|(j + 1)){
            ft[j] += delta;
        }
    }

    int query(int l, int r){
        return read(r) - read(l - 1);
    }
};
int P__(int x, FenwickTree &f){
        // return P(x) = count of x
        return f.query(x, x);
}
int T__(int x, FenwickTree &f){
        // return t[x] = x * P(x) * (2 * P(< x) + P(x)); 
        return x * P__(x, f) * (2 * f.query(0, x - 1) + P__(x, f));
}
int F__(int x, FenwickTree &F, FenwickTree &f){
        // return f[x] = x * P(x) * 2
        return x * P__(x, f) * 2;
}
void slv(){
        int n; cin >> n; 

        vector<int> f_(2e5 + 1);

        FenwickTree F(f_), frequency(f_);

        // f[x] = P(x) * 2 * x
        // t[x] = x * P(x) * (2 * P(< x) + P(x))
        // ans = SUMMATION (x * t[x])

        // when u input x 
        // update f[x]
        // add summation f[y] (y > x) into the ans;

        // subtract t[x] from ans and add the updated t[x]; 
        // don't need to maintain t

        mint ans = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            int t_x = T__(x, frequency);
            int f_x = F__(x, F, frequency);

            frequency.increase(x, 1);

            F.increase(x, F__(x, F, frequency) - f_x);

            ans += T__(x, frequency) - t_x;

            // add summation f[y] y > x
            ans += F.query(x + 1, 2e5);
            mint den = i + 1;
            den *= i + 1;
            cout << (ans / den).x << endl;
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