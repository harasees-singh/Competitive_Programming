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
vi in;
struct SparseTable{
    // 1 based indexing
    vector<vector<int>> M;
    vector<vector<int>> Midx;
    int lg = 1;
    vector<int> in;

    SparseTable(vector<int> &I){
        in = I;

        while((1 << lg) < sz(in)) lg++;

        M = vector<vector<int>> (lg + 1, vector<int> (sz(in) + 1));
        
        for(int i = 1; i < sz(in) + 1; i++)
            M[0][i] = in[i - 1];

        for(int i = 0; i < lg; i++)
            for(int j = 1; j < sz(in) - (1 << i) + 1; j++)
                M[i + 1][j] = __gcd(M[i][j], M[i][j + (1 << i)]);
        
    }

    int read(int l, int r){
        assert(l <= r and l > -1);
        
        int n = 1, count = 0;
      
        while(n << 1 < (r - l + 1)) n <<= 1, count++;

        return __gcd(M[count][l], M[count][r - n + 1]);
    }
};
void slv(){
        int n; cin >> n;  

        in = vi(n);

        cin >> in; 

        SparseTable T(in);

        int lst = -1; 
        int pref = 0;
        for(int i = 0; i < n; i++){
            int l = lst + 1, r = i;

            while(l <= r){
                int mid = (l + r) / 2;

                if(T.read(mid + 1, i + 1) >= i - mid + 1) r = mid - 1;

                else l = mid + 1;
            }
            if(T.read(l + 1, i + 1) == i - l + 1){
                ++pref;
                lst = i;
            }
            cout << pref << ' ';
            
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