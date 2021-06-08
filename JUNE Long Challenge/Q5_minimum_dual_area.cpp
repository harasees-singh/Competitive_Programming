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

        loop(i, 0, points){

            int tempx, tempy;     
            cin >> tempx >> tempy; coordinates.push_back({tempx, tempy});
        }

        if(points == 1){cout << 0 << endl; continue;}

        sort(all(coordinates));

        vi x_prefix_min(points); vi x_prefix_max(points); vi x_suffix_min(points); vi x_suffix_max(points);

        int x_min=coordinates[0].second, x_max = coordinates[0].second;

        loop(i, 0, points){
            int curr = coordinates[i].second;
            x_min = min(x_min, curr); x_max = max(x_max, curr);
            x_prefix_max[i] = x_max; x_prefix_min[i] = x_min;
        }

        x_min=coordinates[points-1].second, x_max = coordinates[points-1].second;

        for(int i=points-1; i>=0; i--){
            int curr = coordinates[i].second;
            x_min = min(x_min, curr); x_max = max(x_max, curr);
            x_suffix_max[i] = x_max; x_suffix_min[i] = x_min;
        }
        
        // everything for x is ready; y min in a domain and y max in a domain;
        int ansx=infinity;
        loop(i, 0, points-1){
            int parition = coordinates[i].first;
            int next_partition = coordinates[i+1].first;
            int area = (parition - coordinates[0].first)*(x_prefix_max[i] - x_prefix_min[i]) + (coordinates[points-1].first - next_partition)*(x_suffix_max[i+1] - x_suffix_min[i+1]);
            ansx = min(area, ansx);
        }

        // -=---------------------------------------------------------------------------------

        sort(all(coordinates), [](pii hell, pii heaven){return hell.second < heaven.second;});
        

        x_min=coordinates[0].first, x_max = coordinates[0].first;

        loop(i, 0, points){
            int curr = coordinates[i].first;
            x_min = min(x_min, curr); x_max = max(x_max, curr);
            x_prefix_max[i] = x_max; x_prefix_min[i] = x_min;
        }

        x_min=coordinates[points-1].first, x_max = coordinates[points-1].first;

        for(int i=points-1; i>=0; i--){
            int curr = coordinates[i].first;
            x_min = min(x_min, curr); x_max = max(x_max, curr);
            x_suffix_max[i] = x_max; x_suffix_min[i] = x_min;
        }
        
        // everything for x is ready; y min in a domain and y max in a domain;
        int ansy=ansx;
        loop(i, 0, points-1){
            int parition = coordinates[i].second;
            int next_partition = coordinates[i+1].second;
            int area = (parition - coordinates[0].second)*(x_prefix_max[i] - x_prefix_min[i]) + (coordinates[points-1].second - next_partition)*(x_suffix_max[i+1] - x_suffix_min[i+1]);
            ansy = min(area, ansy);
        }
        cout << ansy << endl;
    }
    return 0;
}