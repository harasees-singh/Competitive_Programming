#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int count=0;
    
    int i=0;
    while(i<s.size())
    {
        if(s[i]=='\\')
        {
            if(i<s.size()-1 && s[i+1]=='n')
            {
                count ++;
                i++;
            }
        }
        i++; 
    }
    cout << count << endl << count +1 << endl;
    i =0;
    while(i < s.size())
    {
        if(s[i]!='\\')
        {
            cout << s[i];
        }
        else
        {
            if(i<s.size()-1 && s[i+1]=='n')
            {
                cout << endl;
                i++;
            }
            else
            {
                cout << '\\';
            }
        }
        i++;
    }
    

}