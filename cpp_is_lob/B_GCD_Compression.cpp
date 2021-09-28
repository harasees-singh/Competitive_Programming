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

        n = n*2;

        int odd = 0;

        vector<pii> I(n);

        l(i, 0, n){

            cin >> I[i].first; I[i].second = i + 1;

            odd += I[i].first%2;
        }

        sort(all(I), [](pii a, pii b){return (a.first&1) > (b.first&1);});

        if(odd&1){

            for(int i = 1; i < n - 1; i+=2)

                cout << I[i].second << space << I[i + 1].second << endl;
        }

        else{

            for(int i = 2; i < n; i += 2)

                cout << I[i].second << space << I[i + 1].second << endl;
        }
    }
}