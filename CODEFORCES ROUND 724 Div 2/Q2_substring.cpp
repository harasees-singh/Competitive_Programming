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
string getString(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);
 
    return s;  
}
int32_t main(){
    test_cases_loop{
        int n; cin >> n;
        string s;
        cin >> s;
        set<string> ones;
        set<string> twos;
        set<string> threes;
        loop(i, 0, sz(s)){
            ones.insert(getString(s[i])); 
            if(i+1<sz(s)){ string temp = getString(s[i]) + getString(s[i+1]); twos.insert(temp);}
            if(i+2<sz(s)){ string temp = getString(s[i]) + getString(s[i+1]) + getString(s[i+2]); threes.insert(temp);}
        } 
        bool parity=true;
        for(int i=0; i<26; i++){
            if(ones.find(getString((char)('a'+i)))==ones.end()){cout << (char)('a'+i) << endl; parity=false; break;}
        }
        if(parity){
            for(int i=0; i<26; i++){
                if(!parity)break;
                for(int j=0; j<26; j++){
                    string temp = getString((char)('a'+i))+ getString((char)('a'+j));
                    // cout << temp << endl;
                    if(twos.find(temp)==twos.end()){cout << temp << endl; parity=false; break;}
                }
            }
        }
        if(parity){
            for(int i=0; i<26; i++){
                if(!parity)break;
                for(int j=0; j<26; j++){
                    if(!parity)break;
                    for(int k=0; k<26; k++){
                        string temp = getString((char)('a'+i))+getString((char)('a'+j))+getString(((char)'a'+k));
                        if(threes.find(temp)==threes.end()){cout << temp << endl; parity=false; break;}
                    }
                }
            }
        }
    }
    return 0;
}