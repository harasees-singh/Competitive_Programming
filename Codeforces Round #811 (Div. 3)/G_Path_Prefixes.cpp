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
vector<int> pref; 
vector<int> ans; 
vector<vector<int>> g;
vector<vector<int>> A, B; 

void dfs(int i, int AA, int BB, int pt, int id){
    
    ans[i] = upper_bound(pref.begin(), pref.begin() + id, AA) - pref.begin() - 1;

    for(int j = 0; j < sz(g[i]); j++){
        int p = g[i][j];

        pref[id] = (B[i][j]) + pref[id - 1];

        dfs(p, AA + A[i][j], BB, pt, id + 1);
    }
    return;
}
void slv(){
        int n; cin >> n; 
        
        for(int i = 2; i <= n; i++){
            int p; cin >> p; 

            int a, b; cin >> a >> b; 
            
            A[p].push_back(a);
            B[p].push_back(b);

            g[p].push_back(i);
        }

        dfs(1, 0, 0, 0, 1);

        for(int i = 2; i <= n; i++){
            cout << ans[i] << ' ';
        }
        for(int i = 1; i <= n; i++) g[i] = {}, A[i] = {}, B[i] = {};
        cout << endl;
}

int32_t main(){
        
        FIO
        int n = 2e5;

        pref = vector<int> (n + 1);

        g = vector<vector<int>>(n + 1);
        A = vector<vector<int>> (n + 1), B = vector<vector<int>> (n + 1); 

        ans = vector<int> (n + 1);


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