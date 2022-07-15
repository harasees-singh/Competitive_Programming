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
int lookupMN(vector<vi>& MN, int l, int r, vi &in){

    int n=1;

    int count = 0;

    while(n<<1 < (r-l+1)) n <<= 1, count++;

    return in[MN[count][l]] < in[MN[count][r - n + 1]] ? MN[count][l] : MN[count][r - n + 1];
    
}
int lookupMX(vector<vi>& MN, int l, int r, vi &in){

    int n=1;

    int count = 0;

    while(n<<1 < (r-l+1)) n <<= 1, count++;

    // return __gcd(table[count][l], table[count][r - n + 1]);
    return in[MN[count][l]] > in[MN[count][r - n + 1]] ? MN[count][l] : MN[count][r - n + 1];
    
}

void slv(){
    int lg = 1;

    int n; cin >> n; vi in(n); cin >> in;

    while((1 << lg) < sz(in)) lg++;

    vector<vi> MN(lg + 1, vi(sz(in)+1));
    vector<vi> MX(lg + 1, vi(sz(in)+1));

    for(int i = 1; i < sz(in)+1; i++){MN[0][i] = i - 1; MX[0][i] = i - 1;}

    // 1 based indexing
    for(int i = 0; i < lg; i++)
        for(int j = 1; j < sz(in) - (1<<i) + 1; j++){

            MN[i+1][j] = (in[MN[i][j]] < in[MN[i][j + (1<<i)]] ? MN[i][j] : MN[i][j + (1<<i)]);
        } 
    for(int i = 0; i < lg; i++)
        for(int j = 1; j < sz(in) - (1<<i) + 1; j++){

            MX[i+1][j] = (in[MX[i][j]] > in[MX[i][j + (1<<i)]] ? MX[i][j] : MX[i][j + (1<<i)]);
        }
    
    queue<int> Q;

    // nxt greater and nxt smaller

    vi nxtG(n), nxtS(n);

    in.push_back(infinity);

    stack<int> G; G.push(n);

    for(int i = n - 1; i >= 0; i--){
        while(in[G.top()] < in[i]) G.pop();

        nxtG[i] = G.top();

        G.push(i);
    }
    Q.push(0);

    in.pop_back(); in.push_back(0);

    stack<int> S; S.push(n);

    for(int i = n - 1; i >= 0; i--){
        while(in[S.top()] > in[i]) S.pop();

        nxtS[i] = S.top();

        S.push(i);
    }
    vi d(n);

    while(1){
        int f = Q.front(); Q.pop();

        if(f==n-1){
            cout << d[f] << endl; return;
        }
        int s = nxtS[f];


        int mx = lookupMX(MX, f + 1, s, in);


        if(not d[mx] and mx != f){
            d[mx] = d[f] + 1;

            Q.push(mx);
        }

        int g = nxtG[f];


        int mn = lookupMN(MN, f + 1, g, in);

        if(not d[mn] and mn != f){
            d[mn] = d[f] + 1;

            Q.push(mn);
        }

        if(d[f + 1]==0){
            d[f + 1]=d[f]+1; Q.push(f + 1);
        }
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