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
#define int long long
#define vi vector<int>
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define pb(n) push_back(n)
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    loop(i, 0, t){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int j = 0;
        char temp = s[j];
        char x = 'a';
        bool var = true;
        vi check(26, 0);
        check[temp - x] = 1;
        while (j < n){
            cout<<j<<endl;
            if (temp != s[j]){
                if (check[s[j] - x] == 1) {var = false; break;}
                check[s[j] - x] = 1;
                temp = s[j];
            j++;
            }
        }
        if (var) {cout<<"YES"<<endl; continue;}
        cout<<"NO"<<endl;
    }
    return 0;
}