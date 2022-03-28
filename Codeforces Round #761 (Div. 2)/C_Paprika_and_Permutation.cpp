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
#define w(t)                            int t; cin >> t; while(t--)
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

        w(t){
            // each num can be converted to 1, 2, ..  ceil(n / 2) - 1;

            // sort and start from greatest ele by making it = largest ele required;
            int n; cin >> n;

            multiset<int> have, need; 

            for(int i = 1; i <= n; i++) need.insert(i);

            for(int i = 0; i < n; i++){
                int t; cin >> t; 

                if(need.count(t)) need.erase(t);

                else have.insert(t);
            }   
            int cnt = 0;
            bool ok = 1;
            if(not sz(have)) {cout << 0 << endl ; continue;}
            for(auto it = prev(have.end()); cnt < have.size(); cnt++, it--){
            // cout << "YES" << endl; cout.flush();
                int convert = *it;

                int needed = *prev(need.end()); need.erase(prev(need.end()));

                if(needed > (convert + 1)/2 - 1){
                    ok = 0;
                    cout << -1 << endl; break;
                }
            }
            if(ok) cout << sz(have) << endl;
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