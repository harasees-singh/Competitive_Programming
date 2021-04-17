#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> s;
    int temp=n;
    while(temp--)
    {
        string temp;
        cin >> temp;
        s.push_back(temp);
    }
    // cout << "the length of the current string is " << s[0].size() << endl;
    string ans="";
    for(int i=0; i<s[0].size(); i++)
    {
        char current = 'x';
        bool parity=true;
        for(int j=0; j<n; j++)
        {
            if(s[j][i] == '?') {
                continue;
            }
            else if(parity || current==s[j][i]) {
                current=s[j][i]; parity=false;
                //cout << s[j][i] << endl;
            }
            else {
                current='?'; break;
            }
            //cout << current << "aye yo" << endl;
        }
        ans=ans+current;
    }
    cout << ans << endl;
}