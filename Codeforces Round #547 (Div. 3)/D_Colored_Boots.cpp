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

int32_t main(){
        
        FIO

        map<char, vi> u, v; 

        int n; cin >> n;

        string U, V; cin >> U >> V;

        l(i, 0, n){
                char cur = U[i];

                u[cur].pb(i);
        }
        l(i, 0, n){
                char cur = V[i];

                v[cur].pb(i);
        }
        vector<pii> ans;
        for(char a = 'a'; a <= 'z'; a++){
                int mn = min(sz(u[a]), sz(v[a]));

                l(i, 0, mn){
                        int l, r;

                        l = u[a].back(), r = v[a].back(); 

                        u[a].pop_back();
                        v[a].pop_back();

                        ans.push_back(make_pair(l + 1, r + 1));
                }
        }
        char pt = 'z';
        int i = 0;
        for(; i < sz(u['?']); i++){
                int id = u['?'][i];


                while(pt >= 'a'){
                        if(sz(v[pt])==0) pt--;

                        else break;
                }
                if(pt < 'a') break;
                ans.push_back(make_pair(id + 1, v[pt].back() + 1));

                v[pt].pop_back();
        }
        pt = 'z';
        int j = 0;
        for(; j < sz(v['?']); j++){
                int id = v['?'][j];

                while(pt >= 'a'){
                        if(sz(u[pt])==0) pt--;

                        else break;
                }
                if(pt < 'a') break;
                ans.push_back(make_pair(u[pt].back() + 1, id + 1));

                u[pt].pop_back();
        }
        pt = '?';
        for(; i < sz(u['?']); i++){
                int id = u['?'][i];
                // if(sz(v[pt]) == 0)break;
                if(j == sz(v[pt])) break;
                ans.push_back(make_pair(id + 1, v['?'][j] + 1));
                
                j++;
        }
        cout << sz(ans) << endl; 
        for(auto &p : ans) cout << p.ff << ' ' << p.ss << endl;


        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/