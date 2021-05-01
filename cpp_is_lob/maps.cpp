#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int, int> test;
    // test[1]++;
    // cout << test[0] << " " << test[1] << endl;
    cout << "---------------------------------------------------------" << endl;
    test.insert({1, 0});
    test.insert({8, 0});
    test.insert({4, 0});
    test.insert({3, 0});
    test.insert({0, 0});
    test.insert({69, 0});
    test[0]=0;
    test[4]=8;      // overwrite
    test[2]=0;
    test[-87]=0;
    // cout << test[4] << endl;
    for(std::map<int, int>::iterator i=test.begin(); i!=test.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }
}