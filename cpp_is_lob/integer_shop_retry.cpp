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
                int n; cin >> n;

                int l, r, c; cin >> l >> r >> c;

                cout << c << endl; cout.flush();

                set<vi> seg; seg.insert({l, r, c});

                for(int i = 0; i < n - 1; i++){
                        cin >> l >> r >> c;

                        int L, R, cost; 

                        assert(sz(seg));

                        if(sz(seg) == 1){

                                auto v = *(seg.begin());
                                L = v[0], R = v[1], cost = v[2];
                                if(l <= L and r >= R){
                                        if(l == L and r == R){
                                                cost = min(cost, c);
                                        }
                                        else    
                                                seg.clear(), seg.insert({l, r, c}), cost = c;
                                }
                                else if(l >= L and r <= R);

                                else{
                                        seg.insert({l, r, c});

                                        cost += c;
                                }
                        }
                        else{
                                // 2 segs already present
                                assert(sz(seg) == 2);
                                int s1, e1, s2, e2, c1, c2; 

                                auto v1 = *seg.begin();
                                auto v2 = *(++seg.begin());

                                s1 = v1[0], e1 = v1[1], c1 = v1[2];

                                s2 = v2[0], e2 = v2[1], c2 = v2[2];

                                cost = c1 + c2;
                                if(l <= s1 and r >= e2){
                                        if(l == s1 and r == e2){
                                                if(cost > c){
                                                        seg.clear();
                                                        seg.insert({l, r, c});
                                                        cost = c;
                                                }
                                        }
                                        else{
                                                cost = c;
                                                seg.clear();
                                                seg.insert({l, r, c});
                                        }
                                }
                                else if(l <= s1){
                                        if(l==s1){
                                                if(c < c1){
                                                        seg.erase(seg.begin());

                                                        seg.insert({l, r, c});

                                                        cost -= c1, cost += c;
                                                }
                                        }
                                        else{
                                                seg.erase(seg.begin());

                                                seg.insert({l, r, c});

                                                cost -= c1, cost += c;
                                        }
                                }
                                else if(r >= e2){
                                        if(r==e2){
                                                if(c < c2){
                                                        seg.erase((prev(seg.end())));

                                                        seg.insert({l, r, c});

                                                        cost -= c2, cost += c;
                                                }
                                        }
                                        else{
                                                seg.erase(prev(seg.end()));

                                                seg.insert({l, r, c});

                                                cost -= c2, cost += c;
                                        }
                                }
                        }
                        cout << cost << endl;
                }       
        }

        return 0;
}
