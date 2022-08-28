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
vector<string> out;
vector<string> mat;
int n, m; 
pii lst; 
void dfs(int i, int j, char put, int cnt, int limit){
    lst = {i, j};

    if(cnt == limit) return;

    if(mat[i][j] == 'R'){
        cnt++;
    }
    out[i][j] = put;
    if(j + 1 < m and out[i][j + 1] == '.'){
        dfs(i, j + 1, put, cnt, limit);

        return;
    }
    if(j - 1 >= 0 and out[i][j - 1] == '.'){
        dfs(i, j - 1, put, cnt, limit);

        return;
    }
    dfs(i + 1, j, put, cnt, limit);
}
void slv(){
    lst = {0, 0};

    string D; 

    for(auto c = 'a'; c <= 'z'; c++) D.push_back(c); for(auto c = 'A'; c <= 'Z'; c++) D.push_back(c); for(auto c = '0'; c <= '9'; c++) D.push_back(c);
    cin >> n >> m; int k; cin >> k; 
    mat = vector<string> (n);

    cin >> mat;
    out = vector<string> (n, string(m, '.'));

    int R = 0; 
    for(auto &p : mat) for(auto a : p) R += a == 'R';

    int limit = R / k;

    int extra = R % k;

    // cout << k - extra << endl;
    // cout << limit << endl; cout.flush();
    for(int i = 0; i < k; i++) dfs(lst.ff, lst.ss, D[i], 0, limit + (i >= (k - extra)));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(out[i][j] == '.'){
                if(i) out[i][j] = out[i - 1][j];

                else out[i][j] = out[i][j - 1];                
            }
            cout << out[i][j];
        }    
        cout << endl;
    }
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