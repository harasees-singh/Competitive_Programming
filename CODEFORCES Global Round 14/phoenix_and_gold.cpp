#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> peices(0);
        for(int i=0; i<n; i++)
        {
            int temp;
            cin >> temp;
            peices.push_back(temp);
        }
        sort(peices.begin(), peices.end());
        int sum=0;
        int theif=INT32_MAX;
        for(int j=0; j<n; j++)
        {
            if(x-sum == peices[j]) theif=peices[j];
            else sum+=peices[j];
        }
        if(theif!=peices[peices.size()-1])
        {
            cout << "YES" << endl;
            for(int i=0; i<n; i++)
            {
                if(peices[i] != theif) cout << peices[i] << " ";
            }
            if(theif != INT32_MAX) cout << theif << endl;
        }
        else cout << "NO" << endl;
    }
}