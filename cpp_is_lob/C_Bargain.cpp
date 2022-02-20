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

vi nC2(1e5 + 1);        // not the literal nC2
                        // it's the number of ways of picking a subsegment out of a n len string 
                        // empty subseg allowed
                        // = n * (n + 1) / 2 + 1

int32_t main(){
        
        FIO
        // ans is summation pref * s[i] + ten_power * (number of subsegments of a string of len i) for zero based indexing
        // pref += (10 ^ i) * (i + 1); after each iteration
        nC2[0] = 1;

        fstream out;

        out.open("out.txt");

        out.clear();

        for(int i = 1; i <= 1e5; i++)
                nC2[i] = (i * (i + 1))/2 + 1, nC2[i] %= MOD;   
        
        int pref = 0;

        string s; cin >> s;
        int ans = 0;
        int n = sz(s);

        reverse(all(s));

        int sub = 0; int ten_power = 1;

        for(int i = 0; i < n; i++){

                sub += ten_power * (s[i] - '0'); 

                ans += pref * (s[i] - '0'); 
                ans %= MOD;

                ans += ((nC2[n - i - 1] * ten_power) % MOD) * (s[i] - '0');

                pref += ten_power * (i + 1);

                ten_power *= 10; 

                sub %= MOD;

                pref %= MOD;

                ten_power %= MOD;
                
                ans %= MOD;

                out << ans << ' ' << sub << ' ' << endl;
        }
        cout << (ans - sub + MOD) % MOD << endl;

        out << endl; out.close();
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/