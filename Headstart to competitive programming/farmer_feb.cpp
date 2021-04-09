#include<iostream>
#include<math.h>
using namespace std;
bool prime(int sum)
{
    bool flag = true;
    for(int i=2; i<(int)sqrt(sum) + 1; i++)
    {
        if(sum%i == 0)
        {
            flag = false;
            break;
        }
    }
    if(flag) return true;
    return false;
}
int find_prime(int x, int y)
{
    int sum = x+y;
    int t= sum;
    for(int i = t+1;;i++)
    {
        if(prime(i))
        {
            return i-sum;
        }
    }
    
}
int main()
{
    int t, x, y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        cout << find_prime(x, y) << endl;
    }
}