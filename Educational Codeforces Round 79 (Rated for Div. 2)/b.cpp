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

int sq(int x){
    return x * x;
}

void slv(){
        
        int x, y, r, R, a, b, r1, R1;

        cin >> x >> y >> r >> R >> a >> b >> r1 >> R1; 

        int distSquare = sq(x - a) + sq(y - b);
        if(distSquare == 0 and min(R1, R) == max(r1, r)){
            cout << 2 << endl; return;
        }

        if(distSquare >= sq(R1 + R)){
            cout << 4 << endl; return;
        }   
        if(r > R1){
            if(distSquare <= sq(r - R1)){
                cout << 4 << endl; return;
            }
        }
        if(r1 > R){
            if(distSquare <= sq(r1 - R)){
                cout << 4 << endl; return;
            }
        }
        if(sq(max(R1 + r, r1 + R)) <= distSquare and distSquare <= sq(R1 + R)){
            cout << 2 << endl; return;
        }
        if(sq(max(r1 + R, r + R1)) >= distSquare and sq(min(r1 + R, r + R1)) <= distSquare){
            cout << 1 << endl; return;
        }
        if(sq(r1 - r) >= distSquare and sq(R1 - R) <= distSquare){
            cout << 1 << endl; return;
        }
        cout << 0 << endl; return;
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