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

    int n;
    cin >> n;

        int rem = n%4;

        if(rem == 0){
                cout << 0 << endl;
                cout << n/2 << space;
                for(int i = 1; i < n/2; i += 2)
                        cout << i << space << n - i + 1 << space; cout << endl;
        }
        if(rem == 1){
                cout << 1 << endl;
                cout << n/2 << space;
                for(int i = 2; i <= n/2; i += 2)
                        cout << i << space << n - i + 2 << space; cout << endl;
        }
        if(rem == 2){
                cout << 1 << endl;
                cout << n/2 << space;
                for(int i = 1; i < n/2; i+= 2)
                        cout << i << space << n - i + 1 << space;

                cout << n/2 << endl;
                        
        }
        if(rem == 3){
                cout << 0 << endl;
                cout << n/2 << space;

                for(int i = 2; i < n/2; i += 2)
                        cout << i << space << n - i + 2 << space;
                cout << n/2 + 2 << endl;
        }

        return 0;
}
