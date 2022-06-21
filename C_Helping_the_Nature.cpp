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
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE
vector<vi> sparseTable;
int lookupSparseTable(vector<vi>& table, int l, int r, vi &in){

    int n=1;

    int count = 0;

    while(n<<1 < (r-l+1)) n <<= 1, count++;

    return in[table[count][l]] < in[table[count][r - n + 1]] ? table[count][l] : table[count][r - n + 1];
    
}
void init(vi &in){
    int lg = 1;

    while((1 << lg) < sz(in)) lg++;

    sparseTable = vector<vi> (lg + 1, vi(sz(in)+1));

    for(int i = 1; i <= sz(in); i++)
        sparseTable[0][i] = i - 1;

    // 1 based indexing
    for(int i = 0; i < lg; i++)
        for(int j = 1; j < sz(in) - (1<<i) + 1; j++){

            sparseTable[i+1][j] = in[sparseTable[i][j]] < in[sparseTable[i][j + (1<<i)]] ? sparseTable[i][j] : sparseTable[i][j + (1<<i)];
        } 
}
int ans = 0;
void div(int i, int j, vector<vi>& table, vi &in, int sub){
    if(i > j) return;

    int id = lookupSparseTable(table, i + 1, j + 1, in);

    assert(in[id] >= sub);

    ans += 3 * (in[id] - sub);

    sub = in[id];

    div(i, id - 1, table, in, sub); 
    
    div(id + 1, j, table, in, sub);
}
int get(vi in){
    int n = sz(in);

    ans = 0;

    ans += in[0];

    int lst = infinity;

    for(auto &p : in){
        amin(lst, p);

        p -= lst;
    }
    ans += in.back();

    lst = infinity;

    for(int i = n - 1; i >= 0; i--){
        amin(lst, in[i]);

        in[i] -= lst;
    }
    init(in);

    div(0, n - 1, sparseTable, in, 0);
    // cout << "OK" << endl; cout.flush();

    return ans;
}
void slv(){
    int n; cin >> n; vi in(n);


    for(auto &p : in)
        cin >> p;

    int L = *min_element(all(in));

    int ans = 0;

    if(L < 0){
        ans += (-L);
        for(auto &p : in) p -= L;
    }

    int f1 = get(in);

    // reverse(all(in));

    // int f2 = get(in);
    
    cout << ans + f1 << endl;
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