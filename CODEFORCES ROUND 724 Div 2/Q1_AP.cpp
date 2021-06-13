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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int32_t main(){
    test_cases_loop{
        int n; cin >> n;
        vi ele;
        bool negative=false;
        loop(i, 0, n){
            int temp; cin >> temp; ele.pb(temp); if(temp<0)negative=true;
        }
        if(negative){cout << "NO" << endl; continue;}
        sort(all(ele));
        int gcd__ = gcd(ele[0], ele[1]);
        loop(i, 2, sz(ele))gcd__ = gcd(gcd__, ele[i]);
        vi answer;
        if(ele[0]==0){
            for(int j=0; j<=ele[sz(ele)-1]; j+=gcd__){
                answer.pb(j);
            }
        }
        else{
            for(int j=gcd__; j<=ele[sz(ele)-1]; j+=gcd__){
                answer.pb(j);
            }
        }
        if(sz(answer)>300){cout << "NO" << endl; continue;}
        cout << "YES" << endl;
        cout << sz(answer) << endl;
        for(auto a: answer)cout << a << space;
        cout << endl;
    }
    
    return 0;
}