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
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    int n; 

    cin >> n;

    map<pii, int> Cost;
    unordered_map<int, vi> DirectedRoad;
    l(i, 0, n){
        int a, b, c;

        cin >> a >> b >> c;
        DirectedRoad[a].push_back(b);
        DirectedRoad[b].push_back(a);
        Cost[{a, b}] = 0;

        Cost[{b, a}] = c;
    } 

    int clockwise, anticlockwise;
    clockwise = (*DirectedRoad.begin()).ff;
    // 
    int cost = 0;
    int minima = infinity;
    l(i, 0, 2){
            int back = clockwise;

            anticlockwise = ((*DirectedRoad.begin()).ss)[i];

            while(anticlockwise != clockwise){

                    cost += Cost[{back, anticlockwise}];

                    int t = anticlockwise;
                    
                    anticlockwise = (DirectedRoad[anticlockwise][0] == back ? DirectedRoad[anticlockwise][1] : DirectedRoad[anticlockwise][0]);

                    back = t;
            }
            cost += Cost[{back, anticlockwise}];

            minima = min(minima, cost);

            cost = 0;
    }

    cout << minima << endl;
}
