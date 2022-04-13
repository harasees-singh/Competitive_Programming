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
map<string, int> f;
int check(string s){
    int mn = infinity;
    if(s[0] < '8'){
        // 7, 8, 9

        int need = not (bool)(f[s]);
        s[0]++;
        need += not (bool)(f[s]);

        s[0]++;
        need += not (bool)(f[s]);
        amin(mn, need);
    }
    if(s[0] < '9' and s[0] > '1'){
        // 6, 7, 8

        s[0]--;
        int need = 0;
        for(int i = 0; i < 3; i++, s[0]++){
            need += not (bool)(f[s]);
        }
        amin(mn, need);
    }
    if(s[0] > '2'){
        // 5, 6, 7
        s[0]--, s[0]--;

        int need = 0;
        for(int i = 0; i < 3; i++, s[0]++){
            need += not (bool)(f[s]);
        }
        amin(mn, need);
    }
    return mn;

}
int32_t main(){
        
        FIO


        string s = "mps";

        vector<string> in(3); for(auto &p : in) cin >> p;

        for(auto p : s){
            for(int i = 1; i <= 9; i++){
                f[string(1, i + '0') + string(1, p)] = 0;
            }
        }
        for(auto p : in) f[p]++;
        int  mn = infinity;
        for(auto p : f){
            
            amin(mn, check(p.ff));

            amin(mn, max(0ll, 3 - p.ss));
        }
        cout << mn << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/