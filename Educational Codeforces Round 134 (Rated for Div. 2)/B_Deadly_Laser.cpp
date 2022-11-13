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
vector<vector<bool>> dp;
bool safe(int i, int j, int sx, int sy, int d){
    if(i == dp.size() or j == dp[0].size() or i == 0 or j == 0) return false;

    return (abs(i - sx) + abs(j - sy) > d);
}
void mark(int i, int j, int sx, int sy, int d){
    if(!safe(i, j, sx, sy, d)) return;

    if(dp[i][j]) return;
    dp[i][j] = 1;
    mark(i + 1, j, sx, sy, d); mark(i - 1, j, sx, sy, d);

    mark(i, j + 1, sx, sy, d); mark(i, j - 1, sx, sy, d);
}
void slv(){
        int n, m, sx, sy, d; cin >> n >> m >> sx >> sy >> d; 

        dp = vector<vector<bool>> (n + 1, vector<bool> (m + 1));

        // mark(1, 1, sx, sy, d);
        bool top = true, right = true, left = true, bottom = true;
        for(int j = 1; j <= m; j++){
            if(!safe(1, j, sx, sy, d)){
                top = false;
            }
            if(!safe(n, j, sx, sy, d)){
                bottom = false;
            }
        }
        for(int i = 1; i <= n; i++){
            if(!safe(i, m, sx, sy, d)){
                right = false; 
            }
            if(!safe(i, 1, sx, sy, d)){
                left = false; 
            }
        }
        

        if(top and right or bottom and left){
            cout << n + m - 2 << endl; return;
        }
        cout << -1 << endl;
}

int32_t main(){
        
        FIO

        w(T) 
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