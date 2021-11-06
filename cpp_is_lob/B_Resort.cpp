#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff first
#define ss second
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define endl '\n'
#define space " "
// #define int                             long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back((n))
#define mii map<int, int>
#define umii unordered_map<int, int>
#define w(t)  \
	int t;    \
	cin >> t; \
	while (t--)
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define l(var, initial, final) for (int var = initial; var < final; var++)
#define cout std::cout
#define cin std::cin
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define fps(x, y) fixed << setprecision(y) << x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

vector<vi> g;

vi val;

vi dp;

vi vis;

int dfs(int i)
{

	if (val[i] == 1)
		return dp[i] = 1;

	if (dp[i] == -1)
	{

		if (sz(g[i]) > 1 or sz(g[i]) == 0 or vis[g[i][0]])
			return dp[i] = -2;

		vis[g[i][0]] = 1;

		int t = dfs(g[i][0]);

		return dp[i] = (t == -2 ? -2 : 1 + t);
	}

	return dp[i];
}

void printDFS(int i)
{
	cout << i << space;

	if (val[i] == 1)
		return;

	printDFS(g[i][0]);
}

int32_t main()
{
	FIO

	int n;
	cin >> n;

	vis = vi(n + 1);

	val = vi(n + 1);

	g = vector<vi>(n + 1);

	dp = vi(n + 1, -1);

	l(i, 1, n + 1)
	{
		cin >> val[i];
	}

	l(i, 0, n)
	{
		int t;
	
		cin >> t;

		g[t].pb(i + 1);
	}

	int maxi = 0;

	int node;

	l(i, 1, n + 1)
	{

		int t = dp[i];

		if(t == -1)
				t = dfs(i);

		if(t > maxi)
				maxi = t, node = i;
	}

	assert(maxi);

	cout << maxi << endl;

	printDFS(node);

	return 0;
}
