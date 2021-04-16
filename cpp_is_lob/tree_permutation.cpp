#include<iostream>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main()
{
    int t, n, s;
    cin>> t;
    while(t--)
    {
        map<int, int> Tree_child_parent;
        cin>>n>>s;
        n--;
        int temp = n;
        while(temp--)
        {
            int parent, child;
            cin >> parent >> child;
            Tree_child_parent[child] = parent;
        }
        vector<int> original_values(0), permuted_values(0);
        n++;
        temp=n;
        while(temp--)
        {
            int val;
            cin>>val;
            original_values.push_back(val);
        }
        temp=n;
        while(temp--)
        {
            int val;
            cin>>val;
            permuted_values.push_back(val);
        }
        // cout << original_values[0] << endl << original_values[1] << endl << permuted_values[0] << endl << permuted_values[1] << endl;
        vector<int>visited(original_values.size(), 0);
        map<int, int>original_permuted_values;
        for(int i =0; i<original_values.size(); i++)
        {
            original_permuted_values[original_values[i]] = permuted_values[i];
        }
        int i=0;
        int permuted_val = 0;
        
    }
}