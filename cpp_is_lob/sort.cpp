#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> &one, pair<int,int> &two){

    return one.second < two.second; 
}

int main(){

    vector<pair<int, int>> a = {{1, 2}, {4, 5}, {4, -1}};

    sort(a.begin(), a.end(), compare);

    for(auto &p : a) cout << p.first << ' ' << p.second << endl;
    
    return 0;
}