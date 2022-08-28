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

vector<vector<vector<int>>> dp;  
bool check(vector<string> &in, vector<vector<pair<int, int>>> &X, vector<vector<pair<int, int>>> &Y){
    // segment cover 
    int n = in.size(), m = in[0].size();

    vector<vector<bool>> mark(n, vector<bool> (m));

    // cout << X << Y << endl; cout.flush();

    for(int i = 0; i < n; i++){
        int pt = 0;
        sort(all(X[i]));

        int lst = -1;
        int mx = -2;
        while(pt < sz(X[i])){
            if(X[i][pt].ff > mx) lst = X[i][pt].ff, mx = X[i][pt].ss;

            while(pt < sz(X[i]) and X[i][pt].ff <= mx) amax(mx, X[i][pt].ss), pt++;

            for(int x = lst; x <= mx; x++) mark[i][x] = 1;
        }
    }
    // for(auto p : mark) {for(auto q : p)cout << q <<' '; cout << endl;} cout.flush();
    for(int i = 0; i < m; i++){
        int pt = 0;
        sort(all(Y[i]));

        int lst = -1;
        int mx = -2;
        while(pt < sz(Y[i])){
            if(Y[i][pt].ff > mx) lst = Y[i][pt].ff, mx = Y[i][pt].ss;

            while(pt < sz(Y[i]) and Y[i][pt].ff <= mx) amax(mx, Y[i][pt].ss), pt++;

            for(int x = lst; x <= mx; x++) mark[x][i] = 1;
        }
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(in[i][j] == '*' and mark[i][j] == 0) return false;

    return true;
}
void slv(){
        int n, m; cin >> n >> m; 

        vector<string> in(n); cin >> in;

        vector<vector<pair<int, int>>> X(n), Y(m);

        dp = vector<vector<vector<int>>> (4, vector<vector<int>> (n, vector<int> (m)));

        for(int j = 0; j < m; j++) dp[0][0][j] = in[0][j] == '*';

        for(int i = 1; i < n; i++) for(int j = 0; j < m; j++) dp[0][i][j] = (in[i][j] == '*' ? dp[0][i - 1][j] + 1 : 0);

        for(int j = 0; j < m; j++) dp[1][n - 1][j] = in[n - 1][j] == '*';

        for(int i = n - 2; i >= 0; i--) for(int j = 0; j < m; j++) dp[1][i][j] = (in[i][j] == '*' ? dp[1][i + 1][j] + 1 : 0);
        
        for(int i = 0; i < n; i++) dp[2][i][0] = in[i][0] == '*';

        for(int i = 0; i < n; i++) for(int j = 1; j < m; j++) dp[2][i][j] = (in[i][j] == '*' ? dp[2][i][j - 1] + 1 : 0);

        for(int i = 0; i < n; i++) dp[3][i][m - 1] = in[i][m - 1] == '*';

        for(int i = 0; i < n; i++) for(int j = m - 2; j >= 0; j--) dp[3][i][j] = (in[i][j] == '*' ? dp[3][i][j + 1] + 1 : 0);
        vector<vector<int>> ans; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int mn = infinity;

                if(i == 0 or j == 0 or i == n - 1 or j == m - 1) continue;

                if(in[i][j] != '*') continue;

                amin(mn, dp[0][i - 1][j]);

                amin(mn, dp[1][i + 1][j]);

                amin(mn, dp[2][i][j - 1]);

                amin(mn, dp[3][i][j + 1]);

                if(mn){
                    ans.push_back({i + 1, j + 1, mn});

                    X[i].push_back({j - mn, j + mn});

                    Y[j].push_back({i - mn, i + mn});
                }
            }       
        }
        // cout << "OK"; cout.flush();
        if(! check(in, X, Y)){cout << -1 << endl; return;}

        cout << sz(ans) << endl; 

        for(auto p : ans){ for(auto q : p) cout << q << ' '; cout << endl;} 
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