#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

bool valley(int i, vi &a)
{
	return (a[i] < a[i - 1]) and (a[i] < a[i + 1]);
}

bool hill(int i, vi &a)
{
	return (a[i] > a[i - 1]) and (a[i] > a[i + 1]);
}

bool extremaNow(int i, vi &a)
{
	return hill(i, a) or valley(i, a);
}

void solve()
{
	int n; cin >> n;
	
	vi extrema(n), a(n);
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	int s = 0;
	
	for(int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1] and a[i] > a[i + 1])
			extrema[i] = 1, s++;
			
		else if (a[i] < a[i - 1] and a[i] < a[i + 1])
			extrema[i] = 1, s++;
	}
	
	int ans = s;
	
	for(int i = 1; i < n - 1; i++)
	{
		int old_a = a[i];
		
		// Case-1 : change a[i] to a[i - 1]
		a[i] = a[i - 1];
		
		int sub = extrema[i] + extrema[i - 1] + extrema[i + 1];
		int add = extremaNow(i, a) + extremaNow(i - 1, a) + extremaNow(i + 1, a); 
		
		ans = min(ans, s - sub + add);
		
		// Case-2
		a[i] = a[i + 1];
		
		add = extremaNow(i, a) + extremaNow(i - 1, a) + extremaNow(i + 1, a);
		
		ans = min(ans, s - sub + add);
		
		// undo the changes
		a[i] = old_a;		 
	}
	
	cout << ans << "\n";	
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}