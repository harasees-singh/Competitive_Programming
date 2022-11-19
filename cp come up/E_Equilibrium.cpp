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
vector<int> a, b, in;

// hehe :)
struct Data{
    pair<int, int> sum, pref, suff, ans;
};
struct SegTreeMaxSubSum{
    // zero based indexing

    vector<Data> t;
    vector<int> a;

    SegTreeMaxSubSum(const vector<int> &in){
        a = in;
        t = vector<Data> (in.size() * 4); 
        build(1, 0, sz(a) - 1);
    }
    Data make_Data (int val) {
        Data res;
        res.sum = {val, val};
        res.pref = res.suff = res.ans = {max(0ll, val), min(0ll, val)};
        return res;
    }
    Data combine (Data l, Data r) {
        Data res;
        res.sum = {l.sum.first + r.sum.first, l.sum.second + r.sum.second};
        res.pref = {max(l.pref.first, l.sum.first + r.pref.first), min(l.pref.second, l.sum.second + r.pref.second)};
        res.suff = {max(r.suff.first, r.sum.first + l.suff.first), min(r.suff.second, r.sum.second + l.suff.second)};

        res.ans.first = max(max(l.ans.first, r.ans.first), l.suff.first + r.pref.first);
        res.ans.second = min(min(l.ans.second, r.ans.second), l.suff.second + r.pref.second);
        return res;
    }
    void build(int v, int tl, int tr) {
        if (tl == tr)
            t[v] = make_Data(a[tl]);
        else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);

            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = make_Data(new_val);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);

            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    Data query(int v, int tl, int tr, int l, int r) {
        if (l == tl && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;

        if (r <= tm)
            return query(v * 2, tl, tm, l, r);
        if (l > tm)
            return query(v * 2 + 1, tm + 1, tr, l, r);
        return combine(query(v * 2, tl, tm, l, tm), query(v * 2 + 1, tm + 1, tr, tm + 1, r));
    }

    Data Query(int l, int r){
        return query(1, 0, sz(a) - 1, l, r);
    }
    void Update(int i, int d){
        update(1, 0, sz(a) - 1, i, d);
    }
};
struct SparseTable{
    // 1 based indexing
    vector<vector<int>> M, M_;
    int lg = 1;
    vector<int> in;
 
    SparseTable(vector<int> &I){
        in = I;
 
        while((1 << lg) < sz(in)) lg++;
 
        M = vector<vector<int>> (lg + 1, vector<int> (sz(in) + 1));
        M_ = vector<vector<int>> (lg + 1, vector<int> (sz(in) + 1));
        
        for(int i = 1; i < sz(in) + 1; i++)
            M[0][i] = in[i - 1];
        for(int i = 1; i < sz(in) + 1; i++)
            M_[0][i] = in[i - 1];
            
        for(int i = 0; i < lg; i++)
            for(int j = 1; j < sz(in) - (1 << i) + 1; j++)
                M[i + 1][j] = min(M[i][j], M[i][j + (1 << i)]);
        for(int i = 0; i < lg; i++)
            for(int j = 1; j < sz(in) - (1 << i) + 1; j++)
                M_[i + 1][j] = max(M_[i][j], M_[i][j + (1 << i)]);
        
    }
    int read_MN(int l, int r){
        assert(l <= r and l > -1);
        
        int n = 1, count = 0;
      
        while((n << 1) < (r - l + 1)) n <<= 1, count++;
 
        return min(M[count][l], M[count][r - n + 1]);
    }
    int read_MX(int l, int r){
        assert(l <= r and l > -1);
        
        int n = 1, count = 0;
      
        while((n << 1) < (r - l + 1)) n <<= 1, count++;
 
        return max(M_[count][l], M_[count][r - n + 1]);
    }
};
int prefSum(int i, int j, const vector<int> &in){
    assert(i >= 0 and j < sz(in) and i <= j);

    return in[j] - (i ? in[i - 1] : 0);
}
int suffSum(int i, int j, const vector<int> &in){
    return in[i] - (j == sz(in) - 1 ? 0 : in[j + 1]);
}
bool prevSign(int i, int j){
    return (i < 0 and j < 0) or (i >= 0 and j >= 0);
}
void slv(){
    int n, q; cin >> n >> q;

    a = vector<int> (n), b = vector<int> (n);
    cin >> a >> b;

    in = vector<int> (n);

    for(int i = 0; i < n; i++) in[i] = a[i] - b[i];
    // need no positive prefix
    // no negative suffix
    // total sum should be zero;

    SegTreeMaxSubSum T(in);

    vector<int> pref(n), suff(n);

    int P = 0;

    for(int i = 0; i < n; i++){
        P += in[i];

        pref[i] = P;
    }
    P = 0;
    for(int i = n - 1; i >= 0; i--){
        P += in[i];

        suff[i] = P;
    }
    for(int i = 1; i < n; i++) in[i] += in[i - 1];

    SparseTable PREFIX(pref);
    SparseTable SUFFIX(suff);

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        
        if(prefSum(l - 1, r - 1, in) or PREFIX.read_MX(l, r) - (l > 1 ? pref[l - 2] : 0) > 0 or SUFFIX.read_MN(l, r) - (r <= n - 1 ? suff[r] : 0) < 0){
            cout << -1 << endl; continue;
        }
        pair<int, int> ans = T.Query(l - 1, r - 1).ans;

        cout << max(ans.first, abs(ans.second)) << endl;
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