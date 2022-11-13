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

int get(const vector<int> &ZERO, int l, int r, int right){
    return (ZERO[right] - ZERO[l - 1] != (right - l + 1)) + (ZERO[r] - ZERO[right] != (r - (right + 1) + 1));
}

void slv(){
        int n, q; cin >> n >> q; 

        vector<int> in(n + 1);

        for(int i = 1; i <= n; i++){
            int t; cin >> t; 

            in[i] = t;
        }
        vector<vector<int>> f(n + 1, vector<int> (30));

        vector<map<string, vector<int>>> HASH(2); // even, odd

        for(int i = 1; i <= n; i++){
            string out;
            for(int j = 0; j < 30; j++){
                f[i][j] = (in[i] >> j) ^ f[i - 1][j];
                out += to_string(f[i][j]);
            }
            HASH[i % 2][out].push_back(i);
        }
        vector<int> ZERO(n + 1);

        for(int i = 1; i <= n; i++){
            ZERO[i] = ZERO[i - 1] + (in[i] == 0);
        }
        for(auto &p : HASH[0]){
            sort(all(p.second));
        }
        for(auto &p : HASH[1]){
            sort(all(p.second));
        }
        for(int i = 0; i < q; i++){
            int l, r; cin >> l >> r;

            if((r - l + 1) % 2){
                // 1 or -1

                if(f[r] == f[l - 1]){
                    cout << (ZERO[r] - ZERO[l - 1] != (r - l + 1)) << endl; 
                }
                else cout << -1 << endl;
            }
            else{
                // break in two segs of odd len with each xor 0

                if(f[r] != f[l - 1]){
                    cout << -1 << endl; continue;
                }
                // net seg xor is 0 ✔️
                string out;
                for(int j = 0; j < 30; j++){
                    out += to_string(f[l - 1][j]); // string corres to l index
                }
                auto it = lower_bound(all(HASH[l % 2][out]), l); 

                if(it != HASH[l % 2][out].end() and *it <= r){
                    // 0, 0, 0, 0
                    // check dis case

                    // also u might need 1 operation 
                    // 0, 1, 1, 0
                    // take prev(hash.end()) as the right border and check if left needs operation and if right needs operation

                    int right = *(upper_bound(all(HASH[l % 2][out]), r) - 1);

                    // int ans = (ZERO[right] - ZERO[l - 1] != (right - l + 1)) + (ZERO[r] - ZERO[right] != (r - (right + 1) + 1));
                    int ans = get(ZERO, l, r, right);

                    int left = *(it);

                    amin(ans, get(ZERO, l, r, left));

                    cout << ans << endl;
                }   
                else{
                    cout << -1 << endl;
                }
            }
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