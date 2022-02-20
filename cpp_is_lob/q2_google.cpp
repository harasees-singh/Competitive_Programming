// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

int32_t main(){
        FIO 

        w(t){
                string s; cin >> s;

                vi pos;

                set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

                l(i, 0, sz(s)) if(vowels.count(s[i]) == 0) pos.push_back(i);

                int mn = infinity;

                l(i, 0, sz(pos)){
                        int remove = pos[i] - pos[0] + 1;

                        if(i < sz(pos) - 1) remove += pos.back() - pos[i + 1] + 1;

                        mn = min(mn, remove);
                }
                if(mn == infinity){
                        cout << (pos.size() ? sz(s) - 1 : sz(s)) << endl;
                }
                else cout << sz(s) - mn << endl;
        }

        return 0;
}
