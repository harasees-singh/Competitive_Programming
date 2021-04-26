#include<iostream>
#include"bits.cpp"
using namespace std;
vector<int>collections(0);
vector<vector<int>>visited(0);
pair<int, int> find_coordinate(vector<string> &matrix, pair<int, int> dynamic_coordinate)
{
    for(int i=dynamic_coordinate.first; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[0].size(); j++)
        {
            if(matrix[i][j]=='1') return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}
void spit_collections(vector<string> &matrix, int dynamic_count, pair<int, int> dynamic_coordinate)
{
    int x=dynamic_coordinate.first; int y=dynamic_coordinate.second;
    visited[x][y]=1;                    // marking that pos as visited
    if(x+1<matrix.size() && (matrix[x+1][y]=='0' || visited[x+1][y]) && y+1 <matrix[0].size() && (matrix[x][y+1]=='0' || visited[x+1][y]))
    {
        if(dynamic_count!=0)         
        {
            collections.push_back(dynamic_count);
            pair<int, int> temp=find_coordinate(matrix, dynamic_coordinate);
            if(temp.first!=-1) spit_collections(matrix, 1, temp);
        }
        
        return;
    }
    if(matrix[x+1][y]=='1' && !visited[x+1][y]) spit_collections(matrix, dynamic_count+1, make_pair(x+1, y));           // going down
    if(matrix[x][y+1]=='1' && !visited[x][y+1]) spit_collections(matrix, dynamic_count+1, make_pair(x, y+1));           // going right
    if(matrix[x][y-1]=='1' && !visited[x][y-1]) spit_collections(matrix, dynamic_count+1, make_pair(x, y-1));           // going left
    return;
}
int main()
{
    int t;
    int n, m;
    cin >> t;
    while(t--)
    {
        visited.resize(0);
        cin >> n >> m;
        vector<string>matrix(0);
        for(int i=0; i<n; i++)
        {
            string temp;
            cin >> temp;
            matrix.push_back(temp);
            vector<int> sed_lyf(m, 0);
            visited.push_back(sed_lyf);
        }
        pair<int, int> initial = find_coordinate(matrix, make_pair(0, 0));
        // initializing visited
        spit_collections(matrix, 1, initial);
    }
}