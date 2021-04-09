#include<iostream>
#include<math.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    ll a, b;
    while(t--)
    {    int matches = 0;
        cin >> a >> b;
        ll sum = a+b;
        ll temp = sum;
        while(temp)
        {
            int current_digit = temp%10;
            if(current_digit == 6 || current_digit == 0 || current_digit == 9)
            {
                matches = matches + 6;
            }
            else if(current_digit == 1)
            {
                matches = matches + 2;
            }
            else if(current_digit == 2 || current_digit == 5 || current_digit == 3)
            {
                matches = matches + 5;
            }
            else if(current_digit == 8)
            {
                matches = matches + 7;
            }
            else if(current_digit == 4)
            {
                matches = matches + 4;
            }
            else matches = matches + 3;

            temp = temp/10;
        }
        cout<< matches<< endl;


    }
}