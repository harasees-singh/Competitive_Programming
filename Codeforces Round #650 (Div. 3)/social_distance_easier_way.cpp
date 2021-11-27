#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

int32_t main(){
    FIO 

    test_cases_loop{
            int n, k; cin >> n >> k;

            string s; cin >> s;

            string front = "1"; l(i, 0, k) front += '0';
            string end = ""; l(i, 0, k) end += '0'; end += '1';

            s = front + s + end;

            int ans = 0;

            int curr = 0;

            l(i, 0, n + 2*k + 2){
                    if(s[i] == '1') ans += (curr - k)/(k + 1), curr = 0;

                    else curr++;
            }
            cout << ans << endl;
    }

    return 0;
}
