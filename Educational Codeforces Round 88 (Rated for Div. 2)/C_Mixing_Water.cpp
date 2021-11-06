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
int h, c, t;
bool f(int p2, int p1){

        int P = (2*p1 - 1)*(2*p2 - 1);

        int x1 = (p2*h + (p2 - 1)*c)*(2*p1 - 1) - t*P;

        int x2 = (p1*h + (p1 - 1)*c)*(2*p2 - 1) - t*P;

        return abs(x1) < abs(x2);
}

int32_t main(){
    FIO
    int T; cin >> T;

    while(T--){

            cin >> h >> c >> t;

            if((h + c) >= 2*t)
                    {cout << 2 << endl; continue;}
            
            if(t >= h){
                    cout << 1 << endl; continue;
            }

            int p = (t - c)/(2*t - h - c);
            
            assert(p);

            int p2 = p + 1;

            if(f(p2, p))
                    cout << 2*p2 - 1 << endl;
            else
                    cout << 2*p - 1 << endl;


    }

}
