#include<iostream>
using namespace std;
int main()
{
    // For each testcase, in the new line print "Odd" if the XOR in the range is odd, else print "Even".
    int t, l, r;
    cin >> t;
    
    int number_of_odds=0;
    string ans;
    // calculating number of odds
    
    // number of odds will determine the number of times xor changes from odd to even or even to odd
    // so if number_of_odds is even it will be the same as l or else different
    for(int i = 0; i<t; i++)
    {

        if((r-l+1)/2 != 0)
        {
            if(l%2!=0)
            {
                number_of_odds = (r-l+1)/2 + 1;
            }
            else
            {
                number_of_odds = (r-l+1)/2;
            }

        }
        else
        {
            number_of_odds = (r-l+1)/2;
        }

        cin >> l >> r;
        if((r-l+1)%2 != 0)          // if total numbers given are odd
        {
            if(l%2 != 0)
            {
                cout << "Odd" << endl;
                continue;
            }
            else
            {
                cout << "Even" << endl;
                continue;
            }
        }
        else
        {
            if(number_of_odds%2!=0)        
            {
                if(l%2 != 0)
            
                {
                    cout << "Even" << endl;
                    continue;
                }
                else
                {
                    cout << "Odd" << endl;
                    continue;
                }
            }
            else
            {
                if(l%2 != 0)
                {
                    cout << "Odd" << endl;
                    continue;
                }
                else
                {
                    cout << "Even" << endl;
                    continue;
                }
            }
        }   
    }
    return 0;
}