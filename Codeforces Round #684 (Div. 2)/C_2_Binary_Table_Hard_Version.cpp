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
vector<vi> op;
vector<string> in;
void flip(int i, int j){
        in[i][j] = (in[i][j] == '1' ? '0' : '1');
}
vector<vi> chain; 

vi move(int i, int j, int x, int y){
        vi ret; 
        for(int dx = 0; dx < 2; dx++) for(int dy = 0; dy < 2; dy++)
                if(x != i + dx or y != j + dy){
                        flip(i + dx, j + dy);
                        ret.push_back(i + dx + 1); ret.push_back(j + dy + 1);
                }
        assert(sz(ret) == 6);

        return ret;
}
bool get(int i, int j, int c){
        if(c == 5) return false;

        int cnt = 0;
        for(int dx = 0; dx < 2; dx++) for(int dy = 0; dy < 2; dy++){
                cnt += in[i + dx][j + dy] == '0';
        }
        if(cnt == 4){
                return true;
        }

        for(int dx = 0; dx < 2; dx++) for(int dy = 0; dy < 2; dy++){
                chain.push_back(move(i, j, i + dx, j + dy));
                if(get(i, j, c + 1)) return true;

                move(i, j, i + dx, j + dy);

                chain.pop_back();
        }
        return false;
}
void slv(){
        int n, m; cin >> n >> m; 

        in = vector<string> (n);

        op.clear();

        cin >> in;

        if(n % 2){
                for(int j = m - 1; j >= 1; j--){
                        if(in[n - 1][j] == '1'){
                                op.push_back({n - 1, j + 1 - 1, n, j + 1 - 1, n, j + 1});

                                flip(n - 2, j - 1); flip(n - 1, j - 1); flip(n - 1, j);
                        }
                }
                if(in[n - 1][0] == '1'){
                        op.push_back({n - 1, 1, n - 1, 2, n, 1});

                        flip(n - 1, 0); flip(n - 2, 0); flip(n - 2, 1);
                }
                in.pop_back();

                n--;
        }
        if(m % 2){
                for(int j = n - 1; j >= 1; j--){
                        if(in[j][m - 1] == '1'){
                                op.push_back({j, m - 1, j, m, j + 1, m});

                                flip(j - 1, m - 2); flip(j - 1, m - 1); flip(j, m - 1);
                        }
                }
                if(in[0][m - 1] == '1'){
                        op.push_back({1, m - 1, 2, m - 1, 1, m});

                        flip(0, m - 1); flip(0, m - 2); flip(1, m - 2);
                }
                for(auto &p : in) p.pop_back();

                m--;
        }
        for(int i = 0; i < n; i += 2){
                for(int j = 0; j < m; j += 2){
                        chain.clear();

                        assert(get(i, j, 0)); 

                        for(auto &p : chain) 
                                op.push_back(p);
                }
        }
        // for(auto &p : in) for(auto q : p) assert(q == '0');
        cout << sz(op) << endl; 

        for(auto &p : op) {for(auto q : p) cout << q << ' '; cout << endl;}
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