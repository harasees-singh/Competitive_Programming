#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
const int N = 500000;
int Rank[N + 1];
int parent[N + 1];

void MakeSet(){
        for(int i = 0; i <= N; i++)
                parent[i] = i;
}

int findParent(int v){

        if(parent[v] == v)
                return v;
        
        return parent[v] = findParent(parent[v]);
}

void Union(int u, int v){

        u = findParent(u), v = findParent(v);

        if(Rank[u] > Rank[v])
                parent[v] = u;
        else if(Rank[u] < Rank[v])
                parent[u] = v;
        else        
                parent[v] = u, Rank[u]++;
}
int journeyToMoon(int n, vector<vector<int>> astronaut) {
    MakeSet();
    
    for(auto p : astronaut){
        int u, v; 
        
        tie(u, v) = {p[0], p[1]};
        
        Union(u, v);
    }
    long long ret = 0;
    
    map<int, int> f;
    
    for(int i = 0; i < n; i++){
        f[findParent(i)]++;
    }
    
    vector<int> ans;
    
    for(auto p : f)
        ans.push_back(p.second);
        
    for(auto p : ans){
        ret += (n - p)*p;
    }
    
    return ret/2;
}

int main()
{
//     ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);

    cout << result << "\n";

//     fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
