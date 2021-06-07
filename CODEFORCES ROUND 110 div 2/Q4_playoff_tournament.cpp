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
unordered_map<int, int> node_match;
// this q takes 1 sec with unordered map and 1.6 seconds with ordered map
int assassinate(int match_number, int size){
    int segment = floor(log2(size - match_number + 1)) + 1;
    return round(pow(2, segment-1)) + (match_number - (size - (round(pow(2, segment)) - 2)));
}
void dfs(vi &tree, const string &s){
    int tree_depth = floor(log2(sz(tree)-1));
    int curr_match=1;
    // cout << "tree depth " << tree_depth << endl;
    for(int i=tree_depth-1; i>=0; i--){
        for(int j=round(pow(2, i)); j<round(pow(2, i+1)); j++){
            // cout << "node number " << j << endl;
            // j is the node number and curr_match is the match number;
            // cout << "curr match " << curr_match << endl;
            char decision = s[curr_match-1];
            if(decision == '?')tree[j] = tree[2*j] + tree[2*j + 1];
            else if(decision == '0')tree[j] = tree[2*j];
            else tree[j] = tree[2*j + 1];
            node_match[j] = curr_match;
            curr_match++;
        }
    }
}
int logarithmic_query(vi &tree, int match, const string &s){
    int node = assassinate(match, (sz(tree)-1)/2);
    while(node){
        int match_number = node_match[node];
        int i = match_number, j = node;
        char decision = s[i-1];
        if(decision == '?')tree[j] = tree[2*j] + tree[2*j + 1];
        else if(decision == '0')tree[j] = tree[2*j];
        else tree[j] = tree[2*j + 1];
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

