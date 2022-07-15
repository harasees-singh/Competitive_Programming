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

void slv(){
        vi f(3); cin >> f;
        int n = accumulate(all(f), 0ll);
        vector<pbds> F(3);

        for(int i = 0; i < 3; i++){
                for(int j = 0; j < f[i]; j++){
                        int t; cin >> t; 

                        F[i].insert(t);
                }
        }
        vector<int> dp(n + 2, infinity);

        // iterate on ele of second set
        // dp[i] is the number of elements greater than i in set 2 and less than equal to i in set 3

        int loan = 0;

        for(int i = n; i >= 1; i--){
                dp[i] = F[2].order_of_key(i) + loan;

                loan += (F[1].find(i) != F[1].end());

                amin(dp[i], dp[i + 1]);
        }
        // i to something in set 2
        int ans = infinity;
        loan = 0;
        for(int i = 1; i <= n; i++){
                
                amin(ans, sz(F[0]) - F[0].order_of_key(i) + dp[i] + loan);

                loan += (F[1].find(i) != F[1].end());
        }
        // if(second set is empty);
        loan = 0;

        for(int i = 1; i <= n; i++){
                
                if(F[0].find(i) == F[0].end()) loan++;

                amin(ans, sz(F[1]) - F[1].order_of_key(i + 1) + sz(F[0]) - F[0].order_of_key(i + 1) + loan);

        }

        cout << ans << endl;
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