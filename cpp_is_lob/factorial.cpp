#include<iostream>
using namespace std;
int factorial(int a)
{
    if(a==1) return 1;
    //if(a==0) return 1;
    return factorial(a-1)*a;
}
int main()
{
    int ans = factorial(5);
    cout << ans;
}