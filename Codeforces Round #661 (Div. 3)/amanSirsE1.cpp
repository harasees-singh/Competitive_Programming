#include <bits/stdc++.h>
using namespace std;

#define int           long long 
// #define S             second
// #define F             first
#define pb            push_back
#define all(c)        (c).begin(),(c).end()
#define rall(c)       (c).rbegin(),(c).rend() 
#define lb            lower_bound
#define si(c)         (int)((c).size())
#define lcm(a, b)      (a * (b / __gcd(a,b)))  
#define inf           (int)(1e18)
#define endl          '\n'
#define mp            make_pair
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define debug(args...)    _F(#args, args)
#define vi            std::vector<int>
#define pii           pair<int, int> 
#define vpi           vector<pii>

clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

template<typename T> void _F(const char *name, T arg1){ cerr << name << " = " << arg1 << endl;}
template<typename T, typename... Args> void _F(const char *names, T arg1, Args... args)
{ const char *name = strchr(names, ',');cerr.write(names, name-names) << " = " << arg1 << endl;_F(name+2, args...);}

template< typename T1, typename T2 > istream& operator>>(istream& in, pair<T1, T2> &q){ in >> q.F >> q.S; return in;}
template< typename T1, typename T2 > ostream& operator<<(ostream& out, pair<T1, T2> &q){ out << q.F << " " << q.S; return out;}
template< typename T1, typename T2 > pair<T1, T2> operator+(pair<T1, T2> p1, pair<T1, T2> p2){ return {p1.F+p2.F, p1.S+p2.S};}
template< typename T1, typename T2 > pair<T1, T2> operator-(pair<T1, T2> p1, pair<T1, T2> p2){ return {p1.F-p2.F, p1.S-p2.S};}
template< typename T1, typename T2 > bool operator<(pair<T1, T2> p1, pair<T1, T2> p2){ return p1 < p2 ;}

template<typename T> void Unique(vector<T> &v){
    sort(all(v)), v.resize(distance(v.begin(), unique(all(v))));
}



struct Pair
{
	int F, S;
	Pair(int x, int y):F(x), S(y){}
	bool operator<(Pair other) const {
		int tmp1 = F-((S/2)*(F/S));
		int tmp2 = other.F-((other.S/2)*(other.F/other.S));
		return tmp1 <= tmp2;
	}
};

const int N = 1e5+1;
vpi g[N];
vi vis(N);
set<Pair> st;
int n, s, cur;

void clear(int n) {
	for(int i = 0; i <= n; i++) {
		g[i].clear();
		vis[i] = 0;
	}
	st.clear();
	cur = 0;
}

int dfs(int v, int w) {
	vis[v] = 1;
	int cnt = 0;
	for(auto u : g[v]) {
		if(!vis[u.first]) {
			cnt += dfs(u.first, u.second);
		}
	}
	if(si(g[v]) == 1)cnt++;
    cur += w*cnt;
    // cout << w*cnt << ' ' << w << endl;
    if(w*cnt != 0){
    	// cout << "if " << endl;
    	Pair p(w*cnt, w);
    	st.insert(p);
    	// for(auto u : st) {
	    // 	cout << u.F << " " << u.S << endl;
	    // }
	    // cout << "hell" << endl;
    }
    return cnt;
}

void solve(int &test) {
	cin >> n >> s;
	int u, v, w;
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v >> w;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	dfs(1, 0);
	// cout << "moves" << endl;
    int moves = 0;
    // for(auto u : st) {
    // 	cout << u.F << " " << u.S << endl;
    // }
    // cout << "hell" << endl;
    while(cur > s) {
    	assert(si(st) > 0);
    	Pair tmp = *(--end(st));
    	// cout << tmp.F << " " << tmp.S << endl;
    	st.erase(--end(st));
    	cur -= tmp.F;
    	int cnt = tmp.F/tmp.S;
    	tmp.S /= 2;
    	tmp.F = tmp.S*cnt;
    	cur += tmp.F;
    	// cout << tmp.F << " hello " << tmp.S << endl;
    	if(tmp.F != 0)
    	st.insert(Pair(tmp.F, tmp.S));
    	moves++;
    }
    cout << moves << endl;
    clear(n);
 }

signed main(){

    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);   
    start = clock(); 

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int t = 1;
    cin >> t;

    cout << fixed << setprecision(2);
     
    for(int i = 1; i <= t; ++i){
        solve(i); 
    }

    // cerr << time(start);
    return 0;
}