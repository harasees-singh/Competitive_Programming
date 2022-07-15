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

int n, k;
vi f;
int good(int mid, int x){
    // is this value of Y enough for k or more partitions

    // calc the amount of ele in the range x to y

    int ok = f[mid] - f[x - 1];

    int ele = n - ok;

    // 1 ele takes 2 mergers

    int partitions = n - 2 * ele;

    return (partitions >= k);
}
int get(int x){
    // returns y;

    int l = 1, r = n; 

    while(l <= r){
        int mid = (l + r) / 2;

        if(good(mid, x)){
            r = mid  - 1;
        }
        else l = mid + 1;
    }
    return l;
}
void slv(){
        cin >> n >> k; 

        vi in(n);

        f = vi(n + 1);

        for(int i = 0; i < n; i++){
            int t; cin >> t; 
            in[i] = t;
            f[t]++;
        }   
        for(int i = 1; i <= n; i++) f[i] += f[i - 1];
        pii ans = {1, infinity};
        for(int x = 1; x <= n; x++){
            int y = get(x);

            if(y <= n and y - x < ans.ss - ans.ff)
                ans = {x, y};
        }
        cout << ans << endl;


        vi pref(n + 1), suff(n + 2);

        for(int i = 0; i< n; i++){
            if(in[i] < ans.ff or in[i] > ans.ss){
                // out of range

                pref[i + 1] = pref[i] - 1;
            }
            else pref[i + 1] = pref[i] + 1;
        }
        for(int i = n - 1; i >= 0; i--){
            if(in[i] < ans.ff or in[i] > ans.ss){
                // out of range

                suff[i + 1] = suff[i + 2] - 1;
            }
            else suff[i + 1] = suff[i + 2] + 1;
        }
        int lst = 0;

        suff[n + 1] = 1;
        vector<pii> A;
        for(int i = 1; i <= n; i++){
            if(suff[i + 1] > 0 and pref[i] - pref[lst] > 0){
                // cout << lst + 1 << ' ' << i << endl; lst = i;

                A.push_back({lst + 1, i}); lst = i;
            }
        }
        int merge = sz(A) - k;

        // for(int i = merge; i ,)

        cout << A[0].ff << ' ' << A[merge].ss << endl;

        for(int i = merge + 1; i < sz(A); i++) cout << A[i] << endl;
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