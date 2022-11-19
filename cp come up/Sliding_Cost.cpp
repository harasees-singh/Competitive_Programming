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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE

void slv(){
    int n, k; cin >> n >> k;

    vector<int> in(n); cin >> in;

    // median shifts by one only at each step

    // 2, 4, 3 and 4, 3, 5
    // median goes from 3 to 4 (1 step right) ans changes from 
    // (3 - 2) + (4 - 3) to (5 - 4) + (4 - 3);        
    // add and remove contribution of each element to the answer at each step

    pbds PBDS;

    for(int i = 0; i < k - 1; i++){
        int t = in[i]; 

        PBDS.insert(make_pair(t, i));
    }
    int ans = 0;

    int t = in[k - 1]; 

    PBDS.insert({t, k - 1});

    int median = (*PBDS.find_by_order(k / 2)).first;
    // cout << median << endl;

    for(pii p : PBDS) ans += abs(p.first - median);

    // cout << ans << ' ';
    cout << median << endl;

    for(int i = k; i < n; i++){
        // prnIter(PBDS);

        int t = in[k]; 

        PBDS.insert({t, i});

        ans += (abs(median - t));

        ans -= abs(median - in[i - k]);

        PBDS.erase(make_pair(in[i - k], i - k));

        pii Median = (*PBDS.find_by_order(k / 2));

        cout << Median.first << endl;
        int d = Median.first - median;

        ans -= d * (n - n / 2);

        ans += d * (n / 2);

        // cout << ans << ' ';
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