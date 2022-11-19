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
vector<vector<int>> dp;
string s;
int dfs(int i, int j){
    // always make both moves 
    // first alice then bob     
    // total 4 calls

    // max internal, min overall

    if(j - i == 1){
        // base case
        if(s[j] != s[i]) return 0;

        return 1;
    }
    // case 1
    if(dp[i][j] != -1) return dp[i][j];
    // ll, lr, rl, rr

    int LL = dfs(i + 2, j);

    if(LL == 1){
        LL = (s[i] < s[i + 1] ? 0 : (s[i] == s[i + 1] ? 1 : 2));
    }
    int LR = dfs(i + 1, j - 1);

    if(LR == 1){
        LR = (s[i] < s[j] ? 0 : (s[i] == s[j] ? 1 : 2));
    }
    int RL = dfs(i + 1, j - 1);

    if(RL == 1){
        RL = (s[i] < s[j] ? 2 : (s[i] == s[j] ? 1 : 0));
    }
    int RR = dfs(i, j - 2);

    if(RR == 1){
        RR = (s[j] < s[j - 1] ? 0 : (s[j] == s[j - 1] ? 1 : 2));
    }   

    return dp[i][j] = min(max(LR, LL), max(RR, RL));
}

void slv(){
        cin >> s; 
        int n = s.size();

        dp = vector<vector<int>> (n, vector<int> (n, -1));

        // dp[0][i][j] stores if Alice has to make a move on the substring [i, j] then does the game end in draw or Alice or Bob

        // 0 if alice 1 if draw and 2 if bob
        cout << (dfs(0, n - 1) == 0 ? "Alice" : (dfs(0, n - 1) == 1 ? "Draw" : "Bob")) << endl;
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