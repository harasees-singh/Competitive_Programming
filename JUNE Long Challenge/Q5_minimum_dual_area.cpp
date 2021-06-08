#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
int32_t main(){
    FIO
    test_cases_loop{
        int points;
        cin >> points;
        vector<pii> coordinates;
        vector<int> x_dehydrated, y_dehydrated;
        loop(i, 0, points){
            int tempx, tempy;
            
            cin >> tempx >> tempy; x_dehydrated.pb(tempx); y_dehydrated.pb(tempy); coordinates.push_back({tempx, tempy});
        }
        sort(all(x_dehydrated)); sort(all(y_dehydrated));
        int diffx=0, diffy=0;
        int xval=0, yval=0;
        loop(i, 1, sz(x_dehydrated)){
            if(x_dehydrated[i] - x_dehydrated[i-1] > diffx) diffx = x_dehydrated[i] - x_dehydrated[i-1], xval = i-1;
            if(y_dehydrated[i] - y_dehydrated[i-1] > diffy) diffy = y_dehydrated[i] - y_dehydrated[i-1], yval = i-1;
        }
        int xrange = 0;
        int yrange = 0;
        int xrange2 = 0;
        int yrange2 = 0;
        int ymin=coordinates[0].second, ymax=coordinates[0].second;
        sort(all(coordinates));
        loop(x, 0, xval+1){
            coordinates[x].second < ymin ? ymin = coordinates[x].second : ymin = ymin;
            coordinates[x].second > ymax ? ymax = coordinates[x].second : ymax = ymax;
        }
        yrange = ymax - ymin;

        ymin=coordinates[0].second, ymax=coordinates[0].second;
        loop(x, xval+1, points){
            coordinates[x].second < ymin ? ymin = coordinates[x].second : ymin = ymin;
            coordinates[x].second > ymax ? ymax = coordinates[x].second : ymax = ymax;
        }
        yrange2 = ymax - ymin;

        int xmin=coordinates[0].first, xmax=coordinates[0].first;

        sort(all(coordinates), [](pii hell, pii heaven){return hell.second < heaven.second;});

        // cout << "sorted coordinates " << coordinates[0].second << space << coordinates[1].second << endl;
        loop(x, 0, yval+1){
            coordinates[x].first < xmin ? xmin = coordinates[x].first : xmin = xmin;
            coordinates[x].first > xmax ? xmax = coordinates[x].first : xmax = xmax;
        }
        xrange = ymax-ymin;

        xmin=coordinates[0].first, xmax=coordinates[0].first;

        loop(x, yval+1, points){
            coordinates[x].first < xmin ? xmin = coordinates[x].first : xmin = xmin;
            coordinates[x].first > xmax ? xmax = coordinates[x].first : xmax = xmax;
        }
        xrange2 = xmax - xmin;
        // cout << "ranges " << xrange << space << yrange << endl;
        cout << min(yrange*(x_dehydrated[xval] - x_dehydrated[0]) + yrange2*(x_dehydrated[points-1] - x_dehydrated[xval+1]), xrange*(y_dehydrated[yval] - y_dehydrated[0]) + xrange2*(y_dehydrated[points-1] - y_dehydrated[yval+1])) << endl;
    }
    return 0;
}