#include<iostream>
#include<vector>
#include<set>
#include<map>
#define vi vector<int>
#define loop(j, n) for(int i=j; i<n; i++)
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, w, wr;
        cin >> n >> w >> wr;
        vi weights(0);
        loop(0, n)
        {
            int temp;
            cin >> temp;
            weights.push_back(temp);
        }
        map<int, int> frequency;
        int ans=0;
        loop(0, n)
        {
            // if(frequency.find(weights[i])!=frequency.end()) {frequency[weights[i]]++;}
            // else frequency[weights[i]]=1;
            frequency[weights[i]]++;
        }
        int sum_required = w-wr;
        auto it = frequency.begin();
        while(it != frequency.end())
        {
            if(it->second %2 == 0) {ans+= it->second * it->first;}
            else {ans+= (it->first)*((it->second)- 1);}
            // cout << "key " << it->first << " " << "value " << it->second << endl;
            it++;
        }
        // cout << "answer " << ans << endl;
        ans>=sum_required ? cout << "YES" << endl : cout << "NO" << endl;
        // cout << "----------------------------------" << endl;
        
    }
    return 0;
}

