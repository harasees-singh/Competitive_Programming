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
int lookupSparseTable(vector<vi>& table, int l, int r){

    int n=1;

    if(l > r) return -infinity;

    int count = 0;

    while(n<<1 < (r-l+1)) n <<= 1, count++;

    return max(table[count][l], table[count][r - n + 1]);
    
}

void solve(){
    int N; cin >> N;
    int n=1;
    vi in(N); for(auto &p : in) cin >> p;
    vi pref(in), suff(in);

    for(int i=1; i < N; i++)
        pref[i] += pref[i-1];

    for(int i=N-2; i>=0; i--)
        suff[i] += suff[i+1];

    int count = 1;

    while(n<<1 < sz(pref)) n <<= 1, count++;

    n=count;
    vector<vi> PrefSparseTable(n + 1, vi(N + 1));
    vector<vi> SuffSparseTable(n + 1, vi(N + 1));

    l(i, 1,N+1){PrefSparseTable[0][i] = pref[i - 1];}
    l(i, 1,N+1){SuffSparseTable[0][i] = suff[i - 1];}

    // 1 based indexing
    l(i, 0, n)
        l(j, 1, N-(1<<i)+1){

            PrefSparseTable[i+1][j] = max(PrefSparseTable[i][j], PrefSparseTable[i][j + (1<<i)]);
        } 
    l(i, 0, n)
        l(j, 1, N-(1<<i)+1){

            SuffSparseTable[i+1][j] = max(SuffSparseTable[i][j], SuffSparseTable[i][j + (1<<i)]);
        } 
    int mx = infinity;


    // cout << lookupSparseTable(SuffSparseTable, 1, 4) << endl;

    vi suffmx(N);
    stack<int> S; 

    for(int i=N-1; i>=0; i--){
        int cur = in[i];

        while(S.empty() == false and in[S.top()] <= cur) S.pop();
         
        suffmx[i] = (S.empty() ? N : S.top());

        S.push(i);
    }
    S = stack<int>();

    vi prefmx(N);
    for(int i=0; i < N; i++){
        while(S.empty() == false and in[S.top()] <= in[i]) S.pop();
         
        prefmx[i] = (S.empty() ? -1 : S.top());

        S.push(i);
    }

    for(int i=0; i < N; i++){
        int cur = in[i];

        int r = suffmx[i] - 1;
        int l = prefmx[i] + 1;


        int mxl = lookupSparseTable(SuffSparseTable, l + 1, i);

        mxl -= suff[i];

        int mxr = lookupSparseTable(PrefSparseTable, i + 2, r + 1);

        mxr -= pref[i];

        if(mxl > 0 or mxr > 0){
            cout << "NO" << endl; return;
        }
    }
    cout << "YES" << endl;
}
int32_t main(){
        
        FIO
        w(T){
            solve();
        }

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/