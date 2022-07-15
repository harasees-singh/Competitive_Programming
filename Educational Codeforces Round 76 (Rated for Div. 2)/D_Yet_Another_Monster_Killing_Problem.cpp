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
struct FenwickTreeMax {
    vector<int> bit;
    int n;
    const int INF = -(int)1e9;

    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMax(vector<int> a) : FenwickTreeMax(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int MX(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};
int lookupMX(vector<vi>& MN, int l, int r, vi &in){

    int n=1;

    int count = 0;

    while(n<<1 < (r-l+1)) n <<= 1, count++;

    return max(MN[count][l], MN[count][r - n + 1]);
    
}

void slv(){
        int n; cin >> n; 

        vi in(n); cin >> in;

        int m; cin >> m; 

        vi P(n + 1); // power corres to endurance

        for(int i = 0; i < m; i++){
                int p, s; cin >> p >> s; 
                
                amax(P[s], p);
        }
        reverse(all(P)); // for endurance x seek n - x index;

        FenwickTreeMax ft(P);

        // cout << ft.MX(6 - 1) << endl;

        int lg = 1;

        while((1 << lg) < sz(in)) lg++;

        vector<vi> MN(lg + 1, vi(sz(in)+1));

        for(int i = 1; i < sz(in)+1; i++){MN[0][i] = in[i - 1];}
        // 1 based indexing

        for(int i = 0; i < lg; i++)
                for(int j = 1; j < sz(in) - (1<<i) + 1; j++){

                        MN[i+1][j] = max(MN[i][j], MN[i][j + (1<<i)]);
                } 
        int days = 0;
        for(int i = 0; i < n; days++){
                int l = i, r = n - 1; 

                while(l <= r){
                        int mid = (l + r)/2;

                        int seek = mid - i + 1;

                        int mx = lookupMX(MN, i + 1, mid + 1, in);

                        int cand = ft.MX(n - seek);

                        if(cand >= mx) l = mid + 1;

                        else r = mid - 1;
                }

                if(i==r + 1){
                        cout << -1 << endl; return;
                }
                i = r + 1;
        }
        cout << days << endl;
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