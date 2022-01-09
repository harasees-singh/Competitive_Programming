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
        vi I(n);
        for(auto &p : I) cin >> p;
        int good = 0;
        mii cnt;
        l(i,0,n){ 
            
            good = good or (I[i] == I[(i + 1)%n]);

            cnt[I[i]]++;
        
        }

        if(cnt.size() == 1){
            cout << 1 << endl; 
            l(i, 0, n) cout << 1 << space; cout << endl; continue;
        }
        if(n%2 == 0){
            cout << 2 << endl; 
            l(i, 0, n) cout << 1 + (i%2) << space; cout << endl; continue;
        }
        if(good){
            bool done = 0;
            cout << 2 << endl; cout << 1 << ' ';
            bool parity = 1;
            l(i, 1, n){
                if(!done and I[i] == I[i - 1]){
                    
                    cout << 2 - (parity) << space; 
                    done = 1;
                }
                else cout << 2 - (parity^1) << space, parity ^= 1;
            }
            cout << endl;
        }
        else{
            cout << 3 << endl;
            l(i, 0, n - 1){
                cout << 1 + (i%2) << space;
            }
            cout << 3 << endl;
        }
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