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
struct SegTree{
    // query zero based, lazy propagation implememted.
    // Update adds delta to the range l, r 
    // query returns max value in the range l, r and the index at which it occurs.

    // nodes 1 based (dw if only using superficially)
    int N;
    vector<pii> t;
    vector<int> a;
    vector<int> lazy; 

    
    SegTree(vector<int> &a){
        this->a = a;
        N = a.size();
        t = vector<pii> (4 * N + 5);
        lazy = vector<int> (4 * N + 5);
        build(1, 0, N - 1);
    }

    void build(int v, int tl, int tr) {
        if(tl == tr) 
            t[v].ff = a[tl], t[v].ss = tl;
        
        else {
                int tm = (tl + tr) / 2;
                
                build(v * 2, tl, tm);
                
                build(v * 2 + 1, tm + 1, tr);

                t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
    void push(int v) {
        t[v * 2].ff += lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1].ff += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }


    void Update(int l, int r, int delta){
        update(1, 0, N - 1, l, r, delta);
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v].ff += addend;
            lazy[v] += addend;
        } else {
                push(v);
                int tm = (tl + tr) / 2;
                update(v * 2, tl, tm, l, min(r, tm), addend);
                update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
                
                t[v] = max(t[v * 2], t[v * 2 + 1]);

        }
    }
    pii Query(int l, int r){
        return query(1, 0, N - 1, l, r);
    }

    pii query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return {-infinity, -1};
        if (l <= tl && tr <= r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        pii f = query(v * 2, tl, tm, l, min(r, tm)), s = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r); 
        
        return max(f, s);
    }

};
void slv(){
        int n; 

        cin >> n; 

        map<int, vector<pair<int, int>>> M; 

        set<int> unique;

        for(int i = 0; i < n; i++){
                int x, y, c; 

                cin >> x >> y >> c; 

                if(x < y) swap(x, y);

                M[x].push_back(make_pair(y, c));

                unique.insert(y);
        }
        vector<int> f; 

        for(auto p : unique) f.push_back(p);

        unique.clear();

        SegTree T(f);
        pii ans = {2e9, 2e9}; int mx = 0;
        for(auto &p : M){
                int id = p.first;

                for(auto &q : p.second){
                        T.Update(0, lower_bound(all(f), q.first) - f.begin(), q.second);
                }
                // for(int i = 0; i < f.size(); i++) cout << T.Query(i, i) << ' '; cout << endl;
                auto ret = T.Query(0, upper_bound(all(f), id) - f.begin() - 1); 
                int val = ret.ff - id;

                if(val > mx){
                        mx = val;

                        // cout << id << ' ';

                        // cout << ret << endl;

                        ans = {f[ret.ss], id};
                }

        }
        cout << mx << endl; cout << ans.ff << ' ' << ans.ff << ' ' << ans.ss << ' ' << ans.ss;
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