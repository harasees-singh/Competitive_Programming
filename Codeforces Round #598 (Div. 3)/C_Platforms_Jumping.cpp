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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

void shift(int id, vi &in){
        int pl = 1;

        int color = in[id];

        while(id > 1 and in[id - 1] == in[id]) id--, pl++;

        in[id] = 0; in[id + pl] = color;

}

void get(vi &in, int d){
        // bool ok = 0;
        int n = sz(in) - 1;
        l(it, 0, n){
                l(i, 1, n){
                        // if(in[i + 1] == 0){
                                if(i + d > n) continue;
                                bool nono = 1;
                                l(k, i + 1, i + d + 1) nono = nono and !(in[k]);
                                if(in[i] and nono){
                                        int id = i;
                                        while(id + d <= n and in[id + d] == 0){
                                                shift(id, in); id++;
                                        }
                                }
                                // else return;
                        // }
                }
        }
}

int32_t main(){
        
        FIO

        int n, m, d; cin >> n >> m >> d;

        vi in(n + 1);

        int j = 1;

        l(i, 0, m){
                int te; cin >> te;

                while(te--) in[j++] = i + 1;
        }

        get(in ,d);
        // for(auto p : in) cout << p <<' '; cout << endl;

        bool ok = 1;

        int cur = 0;

        l(i, 1, n + 1){
                // if(!in[i]) cur++;

                if(in[i]){

                        ok = ok and (i - cur <= d);

                        while(i <= n and in[i]) i++;

                        cur = --i;
                }
        }

        if(ok and n + 1 - cur <= d){
                cout << "YES" << endl;
                l(i, 1, n + 1) cout << in[i] << ' '; cout << endl;
        }
        else cout << "NO" << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/