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

        int n; cin >> n;

        string a, b; cin >> a >> b;

        vi have(4); // 1s, 0s, all 1s, all 0s
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){
                have[(a[i] == '1' ? 2 : 3)]++;
            }
            else{
                have[(a[i] == '1' ? 0 : 1)]++;
            }
        }
        if(have[0] > n/2 or have[1] > n/2){
            cout << -1; return 0;
        }
        for(int x = 0; x <= n/2; x++){
            int allones = have[2];
            vi ans;
            if(allones > 2 * x) continue;

            int first = min({2 * x - allones, have[0], x});

            int need = 2 * x - first - allones; 
            if (have[0] + have[1] + allones < 2*x) continue;
            // cout << x << ' ' << first << ' ' << need << endl; 
            if(have[1] < need) continue;

            // if(need + first + allones < 2 * x) continue;

            int put = min(x - first, have[2]);
            // if (have[1] - need + put + first > n/2) continue;
            for(int i = 0; i < n and first; i++){
                if(a[i] == '1' and b[i] == '0'){
                    first--; ans.push_back(i + 1);
                }
            }
            for(int i = 0; i < n and put; i++){
                if(a[i] == '1' and b[i] == '1'){
                    put--; ans.push_back(i + 1);
                }
            }
            int get = 0; 
            for(int i = 0; i < n and get < have[1] - need; i++){
                if(a[i] == '0' and b[i] == '1'){
                    get++; ans.push_back(i + 1);
                }
            }
            int final = max(0ll, n/2 - sz(ans));

            for(int i = 0; i < n and final; i++){
                if(a[i] == b[i] and a[i] == '0'){
                    final--; ans.push_back(i + 1);
                }
            }
            if (sz(ans) != n/2) continue;
            assert(sz(ans) == n/2);
            for(auto p : ans) cout << p << ' '; return 0;
        }
        cout << -1;
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/