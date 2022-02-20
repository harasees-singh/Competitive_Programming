// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
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
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
        
        FIO

        // make em all multiples of n

        // for first ele simple // for rest n - 1 add r * (n - 1); where r = ai % n

        int n; cin >> n;

        vi in(n);

        for(auto &p : in) cin >> p;

        cout << 1 << ' ' << 1 << endl;

        cout << -(in[0] % n) << endl;

        in[0] -= (in[0] % n);

        if(n == 1){
                cout << 1 << ' ' << 1 << endl; cout << n << endl;
                in[0] += n;
                cout << 1 << ' ' << 1 << endl; cout << -in[0] << endl;

                return 0;
        }
        cout << 2 << ' ' << n << endl;
        // cout << (n - 1) * (in[1] % n) << endl;
        // for(auto p : in) cout << (n - 1) * (p % n) << ' ';
        for(int i = 1; i < n; i++)
                cout << ((n - 1) * (in[i] % n)) << ' ', in[i] += (n - 1) * (in[i] % n);
        cout << endl;

        cout << 1 << ' ' << n << endl;

        for(auto p : in) cout << -p << ' '; cout << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/