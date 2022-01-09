// ਹਰਅਸੀਸ ਸਿੰਘ

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
// 0 equal
// 1 <
// 2 >
int get(int x1, int x2, int p){
        if(p < 0){
                return 1;
        }
        while(p-- and x1 < x2){
                x1 *= 10;
        }
        if(x1 == x2){
                return 0;
        }
        else if(x1 < x2){
                return 1;
        }
        return 2;
}

int32_t main(){
        
        FIO

        w(t){
                int x1, p1; cin >> x1 >> p1;

                int x2, p2; cin >> x2 >> p2;
                
                int ret;

                if(x1 < x2){
                        ret = get(x1, x2, p1 - p2);
                
                        if(ret == 0){
                                cout << "=";
                        }
                        else if(ret == 1){
                                cout << "<";
                        }
                        else 
                                cout << ">";
                }
                else{
                        ret = get(x2, x1, p2 - p1);
                
                        if(ret == 0){
                                cout << "=";
                        }
                        else if(ret == 1){
                                cout << ">";
                        }
                        else 
                                cout << "<";
                }
                cout << endl;
        }
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/