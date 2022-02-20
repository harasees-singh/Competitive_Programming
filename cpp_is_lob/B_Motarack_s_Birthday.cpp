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
int get(vi &in, int rep){
        int mx = 0;
        for(int i = 1; i < sz(in); i++){
                int cur = (in[i] == -1 ? rep : in[i]);

                int prev = (in[i - 1] == -1 ? rep : in[i - 1]);

                mx = max(mx, abs(cur - prev));
        }
        return mx;
}

int32_t main(){
        
        FIO

        w(t){
                int n; cin >> n;

                vi in(n);

                for(auto &p : in) cin >> p;

                set<int> store;

                for(int i = 0; i < n; i++){
                        if(in[i] == -1) continue;

                        if(i and in[i - 1] == -1) store.insert(in[i]);

                        if(i < n - 1 and in[i + 1] == -1) store.insert(in[i]);
                }
                int tot = 0;

                if(not sz(store)){
                        cout << 0 << ' ' << 0 << endl; continue;
                }

                tot += *(store.begin());

                tot += *(prev(store.end()));

                tot /= 2;

                int mn = get(in, tot);
                
                cout << mn << ' ' << tot << endl;
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