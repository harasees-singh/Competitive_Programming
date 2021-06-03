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
#define infinity 8999999999999999999
#define debug(a) cout << "debug " <<a << endl;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define pii pair<int, int>
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
int32_t main(){
    test_cases_loop{
        int n; cin >> n;
        int available_fule=0;
        vector<pii> dist_fuel;
        loop(i, 0, n){
            int d, f;
            cin >> d >> f;
            available_fule+=f;
            dist_fuel.push_back({d, f});
        }
        priority_queue<int, vi, less<int>> hiphop;
        int dist, fuel; cin >> dist >> fuel;
        // cout << "n " << n << endl;
        loop(j, 0, n){
            int something = dist - dist_fuel[j].first;
            // cout << "something " << something << endl;
            dist_fuel[j] = {something, dist_fuel[j].second};
        }
        sort(all(dist_fuel));
        // cout << "working " << endl;
        
        if(available_fule+fuel < dist){cout << -1 << endl; continue;}
        if(fuel >= dist){cout << 0 << endl; continue;} 
        //------------------------------------------
        int ans=0;
        if(fuel>=dist_fuel[0].first){
            int i=1;
            hiphop.push(dist_fuel[0].second);
            while(i<sz(dist_fuel)){
                
                if(fuel >= dist_fuel[i].first){hiphop.push(dist_fuel[i].second);i++; }
                else{
                    if(!sz(hiphop))break;
                    // cout << "hey" << endl;
                    int fill=hiphop.top(); fuel+=fill; hiphop.pop(); ans++; 
                }
            }
            
            while(sz(hiphop)){
                // cout << "fuel = " << fuel << " " << "dist " << dist << endl;
                if(fuel < dist){
                    fuel+=hiphop.top(); hiphop.pop(); ans++; 
                    // cout << "hey " << endl;
                }
                else break;
            }
            fuel >= dist ? cout << ans << endl: cout << -1 << endl;
            
        }
        else{cout << -1 << endl;}
        
    }
    return 0;
}