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

MOD_DEFINE

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;

        string s; cin >> s;

        int T = 0, M = 0;

        for(char p : s)

            T += (p == 'T'), M += (p == 'M');

        int f = 0;

        bool ok = true;

        for(char p : s){

            f += (p == 'T');

            if(f == 0) ok = false;

            f -= (p == 'M');
        }

        int b = 0;

        for(int i = sz(s) - 1; i >= 0; i--){

            int p = s[i];

            b += (p == 'T');

            if(b == 0) ok = false;

            b -= (p == 'M');
        }

        cout << (T == 2*M and ok ? "YES" : "NO") << endl;
    }
}