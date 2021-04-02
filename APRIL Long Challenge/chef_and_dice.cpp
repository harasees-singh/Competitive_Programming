#include<iostream>
using namespace std;
int main()
{
    long long t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long ans=0;
        long long complete_pile_pips = 44*(n/4);
        int remaining = n % 4;
        if(n>=4)
        {
            if(remaining == 0)
            {
                ans = complete_pile_pips + 16;
            }
            else if(remaining == 1)
            {
                ans = complete_pile_pips + 12 + 20;
            }
            else if(remaining == 2)
            {
                ans = complete_pile_pips + 8 + 2*(20-2);
            }
            else
            {
                ans = complete_pile_pips + 4 + (40 - 4) + (20 - 2) - 3;
            }
        }
        else
        {
            if(n==1)
            {
                ans = 20;
            }
            else if(n==2)
            {
                ans = 40-4;
            }
            else if(n==3)
            {
                ans = 40-4 + 20-2 - 3;
            }
        }
        cout << ans << endl;
    }
}