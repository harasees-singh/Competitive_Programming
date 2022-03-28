// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE
int mini = infinity;
int cost(int a, int b, int c){
    return (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
}
void solve(vi &r, vi &g, vi &b){
    for(auto p : g){
        int idr = upper_bound(all(r), p) - r.begin();

        idr--; if(idr < 0 or idr == sz(r)) continue;

        int idb = lower_bound(all(b), p) - b.begin();

        if(idb < 0 or idb == sz(b)) continue;

        amin(mini, cost(r[idr], b[idb], p));
    }
}
int32_t main(){
        FIO 

        w(t){
            int nr, ng, nb; cin >> nr >> ng >> nb;

            vi r(nr), g(ng), b(nb); for(auto &p : r) cin >> p; for(auto &p : g) cin >> p; for(auto &p : b) cin >> p;

            sort(all(r)); sort(all(g)); sort(all(b));

            int cnt = 0;

            mini = infinity;

            vi permute = {0, 1, 2};

            vector<vi> RGB = {r, g, b};

            do{
                cnt++;

                solve(RGB[permute[0]], RGB[permute[1]], RGB[permute[2]]);

            }while(next_permutation(all(permute)));

            assert(cnt == 6);
            
            cout << mini << endl;
        }

        return 0;
}
