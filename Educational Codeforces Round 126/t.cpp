
#include<bits/stdc++.h>

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

template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

int32_t main() {
	int n; cin >> n;

	vi in(n); for(auto &p : in) cin >> p;

	vi dp(n + 1);  
	in.push_back(infinity);
	stack<int> nxt; nxt.push(n);
	int mx = 0;
	for(int i = n - 1; i >= 0; i--){
		while(in[nxt.top()] <= in[i]) nxt.pop();

		int nxtgreater = nxt.top();

		dp[i] = in[i] ^ dp[nxtgreater];

		amax(mx, dp[i]);
	}
	cout << mx << endl;
}