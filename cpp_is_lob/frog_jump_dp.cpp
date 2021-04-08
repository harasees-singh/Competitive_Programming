#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        if(n==1)
        {
            cout<<0;
            return 0;
        }
        if(n==2)
        {
            cout<<abs(arr[0]-arr[1]);
            return 0;
        }
        int a=0, b=abs(arr[0] - arr[1]);
        int c = -1;
        for(int i=3; i<=n; i++)
        {
            c = min(a + abs(arr[i] - arr[i-2]), b+ abs(arr[i] - arr[i-1]));
            a = b;
            b = c;
        }
        cout << c;
        return 0;
    }
}