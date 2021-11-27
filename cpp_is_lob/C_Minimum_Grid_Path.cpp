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

vi Cost; int ans, n;

set<int> even, odd;

int Sum;

void F(){
        for(int i = 2; i < n; i += 1){
        
                if(i%2){
                        
                        Sum -= (n - i/2)*(*odd.begin());

                        odd.insert(Cost[i]);

                        Sum += Cost[i];

                        Sum += (n - i/2 - 1)*(*odd.begin());
                }
                else{
                        Sum -= (n - i/2)*(*even.begin());

                        even.insert(Cost[i]);

                        Sum += Cost[i];

                        Sum += (n - i/2 - 1)*(*even.begin());
                }
                ans = min(ans, Sum);
        }  
}

int32_t main(){
        FIO

        w(t){
                cin >> n;

                Cost = vi(n);

                for(auto &p : Cost) cin >> p;

                even.clear(); odd.clear();

                even.insert(Cost[0]); odd.insert(Cost[1]);

                ans = n*(Cost[0] + Cost[1]);

                Sum = ans;

                F();

                cout << ans << endl;
    }   

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/