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
        int n; cin >> n;

        vi a(n), b(n);

        for(auto &p : a) cin >> p;
        for(auto &p : b) cin >> p;

        sort(all(a));
        sort(all(b));

        int id = n/4;

        int pta = id;
        int ptb = id;
        // pta = 0

        int suma = 0;
        l(i, pta, n) suma += a[i];

        int sumb = 0;

        l(i, ptb, n) sumb += b[i];

        int cnt = 0;

        if(suma >= sumb){
            cout << 0 << endl;
            continue;
        }
        
        int len = n + 1;
        while(suma < sumb){
            cnt++;
            suma += 100;
            if(len%4 == 0){
                suma -= a[pta], pta++;
                
            }
            else 
                if(ptb > 0) sumb += b[ptb - 1], ptb--;

            if(suma >= sumb) break;
            len++;
        }   
        cout << cnt << endl;

    }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/