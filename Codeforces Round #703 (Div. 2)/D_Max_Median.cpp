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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

// approach is wrong because of the assumption that best median can be found out by solely considering k len subarrays
// but infact a subarray of len greater than k can yeild better median
// example 1 2 1 3 and k = 2, here max median of 2 len segments is 1
// but median of the seg 2 1 3 is 2 > 1

int32_t main(){
    FIO

    int n, k; cin >> n >> k;

    pbds s;

    vi I(n);

    for(auto &p : I)
            cin >>  p;

    l(i, 0, k)
        s.insert(make_pair(I[i], i));

    int maxi = 0;

    l(i, 0, n - k + 1){

            maxi = max(maxi, (*s.find_by_order((k - 1)/2)).ff);

            s.erase(make_pair(I[i], i));
            if(i < n - k)
                    s.insert(make_pair(I[i + k], i + k));
    }

    cout << maxi << endl;

}
