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

int operation(int val){return val*(val+1)/2;}

int32_t main(){
    FIO
    test_cases_loop{
        string s;
        cin >> s;
        int ans=0;
        // need three pointers for one for odd 1s, one for even 1s and one last for '?';
        // add odd and even counts and always subtrace the '?' count;
        int odd_one_count=0, even_one_count=0, question_mark_count=0;
        loop(i, 0, sz(s)){
            char curr= s[i];

            if(curr == '?'){question_mark_count++; odd_one_count++; even_one_count++; continue;}

            ans -= operation(question_mark_count); question_mark_count=0;
            
            int *murder, *elixir;
            
            if((i%2) ^ (s[i]=='1')){murder = &odd_one_count, elixir = &even_one_count;} else{murder = &even_one_count, elixir = &odd_one_count;}
            
            (*elixir)++; ans+=operation(*murder); *murder=0;
        }
        ans += operation(even_one_count) + operation(odd_one_count); ans -= operation(question_mark_count);
        cout << ans << endl;
    }
}

