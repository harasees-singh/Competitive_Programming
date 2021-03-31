#include<iostream>
using namespace std;
int main()
{
    int a[20];
    a[0] = 45;
    a[19] = 45;
    for(int i = 0; i<20; i++)
    {
        printf("%d ", a[i]);
    }
    
    int n = 4;
    int temp;
    while(n--)
    {
        cin >> temp;
        printf("%d", temp);
    }
}