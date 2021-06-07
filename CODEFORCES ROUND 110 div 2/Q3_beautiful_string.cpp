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
char invert(char a){
    char ans;
    
    a=='1'? ans= '0':ans= '1'; 
    cout << "fucnt " << a << space << "answer " << ans << endl;
    return ans;
}

int32_t main(){
    FIO
    test_cases_loop{
        string s;
        cin >> s;
        int ans=0;
        int contiguous_count=1;
        mii visited;
        vi two_pointers;
        bool was_question_mark = false;
        int pointer=0;
        vi dp(sz(s));
        for(auto a:s){
            if(a=='?' And !was_question_mark)two_pointers.pb(pointer), was_question_mark=true;
            else if(a!='?') was_question_mark=false;
            pointer++;
        }
        // cout << "marks " << two_pointers[0] << space << two_pointers[1] << endl;
        char last = s[0];
        bool parity=false; if(last=='?')parity=true;

        int i=1;
        // 2 pointer approach: increment pointer 2 always, increment pointer 1 only if the next element is not '?'
        // if pointer 2 points to anything other than '?' with contiguous sum > 1 make pointer 1 = pointer 2
        // if pointer 2 is alone on a '1' or '0' with contiguous sum==1 do pointer 1 algo and then 

        // while traversing if u find a '1' or '0' and at that time contiguous sum > 1 then mark it as visited;

        while(i<sz(s)){
            char consideration = s[i];
            // cout << i << endl;
            // cout << "yo" << endl;
            
            if(consideration=='?'){contiguous_count++; last=invert(last);}
            // cout << "lol " << (consideration == invert(last)) << endl;
            if(consideration == invert(last)){contiguous_count++; last=consideration; cout << "ivert " << invert(last) << space << consideration << endl;}
            // else if(parity){
            //     ans+= contiguous_count*(contiguous_count+1)/2;
            //     contiguous_count=0; last=consideration; parity=false;
            // }
            else{
                // cout << "else " << i << endl;
                ans+= contiguous_count*(contiguous_count+1)/2; contiguous_count=1;last=consideration;
            }
            if(contiguous_count > 1){visited[i]=1; cout << "visited " << i << space << visited[i] << endl;}
            i+=1;
        }
        int sum=0;
        cout << "early " << visited[3] << space<< visited[2]<< endl;
        for(int i=sz(s)-1; i>=0; i--){
            int curr = visited[i]; sum+=curr;
            curr ==0 ? visited[i]=sum+1, sum=0: visited[i]=0;
        }
        cout << "yo " << visited[2] << space << visited[3] << endl;
        ans+= contiguous_count*(contiguous_count+1)/2;
        
        // cout << visited[2] << space << visited[1] << endl;
        for(auto p:two_pointers){
            int count=1;
            while(s[p]!='?' And visited[p]){
                count++; p++;
            }
        }
        cout << ans << endl;
    }
}

