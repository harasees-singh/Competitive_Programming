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

int N, M;

vector<string> mat;
vector<vector<int>> dp;

bool safe(int i, int j){
    if(!(i >= 0 and i < N and j >= 0 and j < M)) return false;
    bool left = j == 0 or mat[i][j - 1] == '.';
    bool right = j == M - 1 or mat[i][j + 1] == '.';
    bool up = i == 0 or mat[i - 1][j] == '.';
    bool down = i == N - 1 or mat[i + 1][j] == '.';

    return left and right and up and down;
}

vector<vector<bool>> direction;

int cnt = 0;

void mark(int i, int j){
    // cout << i << ' ' << j << endl; cout.flush();
    // assert(i >= 0 and i < N and j < M and j >= 0);
    cnt += mat[i][j] == '.';
    mat[i][j] = '#';

    if(j == M - 1) return;

    mark(i + (direction[i][j] ? -1 : 1), j + 1);
}

int dfs(int i, int j){
    if(j == M - 1){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    // assertion: i, j is cactus;
    int put = infinity;

    bool up = true;

    if(safe(i - 1, j + 1)){
        int ne = (mat[i - 1][j + 1] == '.') + dfs(i - 1, j + 1);
        amin(put, ne);
    }
    if(safe(i + 1, j + 1)){
        int se = (mat[i + 1][j + 1] == '.') + dfs(i + 1, j + 1);
        up = se > put;
        amin(put, se);
    }
    direction[i][j] = up;

    return dp[i][j] = put;
}

void slv(){
        int n, m; cin >> n >> m; 

        cnt = 0;

        N = n, M = m;

        mat = vector<string> (n); cin >> mat;

        dp = vector<vector<int>> (n, vector<int> (m, -1));
        direction = vector<vector<bool>> (n, vector<bool> (m)); // go up or not
        int ans = infinity;

        int p = -1;
        for(int j = 0; j < n; j++){
            if(safe(j, 0)){
                int semi_ans = dfs(j, 0) + (mat[j][0] == '.');

                if(semi_ans < ans) ans = semi_ans, p = j; 
            }
        }

        if(ans == infinity){
            cout << "NO" << endl; return;
        }
        cout << "YES" << endl;

        mark(p, 0);
        assert(cnt == ans);

        for(auto p : mat) cout << p << endl;
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