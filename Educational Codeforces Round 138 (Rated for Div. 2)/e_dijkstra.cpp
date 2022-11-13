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
vector<string> mat;
bool safe(int i, int j){
    int N = mat.size(), M = mat[0].size();

    if(!(i >= 0 and i < N and j >= 0 and j < M)) return false;
    bool left = j == 0 or mat[i][j - 1] == '.';
    bool right = j == M - 1 or mat[i][j + 1] == '.';
    bool up = i == 0 or mat[i - 1][j] == '.';
    bool down = i == N - 1 or mat[i + 1][j] == '.';

    return left and right and up and down;
}

void slv(){
        int n, m; cin >> n >> m; 

        mat = vector<string> (n); cin >> mat;

        set<pair<int, pair<int, int>>> D;

        // cost, {x, y}
        map<pair<int, int>, bool> vis;
        // map<pair<int, int>, int> cost;
        vector<int> cost(n * m, infinity);
        map<pair<int, int>, pair<int, int>> parent;

        for(int i = 0; i < n; i++){
            if(safe(i, 0))
                D.insert(make_pair(mat[i][0] == '.', make_pair(i, 0))),
                cost[i * m] = mat[i][0] == '.';
        }
        pair<int, int> ans = {-1, -1};
        
        for(; D.size(); ){
            auto top = *D.begin();

            const int X = top.second.first, Y = top.second.second, C = top.first;

            // cout << X << ' ' << Y <<' ' << C << endl; 

            if(Y == m - 1){
                ans = {X, Y};
                // cout << C << endl;
                break;
            }

            vis[{X, Y}] = 1;

            D.erase(top);

            for(int dx = -1; dx < 2; dx += 2)
                for(int dy = -1; dy < 2; dy += 2){
                    if(safe(X + dx, Y + dy) and vis[{X + dx, Y + dy}] == 0){
                        if(cost[(X + dx) * m + Y + dy] > C + (mat[X + dx][Y + dy] == '.')){
                            // update cost and parent
                            if(D.count(make_pair(cost[(X + dx) * m + Y + dy], make_pair(X + dx, Y + dy)))){
                                D.erase(make_pair(cost[(X + dx) * m + Y + dy], make_pair(X + dx, Y + dy)));
                            }
                            parent[{X + dx, Y + dy}] = {X, Y};
                            if(X == 0 and Y == 1){
                                // cout << X + dx << ' ' << Y + dy << ' ' << C << endl;
                            }
                            cost[(X + dx) * m + Y + dy] = C + (mat[X + dx][Y + dy] == '.');

                            int newCost = cost[(X + dx) * m + Y + dy];

                            // update in the D set;
                            D.insert(make_pair(newCost, make_pair(X + dx, Y + dy)));  
                        }
                    }
                }
        }
        if(ans == make_pair(-1ll, -1ll)){
            cout << "NO" << endl; return;
        }
        cout << "YES" << endl;
        while(true){
            mat[ans.first][ans.second] = '#';

            // cout << ans.first << ' ' << ans.second << ' ' << cost[ans.first * m + ans.second] << endl;

            if(parent.count(ans) == 0) break;
            ans = parent[ans];
        }
        for(auto p : mat)
            cout << p << endl;
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