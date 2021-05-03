#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    map<int , int> initial;
    map<int, int> final;

    while(t--)
    {
        int n, m, diff_required;
        int sum=0;
        cin >> n >> m >> diff_required;
        vector<int> heights(0);
        for(int i=0; i< n; i++)
        {
            int temp;
            cin >> temp;
            sum+=temp;
            heights.push_back(temp);
        }
        sort(heights.begin(), heights.end());
        int mean = sum/n;
        int curr_sum=0;
        int diff=0;
        int i=0;
        int towers=1;
        
        while(i<n)
        {
            if(abs(mean-curr_sum)>abs(mean-curr_sum-heights[i]))
            {
                curr_sum+=heights[i];
            }
            else diff=max(diff, mean-curr_sum), curr_sum=0, towers++;
            i++;
        }
        if(diff <= diff_required && towers == m) {
            cout << "YES" << endl;
            
        }
        else cout << "NO" << endl;
    }
}