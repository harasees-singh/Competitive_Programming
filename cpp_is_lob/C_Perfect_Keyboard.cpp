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
vector<vi> g;
int32_t main(){
        
        FIO

        w(t){
                g = vector<vi>(26, vi(26));

                string s; cin >> s;
                if(sz(s) == 1){cout << "YES" << endl; for(char a = 'a'; a <= 'z'; a++) cout << a; cout << endl; continue;}

                for(int i = 0; i < sz(s) - 1; i++){

                        g[s[i] - 'a'][s[i + 1] - 'a'] = 1;
                        g[s[i + 1] - 'a'][s[i] - 'a'] = 1;
                }    

                bool ok = 1;

                int odd = 0;

                int start;

                for(int i = 0; i < 26; i++){
                        vi &p = g[i];
                        int cnt = count(all(p), 1);
                        if(cnt > 2){
                                ok = 0; break;
                        }
                        if(cnt == 1){
                                odd++; start = i;
                        }
                }
                if(!ok or odd != 2){
                        cout << "NO" << endl; continue;
                }
                int last = -1; vi vis(26);
                int cpy = start;
                cout << "YES" << endl;

                while(true){
                        cout << (char)(start + 'a'); 

                        vis[start] = 1;

                        if(count(all(g[start]), 1) == 1 and start != cpy) break;

                        int t = start;

                        for(int i = 0; i < 26; i++){
                                if(g[start][i] and i != last){ start = i; break;}
                        }
                        last = t;

                }
                l(i, 0, 26) if(!vis[i]) cout << (char)(i + 'a'); cout << endl;

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