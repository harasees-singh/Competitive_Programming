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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int nP2(int n){
        if(n < 2)
                return 0;
        return ((n)*(n - 1))%MOD;
}

int fac[200000 + 1];


int32_t main(){
        
        FIO

        fac[0] = 1;

        for(int i = 1; i < 200001; i++)
                fac[i] = (i * fac[i - 1])%MOD;
        
        w(t){
                int n; cin >> n;

                vi in(n);

                int ok = 1;

                int AND = (1ll << 32) - 1;

                for(auto &p : in){
                        cin >> p;
                        AND = (AND & p);
                }
                
                int mini = *min_element(all(in));

                ok = (AND == mini);

                int cnt = count(all(in), mini);

                cout << (nP2(cnt) * fac[n - 2] * ok)%MOD << endl;
        }

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/