#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define And &&
#define Or ||
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
void fastscan_integer(int &number)      // for fastest possible integer input
{   
    bool negative = false; register int c; number = 0; c = getchar();
    if (c=='-') negative = true, c = getchar();
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;      
}
using namespace std;

int min_depth=0;
class Graph
{
public:
    map<int, bool> visited;
    map<int, vector<int>> adj;
    void addEdge(int v, int w);
    vi DFS(int v,int sum, int parent);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

vi Graph::DFS(int v, int sum, int parent)
{
    if(adj[v].size()==1 && v!=1){
        vi to_be_returned(0);
        to_be_returned.pb(sum); to_be_returned.pb(v);
        
        return to_be_returned;
    }
    int curr_sum = 1+sum;
    
    int max_depth = 0;
    vi final_list(0);
    for (int i=0; i<adj[v].size(); i++)
        {
            if (!visited[adj[v][i]] && adj[v][i]!=parent){
                vi return_list(DFS(adj[v][i], curr_sum, v));
                int depth = return_list[0];
            
                if(depth<min_depth){
                    min_depth=depth;
                }
                if(max_depth==depth){
                    final_list.insert(final_list.end(), ++return_list.begin(), return_list.end());
                }
                else if(depth>max_depth){
                    final_list = return_list;
                    max_depth = depth;
                }
            }
        }
    
    visited[v] = true;
    return final_list;
}

int32_t main()
{
    FIO
    
    const int MOD = 1e9 + 7;
    test_cases_loop
    {
        Graph g;
        min_depth=1e9;
        int n;
        cin >> n;
        loop(i, 0, n-1)
        {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v); g.addEdge(v, u);
        }
        int minima = 1e9;
        vi final_answer(0);
        bool corner_case = false;
        int corner_case_count = 0;
        vi corner(0);
        loop(i, 0, g.adj[1].size()){
            
            min_depth=1e9;
            if(g.adj[g.adj[1][i]].size()>1)
            {
                vi potential_answer = g.DFS(g.adj[1][i], 1, 1);
                // cout << "the new answer = " << min_depth << '\n';
                if(min_depth!=potential_answer[0]){
                    // cout << "the new number of days can be " << min_depth << '\n';
                    potential_answer[0]=min_depth+1;
                    // cout << "number of days " << potential_answer[0] << '\n';
                }
                
        
                if(potential_answer[0]<minima){
                    final_answer=potential_answer; minima = potential_answer[0];
                }
                else if(potential_answer[0]==minima){
                    final_answer.insert(final_answer.end(), ++potential_answer.begin(), potential_answer.end());
                }
            }
            else{
                corner_case=true;
                corner_case_count++;
                corner.pb(g.adj[1][i]);
            }
            
        }
        
        if(corner_case){
            std::cout << corner_case_count << " " << '1' << '\n';
            sort(corner.begin(), corner.end());
            loop(i, 0, corner.size())
            {
                std::cout << corner[i] << " " ;
            }
            std::cout << '\n';
            continue;
        }
        std::cout << final_answer.size()-1 << " " << final_answer[0] << '\n';
        sort(final_answer.begin(), final_answer.end());
        loop(i, 1, final_answer.size())
        {
            std::cout << final_answer[i] << " " ;
        }
        std::cout << '\n';
    }
    
    return 0;
}