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

    int n; cin >> n;

    int p = 1;

    vi answer;

    for(int i = 1; i <= n - 1; i++)

        if(__gcd(i, n) == 1) answer.pb(i), p *= i, p %= n;

    if(p%n != 1) cout << sz(answer) - 1 << endl;

    else cout << sz(answer) << endl;

    for(auto o : answer)

        if(o == 1 or o != p%n) cout << o << space; cout << endl;

    // int rem = p%n;

    // sure shot non zero

    
}