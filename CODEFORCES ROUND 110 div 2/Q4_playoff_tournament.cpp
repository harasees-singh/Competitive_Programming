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
#include <functional>
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;

// this q takes 1 sec with unordered map and 1.6 seconds with ordered map

void dfs(vi &tree, const string &s){
    // cout << "tree depth " << tree_depth << endl;

    for(int j=(sz(tree)-1)/2; j>0; j--){
        
        int curr_match = sz(s) - j + 1;
        char decision = s[curr_match-1];
        if(decision == '?')tree[j] = tree[2*j] + tree[2*j + 1];
        else if(decision == '1')tree[j] = tree[2*j];                // this is inverted because the tree is being looked at from behind the wall
        else tree[j] = tree[2*j + 1];                               // reason being the order of matches is not related to the node numbers in an easy to use way.
    }                                                              // to solve this problem the tree can be viewed from behind the wall
                                                                   // and a simple relation node_number = string_size - match_number + 1 can be used
}                                                                   // note that left and right must be interchanged when looking from behind the wall.
int logarithmic_query(vi &tree, int match, const string &s){
    int node = sz(s) - match + 1;
    // cout << "node " << node << endl;
    while(node){
        int match_number = sz(s) - node + 1;
        // int i = match_number, j = node;
        char decision = s[match_number-1];
        if(decision == '?')tree[node] = tree[2*node] + tree[2*node + 1];
        else if(decision == '1')tree[node] = tree[2*node];
        else tree[node] = tree[2*node + 1];
        // cout << "new value installed " << "at " << j << " is "<< tree[j] << endl;
        node = node/2;
    }
    return tree[1];
}
int32_t main(){
    FIO
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    vi tree(round(pow(2, n+1)), 1);
    dfs(tree, s);
    while(q--){
        int match; char change;
        cin >> match >> change;
        
        s[match-1] = change;
        cout << logarithmic_query(tree, match, s) << endl;
        
    }
}

