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
vector<vi> adj;
vi color;
int n;
pii roots;
int bfs(int i, int p)
{
    int flag = 0;
    int col = color[i];
    vi vis(n, false);
    vis[p] = true;
    queue<int> q;
    vis[i] = 1;
    q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        // vis[x] = true;
        for (auto j : adj[x])
        {
            if (!vis[j])
            {
                if (color[j] != col)
                {
                    return j;
                }
                vis[j] = 1;
                q.push(j);
            }
        }
    }
    return -1;
}
int32_t main()
{
    FIO
            cin >>
        n;
    adj = vector<vi>(n);
    color = vi(n);
    loop(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    loop(i, 0, n)
    {
        cin >> color[i];
    }
    // assuming root node;
    pii p = {-1, -1};
    int root;

    loop(i, 0, n)
    {
        for (auto j : adj[i])
        {
            if (color[i] != color[j])
            {
                p = {i, j};
            }
        }
    }
    if(p.first == -1){
            cout << "YES\n" << 1; return 0;
    }
    
    int flag = 0;
    root = p.first;
    for (auto i : adj[root])
    {
        int check = bfs(i, root);
        if (check != -1)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << "YES\n";
        cout << root + 1 << endl;
    }
    else
    {
        root = p.second;
        int flag = 0;
        for (auto i : adj[root])
        {
            int check = bfs(i, root);
            if (check != -1)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "YES\n";
            cout << root + 1 << endl;
        }
        else
            cout << "NO\n";
    }

    // }

    return 0;
}