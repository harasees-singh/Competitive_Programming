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

int32_t main(){
        FIO 

        w(t){
            int n; cin >> n;

            vi a(n), b(n); for(auto &p : a) cin >> p; for(auto &p : b) cin >> p;

            vi mn(4, infinity);

            for(auto p : b) amin(mn[0], abs(p - a[0]));
            for(auto p : b) amin(mn[1], abs(p - a[n - 1]));
            for(auto p : a) amin(mn[2], abs(p - b[0]));
            for(auto p : a) amin(mn[3], abs(p - b[n - 1]));

            int MN = infinity;

            amin(MN, accumulate(all(mn), 0ll));

            amin(MN, abs(a[0]-b[0]) + abs(a[n-1]-b[n-1])); // square
            amin(MN, abs(a[0]-b[n-1]) + abs(a[n - 1]-b[0])); // diagonal

            amin(MN, abs(a[0]-b[0]) + mn[1] + mn[3]);
            amin(MN, abs(a[n-1]-b[n-1]) + mn[0] + mn[2]); // 1 edge of square

            amin(MN, abs(a[n-1]-b[0]) + mn[0] + mn[3]);
            amin(MN, abs(a[0]-b[n-1]) + mn[1] + mn[2]); // 1 diagonal

            cout << MN << endl;
        }

        return 0;
}
