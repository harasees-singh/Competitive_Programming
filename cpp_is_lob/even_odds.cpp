#include<iostream>
#define int long long
using namespace std;
int32_t main()
{
    int n, index;
    cin >> n >> index;
    if(n%2 == 0) index>n/2 ? cout << (index-n/2)*2 << endl : cout << 2*index-1 << endl;
    else index> n/2 +1 ? cout << (index-n/2 - 1)*2<< endl : cout << 2*index-1 << endl;
    return 0;
}