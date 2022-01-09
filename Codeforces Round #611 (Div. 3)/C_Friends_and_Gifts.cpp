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

vi g(200000 + 1);
// int cycle[200000 + 1] = {-1};

// bool isCycle(int a, int cmp){
//     if(!a or cycle[a] == 0) return false;

//     if(g[a]==cmp){
//         return cycle[a] = 1;
//     }
//     return cycle[a] = isCycle(g[a], cmp);
// }

int findTail(int h){
    while(g[h]) h = g[h];
    return h;
}

int32_t main(){
    FIO

    int n; cin >> n;
    vi heads(n + 1, 1);
    l(i, 0, n){

        int t; cin >> t;
        g[i + 1] = t;
    }
    for(auto p : g) heads[p] = 0;
    // for(auto p : heads) cout << p << ' '; cout << endl;
    vpii circle;
    l(i, 1, n + 1){
        if(heads[i]){
            int tail = findTail(i);
            // cout << i << space << tail << endl;
            circle.pb(make_pair(i, tail));
        }
    }

    l(i, 0, sz(circle)){

        int tail = circle[i].ss;
        int head = circle[(i + 1)%(sz(circle))].ff;
        g[tail] = head;
    }
    l(i, 1, n + 1)
            cout << g[i] << space; cout << endl;
    return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/