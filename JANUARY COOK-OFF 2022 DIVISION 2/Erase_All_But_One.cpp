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
#define w(t)                            int t; cin >> t; while(t--)
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

MOD_DEFINE

int32_t main(){
        
        FIO

        // let 1 be at pos i 
        // then if max_element over it over [i + 1 to n - 1] > the smallest possible first ele then true else false
        // smallest possible first ele : take min over first eles till the first ele is non removable.
        w(t){
            	int n; cin >> n; 

		vi in(n); for(auto &p : in) cin >> p;

		int pt = 0;

		set<int> till_pt_plus_1;

		for(int i = n - 1; i >= 0; i--) till_pt_plus_1.insert(in[i]);

		int mn = in[0];

		for(; pt < n; pt++){
			if(*prev(till_pt_plus_1.end()) > in[pt] or mn < in[pt]) till_pt_plus_1.erase(in[pt]), mn = min(mn, in[pt]);

			else break;
		}
		// cout << mn << endl;
		auto id = find(all(in), 1);

		int mx = *max_element(id, in.end());

		cout << (mx > mn ? "YES" : "NO") << endl;
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