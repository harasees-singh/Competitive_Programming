#include <iostream>
#include <vector>
#include <cmath>
#include "bits.cpp"
#define loop(j, n) for(int i = j; i < n; i++)
using namespace std;
// i -> row number
// j -> column number
// n -> number of rows
// m -> number of columns
// li -> input list
// visited -> visiting check
// result -> groups of 1

vector <vector<int> > visited;
vector <string> li(0);
vector <int> result;
void land_sizes(int i, int j, int n, int m, int cnt = 0){
    if (li[i][j] == '1' && visited[i][j] == 0){cnt++;}
    else return;
    if ((li[i+1][j] == '0' || visited[i+1][j] == 1) && (li[i][j-1] == '0' || visited[i][j-1] == 1) && (li[i][j+1] == '0' || visited[i][j+1] == 1)){
        if (cnt != 0) {result.push_back(cnt); return;}
        else return;
    }
    if (j == m){
        land_sizes(i+1, j, n, m);
        land_sizes(i, j-1, n, m);
        return;
    }
    if (i == n){
        land_sizes(i, j-1, n, m);
        land_sizes(i, j+1, n, m);
        return;
    }
    land_sizes(i+1, j, n, m);
    land_sizes(i, j-1, n, m);
    land_sizes(i, j+1, n, m);
    return;
}
int main(){
    int t;
    cin>>t;
    loop(0,t){
        int n, m;
        cin>>n>>m;
        li.resize(0);
        visited.resize(0);
        loop(0,n){
            string s;
            cin>>s;
            li.push_back(s);
        }
        vector <int> collections(m, 0);
        
        loop(0,n){
            visited.push_back(collections);
        }
        
        loop(0,n){
            for (int j = 0; j < m; j++){
                if (visited[i][j] == 0 && li[i][j] == '1'){
                    land_sizes(i, j, n, m);
                } 
            }
        }
        sort(result.begin(), result.end(), greater<int>());
        int sum = 0;
        for(int i = 1; i < result.size(); i+=2){
            sum += result[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
