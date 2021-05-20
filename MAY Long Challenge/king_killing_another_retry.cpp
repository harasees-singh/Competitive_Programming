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
vi processed;
int Parent(int child)
{
    return ceil(child/2.00 - 1);
}
void HeapIncreaseKey(vi &H, int i, int key)
{
    // if(key < H.root[i])
    // {
    //     cout << "error: the new key must be greater than the pervious key; key provided = " << key << " and the original key = " << H.root[i] << endl;
    // }
    H[i] = key;
    while (i>0 && H[Parent(i)]<H[i])
    {
        swap(H[i], H[Parent(i)]);
        i = Parent(i);
    }
}
void MinHeapInsert(vi &H, int val)
{
    //H.root = H.IncreaseHeapsize();
    // H.heapsize++;
    // H.root[H.heapsize-1] = -1*INT32_MAX;
    H.pb(-1*INT32_MAX);
    HeapIncreaseKey(H, H.size()-1, val);
}
void heapify(vi &arr, int i, int n)        // lg(n) time complexity
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int minimum = i;
    if(l<n && depth_map[arr[l]] < depth_map[arr[i]])
    {
        minimum = l;
    }
    if(r<n && depth_map[arr[r]] < depth_map[arr[minimum]])
    {
        minimum = r;
    }
    if(minimum!=i)
    {
        swap(arr[i], arr[minimum]);
        return heapify(arr, minimum, n);
    }

}
void BuildAMinHeap(vi &arr)         // O(n) time complexity
{
    int n=arr.size();
    int index = floor(n/2);
    for(int i=index; i>=0; i--)
    {
        heapify(arr, i, n);
    }                   
}


class Graph
{
public:
    map<int, bool> visited;
    map<int, vector<int>> adj;
    void addEdge(int v, int w);
    set<int> DFS(int v, int depth, int parent);
    vi DFS_for_leaves(int node_number, int parent);
    void process(int node_number, int parent, mii &prv);
    
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
        if(alive_clusters[node_number])
        {    vi to_be_returned;
            to_be_returned.pb(node_number);
            return to_be_returned;
        }
        else{
            return {};
        }
    }
    vi will_return(0);
    loop(i, 0, adj[node_number].size()){
        if (alive_clusters[adj[node_number][i]] && adj[node_number][i]!=parent)
        {
            vi no_name_left =  DFS_for_leaves(adj[node_number][i], node_number);
            will_return.insert(will_return.end(), no_name_left.begin(), no_name_left.end());
        }
    }
    return will_return;
}

void Graph:: process(int node, int parent, mii &previous_city){
    if(true){
        // processed[node]=1;
        for(auto child:adj[node]){
            if(child!=previous_city[node] && child!=parent){
                if(!processed[child]){
                    processed[child]=1;
                    alive_clusters[previous_city[node]]=false;
                    // cout << "node marked dead cluster " << previous_city[node] << endl;
                    process(child, node, previous_city);
                }
            }
        }
    }   
}
const int MOD = 1e9 + 7;
int32_t main(){
    FIO
    
    test_cases_loop
    {
        bool corner_case = false;
        int corner_case_count = 0;
        vi corner(0);
        int n;
        cin >> n;
        Graph g;
        depth_map.clear();
        processed.resize(0);
        loop(i, 0, n+1){
            processed.pb(0);
        }
        
        
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
        mii previous_city;
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
            // cout << "the leaf under consideration has adj len " << i << " "<< g.adj[i].size() << endl;
            if(g.adj[g.adj[1][i]].size() > 1)
            {   
                
                child_parent[g.adj[1][i]] = 1;
                depth_map[g.adj[1][i]] = 1;
                g.DFS(g.adj[1][i], 1, 1);
                int final_number_of_days=0;
                set<int> set_of_leaves = parent_leaves[g.adj[1][i]];
                vi for_min_heap;
                for(auto leaf:set_of_leaves){
                        previous_city[leaf]=0;
                        
                        for_min_heap.pb(leaf);
                }
                BuildAMinHeap(for_min_heap);
                
                while(set_of_leaves.size() > 1){
                    mii murder_city;
                    bool murder_parity=false;
                    for(auto node:for_min_heap){
                        previous_city[child_parent[node]]=node;
                        if(set_of_leaves.find(node)!=set_of_leaves.end() && !processed[node]){
                            
                            // if(g.adj[node].size()>=2){if(!processed[g.adj[node][0]] && !processed[g.adj[node][1]]){murder_parity=true;}}    // mistake
                            for(auto child:g.adj[node]){
                                if(child!=previous_city[node] && child!=child_parent[node]){
                                    if(!processed[child]){
                                        murder_parity=true;
                                        break;
                                    }
                                }
                            }
                            if(murder_parity){    
                                g.process(node, child_parent[node], previous_city);
                                // popped[previous_city[node]]=true;
                                alive_clusters[previous_city[node]]=false;
                                murder_city[node]=1;
                            }
                        }
                        
                    }
                    // cout << "infinity " << set_of_leaves.size() <<  endl;
                    set<int> copy_set = set_of_leaves;
                    for(auto leaf:copy_set){
                        int parent=child_parent[leaf];
                        if(!processed[leaf]){
                            if(!murder_city[leaf])
                            {
                                for_min_heap.pb(parent); BuildAMinHeap(for_min_heap); 
                                set_of_leaves.erase(leaf); set_of_leaves.insert(parent);
                                processed[leaf]=1;

                            }
                            else{
                                murder_city[leaf]=0;
                            }

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
            else{
                    corner_case=true;
                    corner_case_count++;
                    corner.pb(g.adj[1][i]);
            }
        }
        // cout << "debug " << endl;



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