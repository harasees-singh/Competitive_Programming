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
// map<int, vector<vector<int>>> f; // {x, {{y, z, index}, ...}}
// map<int, map<int, set<pair<int, int>>>> f;
// map<int, map<int, set<pair<int, int>>>> // x, map {z, Index} corres to y
map<int, map<int, vector<pair<int, int>>>> f; // x, y : {{z1, i1}, {z2, i2}, ...}
void slv(){
        // sort along x, for each x we get a y-z plane
        // for each y-z plane take a point, find the closest y, if multiple points find the closest z
        // pick alternatives
        // if len odd let leave q last one
        // pair along x
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int x, y, z; cin >> x >> y >> z;

            // f[x].push_back({y, z, i + 1});
            f[x][y].push_back({z, i + 1});
        }
        vector<int> X;
        for(auto &p : f){
            // sort(all(p.second));

            auto &MAP = p.second;

            vector<int> Y;

            for(auto &q : MAP){
                sort(all(q.second));

                while(q.second.size() > 1){
                    // pop in pairs
                    cout << q.second.back().second << ' '; 
                    q.second.pop_back(); 

                    cout << q.second.back().second << endl; 
                    q.second.pop_back(); 
                }
                if(q.second.size()) Y.push_back(q.second.back().second);
            }
            for(int i = 0; i + 1 < Y.size(); i += 2){
                cout << Y[i] << ' ' << Y[i + 1] << endl;
            }
            if(Y.size() & 1){
                X.push_back(Y.back());
            }
        }
        assert(X.size() % 2 == 0);

        for(int i = 0; i < sz(X); i += 2){
            cout << X[i] << ' ' << X[i + 1] << endl;
        }
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