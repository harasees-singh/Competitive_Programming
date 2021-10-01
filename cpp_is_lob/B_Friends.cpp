#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

void solve(){
    int n;
    cin >> n;

    vector<unordered_set<int>> adj(6);

    l(i, 0, n){

        int a, b; cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);
    }
    unordered_set<int> store;
    l(i, 1, 6){
            store.insert(i);

            l(j, i + 1, 6){
                    if(adj[i].count(j) == 0){
                            store.insert(j);

                            l(k, j + 1, 6)
                                    if(adj[i].count(k) == 0 and adj[j].count(k) == 0){
                                            cout << "WIN" << endl;
                                            return;
                                    }

                            store.erase(j);
                    }
            }
            store.erase(i);
    }

    l(parent, 1, 6){
            for(auto child : adj[parent])
                    for(auto grandchild : adj[child])
                            if(adj[grandchild].count(parent)){
                                    cout << "WIN" << endl;
                                    return;
                            }
    }
    cout << "FAIL" << endl;
    return;
}

int32_t main(){
    FIO

    solve();

}
