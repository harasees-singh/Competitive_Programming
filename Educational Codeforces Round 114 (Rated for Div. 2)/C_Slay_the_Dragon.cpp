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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    int n; cin >> n;

    vi I(n); 

    int summand = 0;

    l(i, 0, n){
            cin >> I[i]; summand += I[i];
    }

    // cout << summand << endl;

    int m; cin >> m;

    sort(all(I));

    l(i, 0, m){

        int x, y; cin >> x >> y;
        
        int index = lower_bound(all(I), x) - I.begin();


        if(index == 0){

            cout << max(0ll, y - (summand - I[0])) << endl; continue;
        }

        if(index == n){

            cout << x - I[n - 1] + max(0ll, (y - (summand - I[n - 1]))) << endl;
        }

        else {

            cout << min(max(0ll, y - (summand - I[index])), x - I[index - 1] + max(0ll, y - (summand - I[index - 1]))) << endl;
        }
    }
}
