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
#define debug(a) cout << a << endl;
#define debug_(a, b) cout << a << " " << b << endl;
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
string make_string_2(vi &a){
    // cout << "vector ";
    // loop(i, 0, a.size()){cout << a[i] << space;}
    // cout << endl;
    string ans="";
    int count=0;
    for(auto inti:a){
        
        string ch = to_string(inti);
        ans += ch; 
        if(count+1 != a.size()) ans+='.';
        count++;
    }
    return ans;
}
string make_string(vi &a){
    string potentanswer = make_string_2(a);
    int last = potentanswer.size()-1;
    string num;
    while(last>=0 And potentanswer[last]!='.'){
        num+=potentanswer[last];
        // cout << "hey " <<  num << endl;
        last--;
        potentanswer.pop_back();
    }
    reverse(num.begin(), num.end());
    
    // string to_be_removed = potentanswer[potentanswer.size()-1];
    // potentanswer.pop_back(); potentanswer.pb(to_be_removed+1);
    int temp = stoi(num);
    potentanswer+= to_string(temp+1);
    return potentanswer;
}
int32_t main(){
    FIO;
    test_cases_loop{
        int n; cin >> n;
        int copy=n ;
        int curr = 1;
        vi parent = {1};
        copy--;
        int temp; cin >> temp;
        cout << 1 << endl;
        while(copy--){
            int temp;
            cin >> temp;
            
            if(temp == parent[(int)parent.size()-1]+1){cout << make_string(parent) << endl; parent[(int)parent.size()-1]++;}                // make string will add 1 to the last char
            else if(temp==1){cout << make_string_2(parent) << ".1" << endl; parent.pb(1);}
            else{
                while(temp!=parent[(int)parent.size()-1]+1)parent.pop_back();
                
                cout << make_string(parent) << endl;parent[(int)parent.size()-1]++;
            }
        }
    }
}