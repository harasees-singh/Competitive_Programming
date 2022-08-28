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
vector<int> expand(vector<int> &a){
    vector<int> ret; 

    for(int i = 0; i < sz(a) - 1; i++){
        ret.push_back(1);
        ret.push_back(- a[i + 1] + a[i] + 1);
    }
    ret.push_back(1);

    return ret;
}
int kadane(const vector<int> &in){
    int cnt = 0; 
    int mx = 0;
    for(int i = 0; i < sz(in); i++){
        cnt += in[i];

        amax(cnt, 0ll);

        amax(mx, cnt);
    }
    return mx;
}
void slv(){
        int n; cin >> n; 

        vi in(n); cin >> in;

        map<int, vector<int>> m; 

        for(int i = 0; i < n; i++){
            m[in[i]].push_back(i);
        }
        int mx = 0;
        
        int ele = -1;

        for(auto &p : m){
            int ret = kadane(expand(p.ss));

            if(ret > mx){
                ele = p.ff; mx = ret;
            }
        }
        pii seg = {1, 1};
        int cnt = 0;
        int MX = 0;
        int l = 1, r; 
        for(int i = 0; i < n; i++){
            cnt += (in[i] == ele) - (in[i] != ele);

            if(cnt < 0){
                cnt = 0; l = i + 2;
            }
            if(cnt > MX){
                MX = cnt; 

                r = i + 1; 

                seg = {l, r};
            }
        }
        cout << ele << ' ' << seg << endl;
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