#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    
    int sum=0;
    int sed = pow(10, 9) + 7;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        sum+=temp;
        sum = (sum + sed)% sed;             // to avoid calculating remainder when sum is negative

    }
    
    int q;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        int x;
        cin >> x;
        sum+=sum;
        
        sum = sum % sed;
        cout << sum << endl;
    }
    return 0;
}