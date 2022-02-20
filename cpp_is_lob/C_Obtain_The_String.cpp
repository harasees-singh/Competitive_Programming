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
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
        
        FIO

        w(t){
                string s, t; cin >> s >> t;

                vector<vi> id_char(sz(s) + 1, vi(26, INT_MIN));

                vi nearest_char(26, INT_MIN);

                l(i, 0, sz(s)) if(nearest_char[s[i] - 'a'] == INT_MIN) nearest_char[s[i] - 'a'] = i;

                for(int i = sz(s) - 1; i >= 0; i--){
                        int cur = s[i] - 'a';

                        l(j, 0, 26) id_char[i][j] = id_char[i + 1][j];

                        id_char[i][cur] = i;
                }
                // id_char[i][j] represents the id of closest index of string s with char j 
                // -1 if not found
                // for(auto p : nearest_char) cout << p << ' '; cout << endl;
                bool ok = 1;
                // for(auto p : id_char[3]) cout << p << ' '; cout << endl;

                int cnt = 1;
                if(nearest_char[t[0] - 'a'] == INT_MIN){cout << -1 << endl; continue;};
                int ptr = nearest_char[t[0] - 'a'] ;

                for(int i = 1; i < sz(t); i++){
                        char p = t[i];
                        int need = p - 'a';
                        // cout << ptr << endl;

                        // cout << p << ' ' << cnt << endl;

                        if(ptr == id_char[ptr][need]) 
                                        ptr++;

                        if(id_char[ptr][need] == INT_MIN){
                                if(nearest_char[need] == INT_MIN){ok = 0; break;}
                                
                                ptr = nearest_char[need] ; 
                                
                                cnt++;
                        }
                        else{

                                ptr = id_char[ptr][need] ; 
                        
                        }

                }
                
                if(ok)
                        cout << cnt << endl;
                else cout << -1 << endl;
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