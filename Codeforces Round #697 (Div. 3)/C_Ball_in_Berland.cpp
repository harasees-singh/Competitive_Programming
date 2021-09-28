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

    test_cases_loop{

        int a, b, k; cin >> a >> b >> k;

        vi boys(k), gals(k);

        l(i, 0, k)
                cin >> boys[i];

        l(i, 0, k)
                cin >> gals[i];

        int ans = 0;

        unordered_map<int, int> bfreq;

        unordered_map<int, int> gfreq;

        for(auto p : boys)
                bfreq[p]++;

        for(auto p : gals)
                gfreq[p]++;

        for(int i = 0; i < k; i++)
                ans += k - 1 - bfreq[boys[i]] + 1 - gfreq[gals[i]] + 1;
        
        cout << ans/2 << endl;

    }

}
