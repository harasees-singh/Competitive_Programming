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

int32_t main(){
    FIO

    int n, m; cin >> n >> m;

    int I[m];

    l(i, 0, m)
            cin >> I[i];
    
    // n pairs of the form {i, i} will be included only if i does not appear in I.
    // O(n) pairs of the form {i, j} where i and j differ by 1 will be considered if first occurance of i is after the last occurance of j

    vi first(n + 1, infinity);
    int last[n + 1] = {0};

    l(i, 0, m)

            if(first[I[i]] == infinity)
                    first[I[i]] = i + 1;

    for(int i = m - 1; i >= 0; i--)

            if(last[I[i]] == 0)
                    last[I[i]] = i + 1;

    int cnt = 0;

    l(i, 0, n)
            if(first[i + 1] == infinity)
                    cnt++;
    // {i, i} counted

    l(i, 2, n + 1){
            if(first[i] > last[i - 1])
                    cnt++;
            if(first[i - 1] > last[i])
                    cnt++;
    }
    cout << cnt << endl;
}
