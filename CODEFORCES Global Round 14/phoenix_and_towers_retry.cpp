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
int Ceil(double lol)
{
    if(lol - (int) lol < 0.5) return (int)lol;
    else return (int) lol+1;
}
void Print(vi &answer)
{
    for(auto i:answer)
    {
        cout << i << " " ;
    }
    cout << endl;
}
int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        double m;
        cin >> n >> m >> x;
        vi blocks(0);    
        int sum=0;
        loop(i, 0, n)
        {
            int temp;
            cin >> temp;
            blocks.pb(temp);
            sum+=temp;
        }
        
        // cout << "m is " << m << endl;
        int upper_limit = ceil(sum/m);
        int curr_sum=0;
        vi answer(0);
        int counter=1;
        int i=0;

        // printf("upper limit is %lld\n", upper_limit);
        // cout << "sum="<< sum << endl;
        while(i<n)
        {   
            if(abs(curr_sum - upper_limit) > abs(curr_sum + blocks[i] - upper_limit))
            {   
                curr_sum+=blocks[i];
                answer.pb(counter);
                
            }
            else counter+=1, i--, curr_sum=0;
            i++;
            // cout << "counter = " << counter << endl;
            
        }   
        if(answer[blocks.size()-1]==m) cout << "YES" << endl, Print(answer);
        else cout << "NO" << endl;
    }
}
