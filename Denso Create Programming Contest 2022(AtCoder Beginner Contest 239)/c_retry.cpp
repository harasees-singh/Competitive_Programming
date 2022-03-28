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
pair<double, double> reduce(int a, int b){
        int g = __gcd(abs(a), abs(b));
        // cout << g << endl;
        pii ret = make_pair(a/g, b/g);
        // cout << a <<  ' ' << b<< endl;

        // cout << ret.ff << ' ' << ret.ss << endl; 
        return ret;
}
double D(double x, double y, double X, double Y){
        return (X - x) * (X - x) + (Y - y) * (Y - y);
}

double ret(double coord, double go){
        
}
int32_t main(){
        FIO 

        int x, y, X, Y; cin >> x >> y >> X >> Y; 

        pair<double, double> mid = {(x + X)/2.0, (Y + y)/2.0};

        pair<double, double> slope = reduce(-(x - X), y - Y);

        double d = 5 - D(mid.ff, mid.ss, x, y);

        d = sqrt(d);

        double xpt = 

        return 0;
}
