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

void solve(){
    int n, m; cin >> n >> m;

    vector<string> mat(n);
    for(auto &p : mat) cin >> p;

    vector<vector<bool>> vis(n, vector<bool> (m));
    vector<vector<int>> dp(n, vi(m, -1));
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(vis[i][j]) continue;
            int cur = i * m + j;

            vi path;
            bool valid=1;
            while(not vis[cur/m][cur%m]){
                vis[cur/m][cur%m] = 1;

                path.push_back(cur);

                int row=cur/m, col=cur%m;

                row += ((mat[cur/m][cur%m]=='D') - (mat[cur/m][cur%m]=='U'));
                col += ((mat[cur/m][cur%m]=='R') - (mat[cur/m][cur%m]=='L'));

                if(row==n or row<0 or col==m or col<0){
                    valid=false; break;
                }
                cur = row*m + col;
                // cout << cur << endl; cout.flush();
            }
            if(not valid) continue;

            auto it = find(all(path), cur); 

            if(it == path.end()) continue;
            int cycle = path.end() - it;
            if(not cycle) continue;
            for(int i=sz(path)-1; i>=0; i--){
                dp[path[i]/m][path[i]%m] = cycle;

                if(path[i] == cur) break;
            }
        }
    }
    // cycles done
    int ans=0;

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(dp[i][j] != -1){
                if(dp[i][j] > dp[ans/m][ans%m]) ans=i*m + j;
                continue;
            }
            stack<int> steck;
            int row=i, col=j;

            bool valid=1;
            while(dp[row][col]==-1){
                // cout << "OK"; cout.flush();
                // cout << row << ' ' << col << endl; cout.flush();
                int cur=row*m + col;
                steck.push(cur);

                row += ((mat[cur/m][cur%m]=='D') - (mat[cur/m][cur%m]=='U'));
                col += ((mat[cur/m][cur%m]=='R') - (mat[cur/m][cur%m]=='L'));

                if(row==n or row<0 or col==m or col<0){
                    valid=false;
                    break;
                }
                
            }
            int tail=0;
            if(valid){
                tail = dp[row][col];
            }
            while(steck.empty()==false){ 
                dp[steck.top()/m][steck.top()%m] = ++tail;

                if(dp[steck.top()/m][steck.top()%m] > dp[ans/m][ans%m]) ans=steck.top();    

                steck.pop();
            }
        }
    }
    
    cout << ans/m + 1 << ' ' << ans%m + 1 << ' ' << dp[ans/m][ans%m] << endl;
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