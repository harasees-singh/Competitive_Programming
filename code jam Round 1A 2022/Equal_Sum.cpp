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
bool isPowerof2(ll x){
	return !(x && (x & (x-1)));
}

int32_t main(){
        
        FIO

        int t; cin >> t; 
        for(int T = 1; T <= t; T++){

            int n; cin >> n; 

            assert(n == 100);

            int cnt = 0;
            int tot = 0;

            int i = 0;

            vpii lstbits;
            for(; (1ll << i) <= 1e9; i++, cnt++){
                assert((1ll << i) <= 1e9);
                cout << (1ll << i) << ' '; cout.flush(); tot += (1ll << i);
            }
            // int pt = (1ll << (i - 1)) - 3;
            // int pt2 = 3;
            i = 0;
            for(; i < n - cnt; i+=1){
                cout << 2 * (i + 1) + 1 << ' ';cout.flush(); tot += (2 * (i + 1) + 1);
                // assert(pt + pt2 == (1ll << (i - 1)));

                // while(isPowerof2(pt) or isPowerof2(pt2)) pt--, pt2++;

                // cout << pt << ' ' << pt2 << ' '; tot += (pt + pt2); lstbits.push_back({pt, pt2});
                // // cout << sz(lstbits) << endl;

                // pt--, pt2++;
            }
            // cout << "hello" << sz(lstbits) << endl; cout.flush();
            // if(i < 100 - cnt){
            //     cout << 1e9; tot += 1e9; 
            // }
            cout << endl;
            cout.flush();

            vi in(n); for(auto &p : in) cin >> p, tot += p;
            int it = 0;
            while(it < n and tot - 2 * in[it] > 0){
                tot -= 2 * in[it];
            }
            
            tot/=2;

            for(int z = 0; tot; z++){
                if((1ll << z) <= 1e9 and ((tot)&1)) cout << (1ll << z) << ' '; 

                tot/=2;

            }
            
            cout << endl;
            cout.flush();
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