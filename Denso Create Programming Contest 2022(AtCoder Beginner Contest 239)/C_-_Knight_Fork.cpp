// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
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
#define fps(x, y)                       fixed<<setprecision(y)<<x
#define double long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE
int x1, Y, x2, y2; 
bool check(int x, int y){
        return (x1 - x) * (x1 - x) + (Y - y) * (Y - y) == 5;
}
int D(int x, int y){
        return (x1 - x) * (x1 - x) + (Y - y) * (Y - y);
}
pair<double, double> reduce(int a, int b){
        int g = __gcd(abs(a), abs(b));
        // cout << g << endl;
        pii ret = make_pair(a/g, b/g);
        // cout << a <<  ' ' << b<< endl;

        // cout << ret.ff << ' ' << ret.ss << endl; 
        return ret;
}
int32_t main(){
        
        FIO

        cin >> x1 >> Y >> x2 >> y2;

        int d = (x1 - x2) * (x1 - x2) + (Y - y2) * (Y - y2);

        if(d > 20){ cout << "No" << endl; return 0;}

        pair<double, double> mid = {(x1 + x2)/2.0, (Y + y2)/2.0};

        pair<double, double> slope = reduce(-(x2 - x1), (y2 - Y));

        double x = (x1 + x2)/2.0, y = (Y + y2)/2.0;
        double copy(y);
        int it = 1;
        while(true){
                if((int)x == x and (int)y == y){
                        if(check(x, y)){
                                cout << "Yes"; return 0;
                        }
                }
                x += 0.5, y = copy + it * 0.5 * (slope.ff) / (slope.ss);
                it++;
                if(D(x, y) > 5) break;
        } 
        x = (x1 + x2)/2.0, y = (Y + y2)/2.0;
        while(true){
                if((int)x == x and (int)y == y){
                        if(check(x, y)){
                                cout << "Yes"; return 0;
                        }
                }
                x -= 0.5, y -= 0.5 * (slope.ff) / (slope.ss);
                if(D(x, y) > 5) break;
        }     
        cout << "No";       

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/