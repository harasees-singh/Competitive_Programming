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
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    // if mex is less < max then final ans is n or n + 1
    // else n + k;

    test_cases_loop{
        int n, k; cin >> n >> k;

        set<int> I;
        l(i, 0, n)
        {
            int t; cin >> t;
            I.insert(t);
        }

        int maxi = (*prev(I.end()));

        int mex = -1;

        for(auto p : I)
            if(p > mex + 1)
                break;
            else    
                mex = p;   

        // mex = max(mex, 0ll);

        mex++;

        if(mex < maxi)
            cout << n + (I.count((mex + maxi + 1)/2) == 0 and k) << endl;
        else
            cout << n + k << endl;
    }

}
