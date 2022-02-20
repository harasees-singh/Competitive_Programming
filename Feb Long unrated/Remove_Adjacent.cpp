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

MOD_DEFINE
vi in;
int sum;
vi find_divisors(int i){
        vi cnt;
        for(int j = 1; j * j <= i; j++){
                if(i % j == 0){
                        cnt.push_back(i/j);

                        cnt.push_back(j);

                        if(i/j == j) cnt.pop_back();
                }
        }
        return cnt;
}
int unite(int s){
        int cnt = 1;
        int cur = 0;
        
        for(int i = 0; i < sz(in); i++){
                cur += in[i];

                if(cur == cnt * (s)) cnt++;
        }

        if(s==0) return sz(in) - cnt + 1;

        if(cnt >= abs(sum / s)) return sz(in) - abs(sum/s);

        return infinity;
}

int32_t main(){
        
        FIO

        w(t){
                int n; cin >> n;

                in = vi(n);

                for(auto &p : in) cin >> p;

                int tot = accumulate(all(in), 0ll);

                sum = tot;

                vi divs;

                if(tot == 0)
                        divs = {0};        
                else
                        divs = find_divisors(abs(tot));
                // cout << "OK" << endl; cout.flush();
                int sign = (tot != 0 ? tot/(abs(tot)) : 0);

                // for(auto p : divs) cout << p << ' '; cout << endl;
                
                int mn = infinity;
                for(auto &p : divs){

                        mn = min(mn, unite(sign * p));
                }
                // assert(mn != infinity);
                
                cout << mn << endl;
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