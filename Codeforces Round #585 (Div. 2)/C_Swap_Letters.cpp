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
void print(vector<vi>& pos){
    for(auto &p : pos){
            for(int i= 0; i < sz(p); i += 2) cout << p[i] + 1 << ' ' << p[i + 1] + 1 << endl;
        }
}
int32_t main(){
        
        FIO

        int n; cin >> n;

        vector<string> in(2); for(auto &p : in) cin >> p;

        vector<vi> pos(2); // a->b, b->a

        for(int i=0; i < n; i++){
            if(in[0][i] != in[1][i]){
                if(in[0][i] == 'a') pos[0].pb(i);

                else pos[1].pb(i);
            }
        }
        if((sz(pos[0]) % 2) ^ (sz(pos[1]) % 2)){
            cout << -1; return 0;
        }
        int ops = (sz(pos[0]) + sz(pos[1])) / 2;
        if(sz(pos[0]) & 1){
            ops++;
            cout << ops << endl;
            int t = pos[0].back();
            cout << t + 1 << ' ' << t + 1 << endl;
            pos[0].pop_back(); 

            pos[1].push_back(t);
        }
        
        else cout << ops << endl;
        print(pos);

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/