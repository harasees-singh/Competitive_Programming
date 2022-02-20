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

pii stream(vi &in, int i, int j){
        int cnt = 1;

        for(int it = i + 1; it < sz(in); it++){
                if(in[it] > in[it - 1]) cnt++; 

                else break;
        }
        int mx = cnt;

        cnt = 1;

        for(int it = j - 1; it >= 0; it--){
                if(in[it] > in[it + 1]) cnt++;
                else break;
        }
        if(mx > cnt){
                return {0, mx};
        }
        return {1, cnt};
}

int32_t main(){
        
        FIO

        int n; cin >> n;

        vi in(n);

        for(auto &p : in) cin >>  p;

        int i = 0, j = n - 1; int lst = 0; 
        string ans; 
        while(i <= j){
                
                int mx = max(in[i], in[j]);
                if(mx <= lst) break;
                if(in[i]==in[j]){
                        pii t = stream(in, i, j);

                        if(t.ff){
                                l(it, 0, t.ss) ans += 'R';
                        }
                        else 
                                l(it, 0, t.ss) ans += 'L';
                        break;
                }
                // lst = min(in[i], in[j]);
                int mn = min(in[i], in[j]);

                if(mn <= lst){
                        if(in[i] < in[j])
                                ans += 'R', j--;
                        else 
                                ans += 'L', i++;
                        
                        lst = mx;
                }
                else{
                        if(in[i] < in[j])
                                ans += 'L', i++;
                        else 
                                ans += 'R', j--;

                        lst = mn;
                }

                        
                
        }
        cout << sz(ans) << endl; cout << ans << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/