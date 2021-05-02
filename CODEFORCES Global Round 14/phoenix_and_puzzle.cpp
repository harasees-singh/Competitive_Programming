#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            cout << "NO" << endl;
        }
        else if((int) log2(n) == log2(n))
        {
            cout << "YES" << endl;
        }
        else if((int) sqrt(n/2.0) == sqrt(n/2.0))
        {
            cout << "YES" << endl;
        }
        else if((int) sqrt(n/4.0) == sqrt(n/4.0))
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}