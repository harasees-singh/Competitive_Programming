#include<iostream>
using namespace std;
int main()
{
    int t, n, k;
    cin >> t;
    
    while(t--)
    {
        cin >> n >> k;
        string given;
        cin >> given;
        int count = 0;
        bool strong = false;
        for(int i=0; i<given.size(); i++)
        {
            char current = given[i];
            if(current == '*')
            {
                count++;
            }
            else
            {
                count =0;
            }
            if(count >= k)
            {
                cout << "YES" << endl;
                strong = true;
                break;
            }

        }
        if(!strong)
        {
            cout << "NO" << endl;
        }
    }
}