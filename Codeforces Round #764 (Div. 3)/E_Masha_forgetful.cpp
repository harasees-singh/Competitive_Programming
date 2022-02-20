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
// #define int                             long long
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

string s;

int m;

map<string, bool> have;

vi memo;

map<string, tuple<int, int, int>> id; // the substring, {string number, index of start}

bool dp(int i){
        if(i >= m) return true;

        if(memo[i] != -1) return memo[i];

        bool two = (have[s.substr(i, 2)] and dp(i + 2));

        if(two){
                // 2 len substr found
                return memo[i] = 1;
        }
        bool three = (have[s.substr(i, 3)] and dp(i + 3));
        if(three){      
                return memo[i] = 1;
        }

        return false;
}

int32_t main(){
        
        FIO

        w(t){
                int n; cin >> n >> m;

                vector<string> cache;

                id = map<string, tuple<int, int, int>>();

                memo = vi(m, -1);

                l(j, 0, n){
                        string s; cin >> s;

                        l(i, 0, m) {
                                string t;
                                t += s[i];
                                for(int k = 1; k <= 2; k++) {
                                        if (k + i >= m) break;
                                        t += s[i + k];

                                        if (!have[t]) {
                                                have[t] = 1;
                                                id[t] = make_tuple(i + 1, i + k + 1, j + 1);
                                                cache.push_back(t);
                                        }
                                }
                        }
                }
                cin >> s;

                vector<tuple<int, int, int>> out;
                if(dp(0)){

                        l(i, 0, m){
                                if(i + 2 >= m or memo[i + 2] == 1){
                                        auto t = id[s.substr(i, 2)];

                                        out.push_back(t);
                                        i++;
                                }
                                else{
                                        auto t = id[s.substr(i, 3)];

                                        out.push_back(t);
                                        i+=2;
                                }
                        }
                        cout << sz(out) << endl;
                        
                        l(i, 0, sz(out)){
                                auto t = out[i];

                                cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
                        }
                }
                else cout << -1 << endl;
                for(auto &p : cache) have[p] = 0;
        }

        return 0;
}
