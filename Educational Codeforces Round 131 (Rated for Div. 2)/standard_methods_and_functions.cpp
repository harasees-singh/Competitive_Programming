#include<bits/stdc++.h>
#define pb(a) push_back((a))
#define MOD 1000000007
#define sz(in) in.size()
using namespace std;

typedef long long ll;


template<typename T>
bool isPowerof2(ll x){
	return !(x && (x & (x-1)));
}

template<typename T>
T power(T x, T y, ll p) { 
    T res = 1;     
  
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
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
struct Factorials {
	
	vector<mint> f, fi;
 
	Factorials() : f(), fi() {}
	Factorials(int n) {
		n += 10;
		f = vector<mint>(n);
		fi = vector<mint>(n);
		f[0] = 1;
		for (int i = 1; i < n; i++)
			f[i] = f[i - 1] * i;
		fi[n - 1] = f[n - 1].inv();
		for (int i = n - 1; i > 0; i--)
			fi[i - 1] = fi[i] * i;
	}
 
	mint C(int n, int k) {
		if (k < 0 || k > n) return 0;
		return f[n] * fi[k] * fi[n - k];
	}
};
struct Powers {
	vector<mint> p, pi;
 
	Powers() : p(), pi() {}
	Powers(int n, mint x) {
		n += 10;
		if (x == 0) {
			p = vector<mint>(n);
			p[0] = 1;
		} else {
			p = vector<mint>(n);
			pi = vector<mint>(n);
			p[0] = pi[0] = 1;
			mint xi = x.inv();
			for (int i = 1; i < n; i++) {
				p[i] = p[i - 1] * x;
				pi[i] = pi[i - 1] * xi;
			}
		}
	}
 
	mint pow(int n) {
		if (n >= 0)
			return p[n];
		else
			return pi[-n];
	}
};
struct Inverses {
	vector<mint> ii;
    int mod = MOD;
 
	Inverses() : ii() {}
	Inverses(int n) {
		n += 10;
		ii = vector<mint>(n);
		ii[1] = 1;
		for (int x = 2; x < n; x++)
			ii[x] = mint() - ii[mod % x] * (mod / x);
	}
 
	mint inv(mint x) {
		assert(x != 0);
		int t = x.x;
		int res = 1;
		while(t >= (int)ii.size()) {
			int z = mod / t;
			res = res * (mod - z) % mod;
			t = mod - t * z;
		}
		return ii[t] * res;
	}
};
struct SparseTable{
    // 1 based indexing
    vector<vector<int>> M;
    vector<vector<int>> Midx;
    int lg = 1;
    vector<int> in;

    SparseTable(vector<int> &I){
        in = I;

        while((1 << lg) < sz(in)) lg++;

        M = vector<vector<int>> (lg + 1, vector<int> (sz(in) + 1));
        Midx = vector<vector<int>> (lg + 1, vector<int> (sz(in) + 1));

        for(int i = 1; i < sz(in) + 1; i++)
            Midx[0][i] = i - 1;
        
        for(int i = 1; i < sz(in) + 1; i++)
            M[0][i] = in[i - 1];

        for(int i = 0; i < lg; i++)
            for(int j = 1; j < sz(in) - (1 << i) + 1; j++)
                Midx[i + 1][j] = (in[Midx[i][j]] < in[Midx[i][j + (1 << i)]] ? Midx[i][j] : Midx[i][j + (1 << i)]);
            
        for(int i = 0; i < lg; i++)
            for(int j = 1; j < sz(in) - (1 << i) + 1; j++)
                M[i + 1][j] = min(M[i][j], M[i][j + (1 << i)]);
        
    }

    int readidx(int l, int r){
        assert(l <= r and l > -1);

        int n = 1, count = 0;

        while(n << 1 < (r - l + 1)) n <<= 1, count++;

        return in[Midx[count][l]] < in[Midx[count][r - n + 1]] ? Midx[count][l] : Midx[count][r - n + 1];
    }
    int read(int l, int r){
        assert(l <= r and l > -1);
        
        int n = 1, count = 0;
      
        while(n << 1 < (r - l + 1)) n <<= 1, count++;

        return min(M[count][l], M[count][r - n + 1]);
    }
};
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// call factorial() amd use C(n, r), all exceptions handled
// copy paste as it is
// log(p) time complexity per call

typedef long long ll;
template<typename T>
T power(T x, T y, ll p) { 
    T res = 1;     
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
ll fac[1000001] = {1};
void factorial(){
    fac[0] = 1;
    for(ll i=1;i<1000001;i++){
        fac[i] = (((((fac[i-1])+MOD)%MOD)*i)+MOD)%MOD;
    }
}
ll C(ll a,ll b){
    if(b>a)
        return 0;
    if(b==0||b==a)
        return 1;
    if(a==0)
        return 0;
    int div = ((fac[b]*fac[a-b]))%MOD;
    div = modInverse(div, MOD);
    return (fac[a]*div)%MOD;
}
////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// call these to initialize arrays 
// O(1) time complexity 
// use Binomial(n, r, p) all exceptions handled
/*
InverseofNumber(p);
InverseofFactorial(p);
factorial(p);
*/
const int N = 200000 + 5;
ll factorialNumInverse[N + 1];
 
ll naturalNumInverse[N + 1];
 
ll fact[N + 1];
 
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll Binomial(ll N, ll R, ll p)
{
	if(R > N or R < 0 or N < 0) return 0;
    ll ans = ((fact[N] * factorialNumInverse[R])% p * factorialNumInverse[N - R])% p;
    return ans;
}
ll p = 1000000007;

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

vector<int> divisors(ll n){
	vector<int> ans;
	for(int i = 2;i<=sqrt(n);i++){
		if(n % i ==0){
			ans.pb(i);
			if(n/i != i) ans.pb(n/i);
		}
	}
	ans.pb(1);
	return ans;
}

struct DisjointSet{
        int N;

        vector<int> Rank, parent, treesize;

        DisjointSet(int n){
                N = n;
                Rank = vector<int>(n + 1);
                parent = vector<int>(n + 1);
                treesize = vector<int>(n + 1);
                
                MakeSet();
        }
        

        void MakeSet(){
                for(int i = 0; i <= N; i++)
                        parent[i] = i, Rank[i] = 0, treesize[i] = 1;
        }

        int findParent(int v){

                if(parent[v] == v)
                        return v;
                
                return parent[v] = findParent(parent[v]);
        }

        void Union(int u, int v){

                u = findParent(u), v = findParent(v);

                if(Rank[u] > Rank[v])
                        parent[v] = u, treesize[u] += treesize[v];
                else if(Rank[u] < Rank[v])
                        parent[u] = v, treesize[v] += treesize[u];
                else        
                        parent[v] = u, Rank[u]++, treesize[u] += treesize[v];
        }
        int nodecnt(int i){
                i = findParent(i);

                return treesize[i]; // node cnt including the parent itself
        }
};

struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        x += 0x9e3779b97f4a7c15;
    
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
    
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct FenwickTree{
    // zero based indexing
    // use query(l, r) to get the sum of elements in range[l, r]
    // exceptions handled when l = 0; (read(-1) returns 0)
    // increase and query take logn time and constant space.
    // constructor takes vector<int> input (a const reference) to construct the tree (ft) in nlogn time.

    vector<int> ft;

    FenwickTree(vector<int> const &I){
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

template<typename T>
vector<T> sieve(T n){
	vector<int> prime(n+1, 1);
	for(int i = 2; i*i<=n; i++){
		if(prime[i]){
			for(int j = 2; j*i<=n; j++){
				prime[i*j] = 0;
			}
		}
	}
	vector<T> ans;
	for(int i = 2; i<=n;i++){
		if(prime[i]) ans.pb(i);
	}
	return prime;
}
template<typename T>
T _gcd(T a, T b){
	T temp1 = max(a,b), temp2 = min(a,b);
	a = temp1, b = temp2;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a%b ==0) return b;
	return _gcd(b, a%b);
}
 
ll nxt(){
    ll x;
    cin >> x;
    return x;
}

