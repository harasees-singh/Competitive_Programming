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

int32_t main(){
        
        FIO

        w(T){
            int n, m; cin >> n >> m;

            vi fence(n); for(auto &p : fence) cin >> p;

            vi col(n); for(auto &p : col) cin >> p;

            vi have(m); for(auto &p : have)  cin >> p;

            vector<vi> req(n + 1);

            for(int i = 0; i < n; i++){
                if(col[i] != fence[i]) req[col[i]].push_back(i);
            }
            int lstcol = have.back(), sentinel;
            // if(req[lstcol].size() == 0)
            vi ans(m);
            if(req[lstcol].empty()){
                int id = find(all(col), lstcol) - col.begin();

                if(id == n){

                    cout << "NO" << endl; continue;
                }
                else{
                    sentinel = ans[m - 1] = id;
                }
            }
            else{
                fence[req[lstcol].back()] = lstcol;

                ans[m - 1] = sentinel = req[lstcol].back();

                req[lstcol].pop_back();
            }
            for(int i = m - 2; i >= 0; i--){
                if(req[have[i]].size()){
                    int id = req[have[i]].back(); req[have[i]].pop_back();

                    ans[i] = id; 

                    fence[id] = have[i];
                }
                else{
                    ans[i] = sentinel;
                }
            }
            if(fence == col){
                cout << "YES" << endl;

                for(auto p : ans) cout << p + 1 << ' '; cout << endl;
            }
            else cout << "NO" <<endl;
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