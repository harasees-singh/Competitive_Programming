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
int n;
int distinct(int i, int j){
        int hori = (j == n - j - 1 ? 1 : 2);

        int vert = (i == n - i - 1 ? 1 : 2);

        return hori * vert;
}

int32_t main(){
        FIO 

        cin >> n;

        set<pii> store;
        vi freq(10001);
        l(i, 0, n * n){
                int t; cin >> t;

                freq[t]++;
        }
        
        for(int i = 0; i < 1001; i++){
                if(freq[i]){
                        store.insert(make_pair(freq[i], i));
                }
        }
        vector<vi> mat(n, vi(n));
        for(int need = 4; need > 0; need /= 2){
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < n; j++){
                                if((not mat[i][j]) and distinct(i, j) == need){
                                        pii have = *(prev(store.end()));

                                        store.erase(have);

                                        if(have.ff < need){
                                                cout << "NO"; return 0;
                                        }
                                        mat[n - i - 1][n - j - 1] = mat[i][n - j - 1] = mat[i][j] = mat[n - i - 1][j] = have.ss;

                                        have.ff -= need;

                                        if(have.ff){
                                                store.insert(have);
                                        }
                                        
                                }
                        }
                }
        }
        cout << "YES" << endl;

        for(auto p : mat){
                for(auto q : p) cout << q << ' '; cout << endl;
        }

        return 0;
}
