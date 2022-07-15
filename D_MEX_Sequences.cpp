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
int P = 998244353;
int ADD(int i, int j) {return (i + j) % P;}

int MUL(int i, int j) {return (i * j) % P;}

int power(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = MUL(a, a)) {
        if (b % 2) {
            res = MUL(a, res);
        }
    }
    return res;
}
void slv(){
    int n; cin >> n;

    vector<vector<int>> dp(2, vector<int> (n + 1));

    vector<int> in(n); 
    cin >> in;

    int one = count(all(in), 1);

    for(auto p : in){

        if(p)
            dp[0][p] = ADD(MUL(2, dp[0][p]), dp[0][p - 1]);
        else dp[0][p] = ADD(MUL(ADD(dp[0][p], 1), 2) - 1, P);

        dp[1][p] = MUL(2, dp[1][p]);
        if(p > 1){
            dp[1][p - 2] = MUL(dp[1][p - 2], 2);
            dp[1][p - 2] = ADD(dp[1][p - 2], dp[0][p - 2]);
        }
    }
    int tot = 0; for(auto p : dp[0]) tot = ADD(tot, p);

    for(auto p : dp[1]) tot = ADD(tot, p);

    cout << ADD(ADD(tot, power(2, one) - 1), P) << endl;
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