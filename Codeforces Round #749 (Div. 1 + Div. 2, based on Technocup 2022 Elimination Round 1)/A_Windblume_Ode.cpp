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

bool isPrime(int n){

        bool ok = 1;

        l(i, 2, sqrt(n) + 1){

                ok = ok & (bool)(n%i);
        }

        return ok;
}

int32_t main(){
    FIO

    w(t){

            int n; cin >> n;

            vi I(n);

            for(auto &p : I)
                    cin >> p;
            
            int S = accumulate(all(I), 0ll);

            if(isPrime(S)){

                    bool f = 1;

                    cout << n - 1 << endl;

                    for(int i = 1; i <= n; i++){
                            int p = I[i - 1];
                            if(f and p%2){
                                    f = 0; continue;}
                            cout << i << space;}
                    cout << endl;
            }
            else{
                    cout << n << endl;

                    for(int i = 1; i <= n; i++)
                            cout << i << space;
                            cout << endl;
            }
    }

}