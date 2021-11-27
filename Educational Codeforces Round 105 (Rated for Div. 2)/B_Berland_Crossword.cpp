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
int n, u, r, d, l; 

bool good(int a, int b, int c, int d){
        if(a >= 0 and b >= 0 and c >= 0 and d >= 0 and a < n - 1 and b < n - 1 and c < n - 1 and d < n - 1) return true; return false;
}

int32_t main(){
    FIO

    w(t){
            cin >> n >> u >> r >> d >> l;

            bool ok = 0;

            l(i, 0, 2){
                    l(j, 0, 2){
                            l(k, 0, 2){
                                    l(p, 0, 2){
                                            int top = u - (i + p);

                                            int right = r - (i + j);

                                            int down = d - (j + k);

                                            int left = l - (k + p);

                                            if(good(left, right, top, down)){
                                                    ok = 1; break;
                                            }
                                    }
                            }
                    }
            }
            cout << (ok ? "YES" : "No") << endl;
    }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/