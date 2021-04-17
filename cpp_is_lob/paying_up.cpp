#include<iostream>
#include<vector>
using namespace std;
#define for(j, n) for(int i=j; i<n; i++)
bool recursive_possiblities(const vector<int> &vals, int val_required, int current_val, int index)          // const will stop the function from altering our vector since we are passing the vector by reference. if we pass vector by copy it will take unnecessary time while copying.
{
    if(current_val == val_required) return true;
    else if (index== vals.size() || current_val > val_required) return false;
    else return recursive_possiblities(vals, val_required, current_val + vals[index], index+1) || recursive_possiblities(vals, val_required, current_val, index+1);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n>> m;
        vector<int> note_vals(0);

        for(0, n)
        {
            int temp;
            cin >> temp;
            note_vals.push_back(temp);
        }
        bool ans = recursive_possiblities(note_vals, m, 0, 0);
        if(ans) cout << "Yes" << endl;
        cout << "No" << endl;
    }
}