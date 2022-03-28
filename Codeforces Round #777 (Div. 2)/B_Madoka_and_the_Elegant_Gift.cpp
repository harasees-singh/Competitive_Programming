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

vector<string> mat;
vector<vector<bool>> vis;
int N, M;

bool check(int i, int j, int n, int m){
    for(int r = i; r <= n; r++){
        for(int c = j; c <= m; c++){
            if(mat[r][c] == '0') return false;

            vis[r][c] = 1;
        }
        if(m + 1 < M and mat[r][m + 1] == '1') return false; 
    }
    if(n + 1 < N)
        for(int c = j; c <= m; c++) {
            if(mat[n + 1][c] == '1') return false; 
        }
    
    if(i - 1 >= 0) 
        for(int c = j; c <= m; c++) {
            if(mat[i - 1][c] == '1') return false;
        }
    if(j - 1 >= 0) for(int r = i; r <= n; r++) if(mat[r][j - 1] == '1') return false;

    return true;
}
void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(not vis[i][j] and mat[i][j] == '1'){
                int itr;
                for(itr = i; itr < N; itr++) if(mat[itr][j] == '0') break; 

                int itc;
                // cout << mat[i][1] << endl;
                for(itc = j; itc < M; itc++) if(mat[i][itc] == '0') break;

                // cout << i << ' ' << j << ' ' << itr << ' ' << itc << endl;
                if(not check(i, j, itr - 1, itc - 1)){
                    cout << "NO" << endl; return;
                }
            }
        }
    }
    cout << "YES" << endl; return;
}
int32_t main(){
        
        FIO
        w(t){
            cin >> N >> M;
            mat = vector<string> (N, string(M, '0'));
            vis = vector<vector<bool>> (N, vector<bool> (M));

            for(auto &p : mat) for(auto &q : p) cin >> q;

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