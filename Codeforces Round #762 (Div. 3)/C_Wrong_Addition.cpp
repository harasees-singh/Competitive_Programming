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

int32_t main(){
        
        FIO

        w(t){
                string a, s; cin >> a >> s;

                while(sz(a) < sz(s)) a = "0" + a;
                // cout << a << endl;
                int i = sz(a) - 1, j = sz(s) - 1;
                string ans;
                bool ok = 1;

                while(i > -1 and j > -1){
                        int diff = s[j] - a[i];

                        if(diff < 0){
                                int val = s[j] - '0';
                                j--;
                                if(j > -1 and val + 10*(s[j] - '0') - (a[i] - '0') < 10 and val + 10*(s[j] - '0') - (a[i] - '0') > -1){
                                        ans.push_back(val + 10*(s[j] - '0') - (a[i] - '0') + '0');
                                }
                                else{
                                        ok = false; break;
                                }
                        }
                        else{
                                ans.pb(diff + '0');
                        }
                        i--, j--;
                }
                while(sz(ans) and ans.back() == '0') ans.pop_back();
                reverse(all(ans));
                // int val = stoi(ans);
                l(j, 0, i + 1) ok = ok and (a[j] == '0');
                ok = ok and (sz(ans));
                cout << (ok and j == -1 ? ans : "-1") << endl;
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