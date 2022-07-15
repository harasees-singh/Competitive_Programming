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
int get(int k, vi &in){
        int n = sz(in);

        assert(k >= n);

        int cyc = k / n;

        k %= n;

        vi time(n);

        int ret = 0, t = 0;
        vi vis(n);
        for(int i = k; i>=0; i--){
                ret += t - time[i];

                time[i] = t++;

                if(! vis[i]) ret += in[i];

                vis[i] = 1;

                // cout << ret << ' ';
        }      
        for(int i = 1; i < n; i++){
                ret += t - time[i];

                time[i] = t++;

                if(! vis[i]) ret += in[i];

                vis[i] = 1;

                // cout << ret << ' ';
        } 
        // cout << "ret " << ret << endl;
        int CYC = 0;
        // cout << "time " << t << endl;
        // t--;
        for(int i=max(0ll, n - 2); i>= 0; i--){
        
                CYC += t - time[i];
                // cout << t - time[i] << ' ';
                time[i] = t++;
        }
        // cout << CYC << endl;
        return CYC * (cyc - 1) + ret; 
}
void solve(){
        int n, k; cin >> n >> k; 

        vi in(n); for(auto &p : in) cin >> p; 

        if(k < n){
                // sliding window;

                int have=0;

                for(int i=0; i < k-1; i++) have += in[i];
                int mx=0;
                for(int i=0; i + k <= n; i++){
                        have += in[i + k - 1];
                        amax(mx, have);

                        have -= in[i]; 
                }
                cout << mx + (k * (k - 1)) / 2 << endl; return;
        }
        int mx = get(k, in);

        reverse(all(in));

        amax(mx, get(k, in));

        cout << mx << endl; 
}
int32_t main(){
        
        FIO
        w(T) solve();
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/