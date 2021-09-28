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

        int n; cin >> n;

        // vi I(n); 

        multiset<pii> I;

        vi arr;

        l(i, 0, n)
        {
            int t; cin >> t; I.insert({t, i});

            arr.pb(t);
        }

        int gcd = (*(--I.end())).ff;

        l(i, 0, n){

            multiset<pii> T;

            cout << arr[(*(--I.end())).ss] << space; 

            int temp = (*(--I.end())).ff;

            gcd = __gcd(temp, gcd);

            I.erase(--I.end());

            for(auto p : I)
                    T.insert({__gcd(gcd, p.ff), p.ss});

            I = T;
        }

        cout << endl;
        
    }

}
