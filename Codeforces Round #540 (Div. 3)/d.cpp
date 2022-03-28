// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
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

MOD_DEFINE
vi in;
int m;
int mn = infinity;
bool good(int mid){
        // can complete by drinking mid cups a day ? 
        int i;
        int net = 0;
        for(i = 0; i < sz(in) and net < m; i++){
                net += max(0ll, (in[i] - (i / mid)));
        }
        if(net < m) return false;
        mn = min(mn, mid);        // number of days
        return true;
}
int32_t main(){
        FIO 

        int n; cin >> n >> m;

        in = vi(n);

        for(auto &p : in) cin >> p;

        sort(in.rbegin(), in.rend());

        int l = 1, r = n;

        while(l <= r){
                int mid = (l + r)/2;

                // mid number days

                // assumption : if we can complete the work in m days then we can complete in m + 1 days as well

                if(not good(mid)){
                        l = mid + 1;
                }
                else 
                        r = mid - 1;
        }
        cout << (mn == infinity ? -1 : mn) << endl;

        return 0;
}
