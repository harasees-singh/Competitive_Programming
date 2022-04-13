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

        int n, m; cin >> n >> m;

        vi a(n), b(n), c(m), d(m);

        for(auto &p : a) cin >> p;
        for(auto &p : b) cin >> p;
        for(auto &p : c) cin >> p;
        for(auto &p : d) cin >> p;

        vpii choco(n);

        for(int i = 0; i < n; i++){
            choco[i] = {a[i], b[i]};
        }
        sort(all(choco));

        reverse(all(choco));

        multiset<pii> have; // d, c

        vpii box(m);

        for(int i = 0; i < m; i++){
            box[i] = {c[i], d[i]};
        }

        sort(all(box));

        reverse(all(box));

        int pt = 0;

        for(auto p : choco){
            int need = p.ff;
            
            while(pt < m and box[pt].ff >= need){
                have.insert({box[pt].ss, box[pt].ff});
                pt++;
            }

            int len = p.ss;

            auto it = have.lower_bound({len, 0});

            if(it == have.end()){
                cout << "No"; return 0;
            }
            have.erase(it);
        }
        cout << "Yes";

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/