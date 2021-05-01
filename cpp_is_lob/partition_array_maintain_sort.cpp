#include<iostream>
#include<vector>
#define loop(i, ini, final) for(int i=ini; i<final; i++)
#define int long long
// #define min(a, b) b <= a ? b:a
using namespace std;
int32_t main()
{
    vector<int> arr = {3, 2, 1, 5, 4};
    vector<int> prefix(0);
    vector<int> suffix(0);
    int ans=0;
    loop(i, 1, arr.size())
    {
        prefix.push_back(max(arr[i-1],arr[i]));
    }
    for(int i=arr.size()-2; i>=0; i--)
    {
        suffix.push_back(min(arr[i],arr[i+1]));
    }
    loop(i, 0, arr.size()-1)
    {
        if(prefix[i]<suffix[i+1]) ans++;
    }
    cout << ans << endl;
}
