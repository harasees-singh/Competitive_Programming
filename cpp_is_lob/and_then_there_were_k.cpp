#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int32_t main(){
    int t; cin >> t;
    while(t--)
        {
            int n; cin >> n;
        cout << (1 << (int)(log2(n))) -1 << endl;
            
        }
    return 0;
}