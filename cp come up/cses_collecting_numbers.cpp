// ਹਰਅਸੀਸ ਸਿੰਘ

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff first
#define ss second
#define infinity 8999999999999999999
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back((n))
#define mii map<int, int>
#define umii unordered_map<int, int>
#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define l(var, initial, final) for (int var = initial; var < final; var++)
#define cout std::cout
#define cin std::cin
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define fps(x, y) fixed << setprecision(y) << x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a)
{
    in >> a.ff >> a.ss;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a)
{
    out << a.ff << ' ' << a.ss;
    return out;
}
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &v)
{
    out << "{ ";
    for (auto &x : v)
        out << x << " ";
    out << "}\n";
    return out;
}


MOD_DEFINE
int check_prev_element(int prev, int nxt, const vector<int> &in, const vector<int> &pos)
{
    int f = 0;

    if (prev > pos[in[prev - 1] - 1] and nxt < pos[in[prev - 1] - 1])
        f++;

    if (prev < pos[in[prev - 1] - 1] and nxt > pos[in[prev - 1] - 1])
        f--;

    return f;
}
int check_next_element(int prev, int nxt, const vector<int> &in, const vector<int> &pos)
{
    int f = 0;

    if (prev < pos[in[prev - 1] + 1] and nxt > pos[in[prev - 1] + 1])
        f++;
    
    if (prev > pos[in[prev - 1] + 1] and nxt < pos[in[prev - 1] + 1])
        f--;

    return f;
}
void slv()
{
    int n, m;
    cin >> n >> m;

    vector<int> in(n);
    cin >> in;

    int f = 0;

    vector<int> pos(n + 1);

    pos.push_back(0); // sentinel

    for (int i = n - 1; i >= 0; i--)
        f += !pos[in[i] + 1], pos[in[i]] = i + 1;

    pos[n + 1] = infinity;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if(u > v) swap(u, v);

        if (abs(in[u - 1] - in[v - 1]) == 1)
        {
            f += -in[u - 1] + in[v - 1];

            int big = in[u - 1] > in[v - 1] ? u : v;

            int smol = u + v - big;

            // big and smol get interchanged;

            f += check_prev_element(smol, big, in, pos) + check_next_element(big, smol, in, pos);

        }
        else{
            // independent case
            f += check_next_element(u, v, in, pos) + check_prev_element(u, v, in, pos);
            // cout << f << endl;
            f += check_next_element(v, u, in, pos) + check_prev_element(v, u, in, pos);
            // cout << f << endl;
        }
        swap(in[u - 1], in[v - 1]);
        swap(pos[in[u - 1]], pos[in[v - 1]]);

        cout << f << endl;
    }
}

int32_t main()
{

    FIO

    slv();

    return 0;
}
/*
 *think brute force first.
 *try proving the algorithm on pen n paper first.
 *floating point precision errors ?
 *implementation too lengthy ? logic might be incorrect.
 *read the question again.
 */