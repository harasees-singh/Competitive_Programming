#include<iostream>
using namespace std;
int main()
{
    int a[10][5];
    for(int i=0; i<10; i++)
        for(int j=0; j<5; j++)
        {
            int temp;
            cin >> temp;
            a[i][j] = temp;
        }
}