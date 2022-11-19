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
vector<int> sum, XOR;
int get(int l, int r){
    return (sum[r] - sum[l - 1] - (XOR[r] xor XOR[l - 1]));
}
int find_R(int l, int R){
    int D = get(l, R); // ok

    int Rl = l, Rr = R; // r

    while(Rl <= Rr){
        int mid = (Rl + Rr) / 2;

        int have = get(l, mid);

        if(have < D){
            Rl = mid + 1;
        }
        else Rr = mid - 1;
    }
    assert(Rl <= R);
    return Rl;
}
void slv(){
        int n, q; cin >> n >> q; 

        vector<int> in(n + 1); for(int i = 1; i <= n; i++) cin >> in[i];

        sum = vector<int> (n + 1);
        
        XOR = vector<int>(n + 1);

        for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + in[i];
        for(int i = 1; i <= n; i++) XOR[i] = XOR[i - 1] xor in[i];
    
        set<int> NON_ZERO;

        for(int i = 1; i <= n; i++){
            if(in[i]){
                NON_ZERO.insert(i);
            }
        }
        for(int i = 0; i < q; i++){
            int L, R; cin >> L >> R;

            pair<int, int> ans = {L, R};

            int need = get(L, R);

            if(need == 0){
                cout << L << ' ' << L << endl; continue;
            }

            auto it = NON_ZERO.lower_bound(L);

            for(int j = 0; it != NON_ZERO.end() and *it <= R and get(*it, R) == need and j < 32; it++, j++){
                int l = *it;
                int r = find_R(l, R);

                if(r - l < ans.second - ans.first){
                    ans = {l, r};
                }
            }
            cout << ans << endl;
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