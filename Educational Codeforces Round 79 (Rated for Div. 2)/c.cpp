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

struct SegmentTreeCustom{
    vector<vector<int>> t; 

    int N;

    SegmentTreeCustom(vector<int>& in){
        N = 4 * in.size() + 5;

        t = vector<vector<int>> (N);

        build(0, 0, in.size() - 1, in);
    }
    int cnt(vector<int> &v, int ele){
        return upper_bound(v.begin(), v.end(), ele) - v.begin();
    }
    vector<int> add(vector<int> &a, vector<int> &b){
        vector<int> ret(a); for(auto p : b) ret.push_back(p);
        sort(ret.begin(), ret.end());

        return ret;
    }
    void build(int v, int tl, int tr, vector<int> &in){
        if(tl > tr) return;

        if(tl == tr){
            t[v] = {in[tl]};

            return;
        }

        int mid = (tl + tr) / 2; 

        // tl to mid - 1 and mid to tr

        build(2 * v + 1, tl, mid, in);
        build(2 * v + 2, mid + 1, tr, in);

        t[v] = add(t[2 * v + 1], t[2 * v + 2]);

        return;
    }
    int query(int v, int tl, int tr, int l, int r, int w){
        // number of ele less than equal to w
        if(tl > tr or tl > r or tr < l) return 0;

        if(tl >= l and tr <= r) return cnt(t[v], w);

        int mid = (tl + tr) / 2;

        return query(2 * v + 1, tl, mid, l, r, w) + query(2 * v + 2, mid + 1, tr, l, r, w);
    }       
};
void slv(){
        int n; cin >> n; 

        vector<int> in(n);

        cin >> in;

        SegmentTreeCustom T(in);

        cout << "build successful" << endl; cout.flush();

        int Q; cin >> Q;

        for(int i = 0; i < Q; i++){
            int j; cin >> j;

            if(j == 2){
                int l, r, w; cin >> l >> r >> w;

                cout << T.query(0, 0, n - 1, l, r - 1, w) << endl;
            }
            else{
                int id, put; cin >> id >> put; 

                cout << "UNDER CONSTRUCTION" << endl;
            }
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