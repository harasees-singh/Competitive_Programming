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

vector<vector<int>> g_dir;
map<pair<int, int>, int> E;
vector<int> val;

int lookup(int i, int j){
	if(i > j) swap(i, j);
	return E[{i, j}]; 
}

bool ok(int i, int j){
	// j the bit 1
	// ith node
    return ((val[i] >> j) & 1);
}

void slv(){
	int n, q; cin >> n >> q;
	
	val = vector<int> (n + 1, (1 << 30) - 1);

	g_dir = vector<vector<int>> (n + 1, vector<int>());
	vector<int> arr(n + 1);

	for(int i = 0; i < q; i++){
		int u, v; cin >> u >> v; 
		
		if(u > v) swap(u, v);
        
		if(u != v) g_dir[u].push_back(v);

		int w; cin >> w;

		val[u] &= w;
		val[v] &= w;

        if(u == v){
            arr[u] = w;
        }
		E[make_pair(u, v)] = w;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 30; j++){
			if(((arr[i] >> j) & 1)){
				continue;
			}
			bool bit = false;

            vector<int> LOOKUP;
			
			for(auto p : g_dir[i]){
                // iterate over direct descendants
                int t = (lookup(i, p));
                
                LOOKUP.push_back(t);

                if(!ok(p, j) and (t >> j) & 1){
                    bit = true; break;
                    // there is an edge where jth bit is 1 but the child cannot have the bit on
                }
			}
			if(bit){
                // so the parent must have it on or else the graph breaks which never happens according to the statement
				arr[i] |= (1 << j);

                assert(ok(i, j));
			}
			else{
                // let the children have their bits on
                int it = 0;
				for(auto p : g_dir[i]){
					arr[p] |= (LOOKUP[it++] & (1 << j));
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << arr[i] << " \n"[i == n];
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