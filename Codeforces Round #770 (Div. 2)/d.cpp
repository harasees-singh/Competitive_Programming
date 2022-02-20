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

int Q = 0;

int query(int i, int j, int k){
        Q++;
        cout << "? " << i << ' ' << j << ' ' << k << endl; cout.flush();

        int ret; cin >> ret;

        return ret;
}

int32_t main(){
        FIO 

        w(t){
                int n; cin >> n;

                int i = 1, j = 2;

                int val = query(i, j, n);

                for(int it = 3; it < n; it++){
                        
                        // potential maxima or minima at it

                        // reject one of i and j

                        int i_is_good = query(i, it, n), j_is_good = query(j, it, n);

                        int top = max({i_is_good, j_is_good, val});

                        if(i_is_good == top){
                                j = it;

                                val = i_is_good;
                        }
                        else if(j_is_good == top){
                                i = it;

                                val = j_is_good;
                        }
                }
                pii ans;
                for(int senti = 1; senti <= n; senti++){
                        if(senti != i and senti != j){
                                int i_j = query(i, j, senti);

                                int j_n = query(j, n, senti);

                                int i_n = query(i, n, senti);

                                if(i_j >= max(j_n, i_n)){
                                        ans = {i, j};
                                }
                                else if(j_n >= max(i_j, i_n))
                                        ans = {j, n};
                                else
                                        ans = {i, n};

                                break;
                        }
                }
                // cout << "Q " << Q << endl;
                // assert(Q <= 2 * n - 2);
                cout << "! " << ans.ff << " " << ans.ss << endl; cout.flush();
        }

        return 0;
}
