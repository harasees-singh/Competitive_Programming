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

using namespace std;

// global variables
map<int, set<int>> parent_leaves;
map<int, int> child_parent;
map<int, int> depth_map;
vector<bool> alive_clusters(0);


class Graph
{
public:
    map<int, bool> visited;
    map<int, vector<int>> adj;
    void addEdge(int v, int w);
    set<int> DFS(int v, int depth, int parent);
    vi DFS_for_leaves(int node_number, int parent);
    
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

set<int> Graph::DFS(int v, int depth, int parent)
{
    if(adj[v].size()==1 && v!=1){
        set<int> to_be_returned;
        to_be_returned.insert(v);
        depth_map[v] = depth;
        child_parent[v] = parent;
        return to_be_returned;
    }
    int curr_depth = depth;
    child_parent[v] = parent;
    // parent stored at the child v;
    // remember to store child_parent[2]=1; and so on
    depth_map[v]=curr_depth;
    
    set<int> leaves_of_this_parent;

    for (int i=0; i<adj[v].size(); i++)
    {
        if (!visited[adj[v][i]] && adj[v][i]!=parent){
            set<int> returned_set = DFS(adj[v][i], curr_depth+1, v);
            for(int leaf:returned_set){
                leaves_of_this_parent.insert(leaf);
            }
        }
    }
    
    visited[v] = true;
    parent_leaves[v] = leaves_of_this_parent;
    return leaves_of_this_parent;
}

vi Graph::DFS_for_leaves(int node_number, int parent){
    if(adj[node_number].size()==1){
        vi to_be_returned;
        to_be_returned.pb(node_number);
        return to_be_returned;
    }
    vi will_return;
    loop(i, 0, adj[node_number].size()){
        if (alive_clusters[adj[node_number][i]] && adj[node_number][i]!=parent)
        {
            vi no_name_left =  DFS_for_leaves(adj[node_number][i], node_number);
            will_return.insert(will_return.end(), no_name_left.begin(), no_name_left.end());
        }
    }
    return will_return;
}

const int MOD = 1e9 + 7;
int32_t main(){
    FIO
    
    
    test_cases_loop
    {
        bool corner_case = false;
        int corner_case_count = 0;
        vi corner(0);
        Graph g;
        depth_map.clear();
        int n;
        cin >> n;
        loop(i, 0, n-1)
        {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v); g.addEdge(v, u);
        }
        // dual adjacency list is ready
        alive_clusters.resize(0);
        loop(j, 0, n+1){
            alive_clusters.pb(true);
        }
        mii popped;
        mii connection_map;
        vi check_for_stay_parity(n+1, false);

        for(int node=1; node<=n; node++){
            connection_map[node]=g.adj[node].size();
        }
        // boolean list is ready will make the child parent map, depth map and parent_leaf map during the dfs.
        int answer_number_of_days=INT32_MAX;
        vi answer_assassins(0);
        // cout << "debug " << endl;
        for(int i=0; i<g.adj[1].size(); i++){
            
            child_parent[g.adj[1][i]] = 1;
            depth_map[g.adj[1][i]] = 1;
            g.DFS(g.adj[1][i], 1, 1);
            int final_number_of_days=0;
            set<int> set_of_leaves = parent_leaves[g.adj[1][i]];
            // cout << "debug 2" << endl;
            // mii position_assassin;
            // for(int leaf:set_of_leaves){
            //     position_assassin[leaf]=leaf;
            // }

            while(set_of_leaves.size() > 1 && set_of_leaves.find(g.adj[1][i])==set_of_leaves.end()){
                // cout << "set of leaves size = " << set_of_leaves.size() << endl;
                for(int leaf:set_of_leaves){
                    connection_map[child_parent[leaf]]--;
                }
                // cout << "connection of 11 " << connection_map[4] << endl;
                // vi dead_assassins(0);
                // cout << "debug 3" << endl;
                // cout << "set size " << set_of_leaves.size() << endl;
                for(int leaf:set_of_leaves){
                    // cout << leaf << " ";
                    if(check_for_stay_parity[leaf]){
                        // cout << "leaf " << leaf << endl;
                        check_for_stay_parity[leaf]=false;
                        // popped[child_parent[leaf]] = true;
                        // cout << "leaf number " << leaf << " ";
                        // cout << "check for stay parity " << check_for_stay_parity[leaf] << endl;
                        continue;
                    }
                    if(connection_map[child_parent[leaf]] >= 2){
                        if(!popped[child_parent[leaf]]){
                            alive_clusters[leaf]=false;
                            // cout << "2 leaf number " << leaf << " ";
                            // cout << "2 check for stay parity " << check_for_stay_parity[leaf] << endl;
                            check_for_stay_parity[leaf]=true;
                        }
                        if(!check_for_stay_parity[leaf])
                            popped[child_parent[leaf]]=true;
                        // dead_assassins.pb(child_parent[leaf]);
                    }
                }
                
                // cout << endl;
                set<int> copy_set = set_of_leaves;
                for(int leaf:copy_set){
                    if(!popped[child_parent[leaf]] && !check_for_stay_parity[leaf]){
                        set_of_leaves.erase(leaf); set_of_leaves.insert(child_parent[leaf]);
                    }
                    // // if(popped[child_parent[leaf]] && !check_for_stay_parity[leaf]){
                    // //     set_of_leaves.erase(leaf); set_of_leaves.insert(child_parent[leaf]);
                    // }
                    else if(check_for_stay_parity[leaf]){
                        // check_for_stay_parity[child_parent[leaf]]=false;
                        // cout << "leaf " << leaf << endl;
                        // set_of_leaves.insert(child_parent[leaf]);
                        continue;
                    }
                    else{
                        set_of_leaves.erase(leaf);
                    }
                }
                
                
                
                final_number_of_days++;
            }
            // cout << "final days before preprocessing " << final_number_of_days << endl;
            // cout << "set of leaves size " << set_of_leaves.size() << endl;
            int last_remaining_assassin = *set_of_leaves.begin();
            final_number_of_days += (depth_map[last_remaining_assassin]);
            // cout << "last remaining assassin " << last_remaining_assassin << endl;
            // cout << "final " << final_number_of_days << endl;
            // cout << "depth map for 5 " << depth_map[4] << endl;
            if(final_number_of_days == answer_number_of_days){
                answer_assassins.pb(g.adj[1][i]); answer_number_of_days = final_number_of_days;
            }
            if(final_number_of_days< answer_number_of_days){
                answer_assassins = {g.adj[1][i]}; answer_number_of_days = final_number_of_days;
            }

        }
        // cout << "debug " << endl;
        vi answer_set;
        loop(i, 0, answer_assassins.size()){
            vi leaves = g.DFS_for_leaves(answer_assassins[i], child_parent[answer_assassins[i]]);

            // cout << "printing leaves "  << endl;
            // for(auto j: leaves)cout << j << " ";

            answer_set.insert(answer_set.end(), leaves.begin(), leaves.end());
        }

        // for(auto mapshit:depth_map){
        //     cout << mapshit.first  << " " << mapshit.second << endl;
        // }



        sort(answer_set.begin(), answer_set.end());
        // if(g.adj[1].size()>1)answer_number_of_days++;
        std::cout << answer_set.size()<< " " << answer_number_of_days << '\n';
        for(auto assassin:answer_set){
            std::cout << assassin << " ";
        }
        std::cout << '\n';
    
    
        
    }
    return 0;

}