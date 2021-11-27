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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    w(t){
        int p, q; cin >> p >> q;

        int Q(q);

        if(p < q or p%q){
            cout << p << endl; continue;
        }
        vi div;
        
        int i = 2;

        while(q > 1 and i*i <= q){
            int cur = 1;

            if(q%i == 0) cur*=i, q/=i;

            while(q%i == 0) q/=i;

            if(cur > 1) div.pb(cur); 

            i++;
        }
        if(q > 1) div.pb(q);

        int maxi = 0;

        assert(div.size());

        for(auto j : div){
            int cpy = p;

            while(cpy%Q == 0){
                cpy /= j;
            }

            maxi = max(cpy, maxi);
        }

        cout << maxi << endl;
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