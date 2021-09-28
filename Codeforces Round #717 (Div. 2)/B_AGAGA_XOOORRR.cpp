#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define Set                             tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;

MOD_DEFINE

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n; 

        vi I;

        int Xor = 0;

        l(i, 0, n){
            
            int t; cin >> t; Xor ^= t; I.pb(t);
        }

        vi pref(n), suff(n);

        pref[0] = I[0];

        suff[n - 1] = I[n - 1];

        l(i, 1, n) pref[i] = pref[i - 1]^I[i];

        for(int i = n - 2; i >= 0; i--){
            
            suff[i] = suff[i + 1]^I[i];
        }

        bool ok = 0;

        for(int i = 0; i < n - 1; i++){

            if(pref[i] == suff[i + 1]) ok = 1;
        }

        for(int i = 0; i < n - 2; i++){

            for(int j = i + 2; j < n; j++){

                if(pref[i] == suff[j] and (pref[j - 1] == 0)) ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}