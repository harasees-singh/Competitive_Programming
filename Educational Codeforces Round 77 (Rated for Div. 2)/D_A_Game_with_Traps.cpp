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
vector<vector<pii>> in;
bool good(int mid, int t){
        int ans = 0;
        int i = 0;
        int n = sz(in) - 1;
        for(; i < n; ){
                // cout << i << endl; cout.flush();
                int mx = i + 1;

                bool diffuse = false;

                // cout << mx << endl; cout.flush(); 
                for(int j = i + 1; j <= mx; j++){
                        for(auto p : in[j]){
                                if(p.ff > mid) amax(mx, p.ss), diffuse = true;

                                // cout << mx << endl; cout.flush();
                        }
                }
                if(diffuse){
                        ans += 2 * (mx - i);
                }
                // cout << mx << endl; cout.flush();
                // cout << endl;
                i = mx; 
        }
        return ans + n + 1 <= t;
}
void slv(){
        int m, n, k, t; cin >> m >> n >> k >> t;

        vi bois(m); cin >> bois; sort(all(bois));

        reverse(all(bois));

        in = vector<vector<pii>>(n + 1);

        for(int i = 0; i < k; i++){
                int l, r, d; cin >> l >> r >> d; 

                in[l].push_back({d, r}); // l pe trap of harm d go to r to disarm
        }
        // cout << in; cout.flush();
        int l = 0, r = m - 1; 

        while(l <= r){

                int mid = (l + r) / 2;

                // cout << mid << endl; cout.flush();

                int agl = bois[mid];

                if(good(agl, t)) l = mid + 1; 

                else r = mid - 1;
        }
        cout << r + 1 << endl;
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