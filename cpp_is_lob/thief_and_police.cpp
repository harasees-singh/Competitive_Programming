#include<iostream>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        int a, b;
        cin >> a >> b;
        int cost_for_theif, cost_for_police;
        cost_for_theif = (n-x)+(m-y);
        cost_for_police = max((n-a), (m-b));
        cost_for_theif<=cost_for_police ? cout << "yes": cout << "no" << endl;

    }   
}