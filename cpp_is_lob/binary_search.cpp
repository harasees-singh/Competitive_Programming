#include<iostream>
using namespace std;
bool good(int mid)
{
    int hidden_number = 9999999;
    if(mid<hidden_number)
    {
        return true;
    }
    return false;
}
int main()
{
    int l=0;
    long long int r = 10000000000;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(good(mid))
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    
    }
    cout << l << " " << r;
    return 0;
}