#include<iostream>
#define loop(j, n) for(int i=j; i<n; i++)
#include<vector>
#include<set>
using namespace std;
int val_needed;
int n;
set<int> denominations_set;
int count_minimum(vector<int> &denominations, int val, int count)
{
    int mini_count=INT32_MAX;
    if(val<0)return INT32_MAX;
    if(denominations_set.find(val)!=denominations_set.end()){return count+1;}
    for(int i=0; i<denominations.size(); i++){mini_count=min(count_minimum(denominations, val-denominations[i], count+1), mini_count);cout << mini_count << endl;}
    return mini_count;
}
int main()
{
    cin>>n;
    float temp;
    cin>>temp;
    val_needed=100*temp;
    vector<int> denominations(n, 0);
    loop(0, n)
    {
        cin >> temp;
        denominations_set.insert(temp*100);
        denominations[i] = temp*100;
    }
    cout << "ran successfully" << endl;
    // cout << denominations.size();
    
    cout << count_minimum(denominations, val_needed, 0) << endl;
}