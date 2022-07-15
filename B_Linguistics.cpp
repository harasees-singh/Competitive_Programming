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

void reduce(int i, vector<int> &f, int j, vector<vector<int>> &F, int delta){
    for(auto &p : F[j]){
        int put = min(f[i], max(0ll, (p - delta) / 2));

        f[i] -= put; 

        p -= put * 2;
    }
}

void slv(){
        vi f(4); cin >> f; 

        string s; cin >> s; 

        if(count(all(s), 'A') != f[0] + f[2] + f[3] or count(all(s), 'B') != f[1] + f[2] + f[3]){
            cout << "NO" << endl; return;
        }

        char lst = '1';

        vector<vector<int>> F(3); // AB, BA, ABA or BAB;
        int n = sz(s);
        s.push_back(s.back());
        int cnt = 1; 

        for(int i = 0; i < n; i++){
            if(s[i] != s[i + 1]){
                cnt++;
            }
            else{
                if(cnt % 2 == 0){
                    F[1 - (s[i] - 'A')].push_back(cnt);
                }
                else F[2].push_back(cnt);

                cnt = 1;
            }
        }
        for(auto &p : F) sort(all(p));
        reduce(2, f, 0, F, 0);

        reduce(3, f, 1, F, 0); // fav

        reduce(2, f, 2, F, 0);

        reduce(3, f, 2, F, 0); // all

        reduce(2, f, 1, F, 2);

        reduce(3, f, 0, F, 2); // unfav

        if(f[2] or f[3]){
            cout << "NO" << endl; return;
        }
        cout << "YES" << endl;
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