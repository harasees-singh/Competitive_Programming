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
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    int a, b, k; cin >> a >> b >> k;

    if(k == 0){

            cout << "Yes" << endl;
            l(i, 0, b) cout << '1'; l(i, 0, a) cout << '0'; cout << endl;
            l(i, 0, b) cout << '1'; l(i, 0, a) cout << '0'; cout << endl;

            return 0;
    }

    if(!a or b < 2 or a + b - 2 < k)
            cout << "No" << endl;
    
    else{
            cout << "Yes" << endl;

            string one;

            l(i, 0, b - 1) one.pb('1'); l(i, 0, a + 1) one.pb('0');

			one[sz(one) - 1 - min(a, k)] = '1';

			cout << one << endl;

            int zero_pos = k - a;

            if(min(a, k) == k){

			        l(i, 0, b - 1) cout << '1'; l(i, 0, a) cout << '0'; cout << '1' << endl;
            }
            else{

                    l(i, 0, b - 1 - zero_pos) cout << '1'; cout << '0'; l(i, 0, zero_pos) cout << '1'; l(i, 0, a - 1) cout << '0'; cout << '1' << endl;
            }
    }

}
