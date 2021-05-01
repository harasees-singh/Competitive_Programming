#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int l;
        cin >> l;
        string s;
        cin >> s;
        vector<float> prefix= { (float) ( (int) s[0]-48)};
        for(int i=1; i<l; i++)
        {
            prefix.push_back(prefix[i-1] + (int) s[i]-48);
        }
        float ans=0;
        for(int i=0; i<l; i++)
        {
            ans = max(ans, prefix[i]/(i+1));
        }
        // cout << (int) s[0] << endl;
        // cout << "ans = " << ans << endl;
        if(ans >= 0.5) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}