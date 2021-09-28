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

        vector<vi> amat(n, vi(n));

        vector<vi> bmat(n, vi(n));

        l(i, 0, n){

            string t; cin >> t;

            for(int j = 0; j < n; j++)
                    amat[i][j] = t[j] - '0';
            
        }
        l(i, 0, n){

            string t; cin >> t;

            for(int j = 0; j < n; j++)
                    bmat[i][j] = t[j] - '0';
            
        }

        // l(r, 0, n)
        //         l(c, 0, n)
        //                 cout << amat[r][c] << ' '; cout.flush();

        for(int i = 0; i < n; i++)
                if(amat[i][0] != bmat[i][0])
                        // do horizontal xor
                        for(auto &p : amat[i])
                                p ^= 1;

        for(int j = 0; j < n; j++)
                if(amat[0][j] != bmat[0][j])
                        // do vertical xor
                        for(int i = 0; i < n; i++)
                                amat[i][j] ^= 1;
        bool equality = true;

        for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                        equality &= (amat[i][j] == bmat[i][j]);

        cout << (equality ? "YES" : "NO") << endl;              
    }
}
