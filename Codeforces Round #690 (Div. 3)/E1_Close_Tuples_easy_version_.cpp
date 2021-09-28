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

int nCr(int n, int r){

    if(n < r) return 0;
    
    if(r <= 0)
            return 1; 
    return n*(nCr(n - 1, r - 1))/r;
}

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;

        int k = 2, m = 3;

        vi I(n);

        l(i, 0, n)
                cin >> I[i];
        
        sort(all(I));

        int ans = 0;

        for(int i = 0; i < n; i++){

            int index = upper_bound(all(I),I[i] + k) - I.begin() - 1;

            if(index - i < 0 or m - 1 < 0 or index - i < m - 1) continue;
            
            ans += nCr(index - i + 1 - 1, m - 1);

        }

        cout << ans << endl;
    }

}
