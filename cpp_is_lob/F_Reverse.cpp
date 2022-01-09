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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

// x should be substr of y
// y should be of the form ..1111 x 1111..
// 10000 -> 100001 case handle
// 10100 -> 101 also handled

string bits(int n){
        string ret;

        while(n){
                ret += (n&1 ? '1' : '0');

                n/=2;
        }
        reverse(all(ret));

        return ret;
}
bool ok(string x, string y){
        l(i, 0, y.size()){
                if(y[i] == '0'){
                        return false;
                }
                if(y.substr(i, x.size()) == x){
                        int j;
                        bool done = false;
                        for(j = i + x.size(); j < y.size(); j++){
                                done = true;
                                if(y[j] == '0') return false;
                        }
                        return (x[x.size() - 1] == '1' or done);
                } 
        }
        return false;
}
int32_t main(){
        
        FIO

        int x, y; cin >> x >> y;
        if(x == y){
                cout << "YES" << endl; return 0;
        }
        int xpy = x;
        while(xpy%2 == 0)
                xpy/=2;
        string X = bits(x);
        string Y = bits(y);
        bool yes = ok(X, Y);
        reverse(all(X));
        yes = yes or ok(X, Y);

        string xx = bits(xpy);

        yes = yes or ok(xx, Y);
        reverse(all(xx));
        yes = yes or ok(xx, Y);

        cout << (yes ? "YES" : "NO") << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/