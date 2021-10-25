#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define infinity 999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define space " "
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop \
    int t;              \
    cin >> t;           \
    while (t--)
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define cout std::cout
#define cin std::cin
#define loop(var, initial, final) for (int var = initial; var < final; var++)
typedef tree<pii, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// bool isCyclic_util(vector<int> adj[], vector<bool> visited, int curr)
// {
//     if (visited[curr] == true)
//         return true;

//     visited[curr] = true;
//     bool FLAG = false;
//     for (int i = 0; i < adj[curr].size(); ++i)
//     {
//         FLAG = isCyclic_util(adj, visited, adj[curr][i]);
//         if (FLAG == true)
//             return true;
//     }
//     return false;
// }
vi visited;
bool isCyclic(int i, vector<int> adj[], int p)
{
    if(visited[i] == 1)
            return true;
    
    if(visited[i] == 2)
            return false;
    
    visited[i] = 1;

    bool ok = 0;

    for(auto q : adj[i])
            
                    ok = ok or isCyclic(q, adj, i);
    
    visited[i] = 2;

    return ok;
            
}
// topological sort
void dfs(vector<int> adj[], vector<bool> &vis, int v, stack<int> &s)
{
    vis[v] = true;

    for (int i = 0; i < sz(adj[v]); i++)
    {
        if (vis[adj[v][i]] == false)
        {
            dfs(adj, vis, adj[v][i], s);
        }
    }
    s.push(v);
}
int32_t main()
{
    FIO int n;
    cin >> n;

    int v = 27;
    vector<int> adj[26];
    vector<string> s(n);
    vector<bool> vis(26, false);
    stack<int> ansrev;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int ptr1 = 0, ptr2 = 0;
    if (n == 1)
    {
        loop(i, 0, 26)
        {
            cout << char('a' + i);
        }
        return 0;
    }
    // while (ptr1 < sz(s[0]) && ptr2 < sz(s[1]))
    // {
    //     if (s[0][ptr1] != s[1][ptr2])
    //     {
    //         adj[s[0][ptr1] - 'a'].push_back(s[1][ptr2] - 'a');
    //         break;
    //     }
    //     ptr1++;
    //     ptr2++;
    // }
    // if (ptr1 == sz(s[0]) || ptr2 == sz(s[1]))
    // {
    //     if (sz(s[0]) > sz(s[1]))
    //     {
    //         cout << "Impossible";
    //         return 0;
    //     }
    // }
    // // if ()

    loop(i, 1, n)
    {
        ptr1 = 0, ptr2 = 0;
        while (ptr1 < sz(s[i - 1]) && ptr2 < sz(s[i]))
        {
            if (s[i - 1][ptr1] != s[i][ptr2])
            {
                adj[s[i - 1][ptr1] - 'a'].push_back(s[i][ptr2] - 'a');
                break;
            }
            ptr1++;
            ptr2++;
        }
        if (ptr1 == sz(s[i - 1]) || ptr2 == sz(s[i]))
        {
            if (sz(s[i - 1]) > sz(s[i]))
            {
                cout << "Impossible";
                return 0;
            }
        }
    }
    // cout << "here";

    visited = vi(27);
    bool ok = 0;
    loop(i, 0, 26){
            if(ok) break;
            if(!visited[i])
                    ok = ok or isCyclic(i, adj, -1);
    }
    if(ok){
            cout << "Impossible" << endl;
            exit(0);
    }
    loop(i, 0, 26)
    {
        if (vis[i] == false)
        {
            dfs(adj, vis, i, ansrev);
        }
    }
    vi alphabets(26, 0);
    while (!ansrev.empty())
    {
        int x = ansrev.top();
        ansrev.pop();
        alphabets[x] = true;
        cout << char(x + 'a');
    }
    // loop(i, 0, 26)
    // {
    //     if (alphabets[i] == 0LL)
    //     {
    //         cout << char(i + 'a');
    //     }
    // }
    // cout << endl;

    return 0;
}