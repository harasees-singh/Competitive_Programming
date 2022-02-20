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
// #define int                             long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back((n))
#define mii map<int, int>
#define umii unordered_map<int, int>
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
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

MOD_DEFINE
vi greatest_divisor(2750136);

template <typename T>
vector<T> sieve(T n)
{
    vector<int> prime(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = 2; j * i <= n; j++)
            {
                if (prime[i * j])
                {
                    greatest_divisor[i * j] = j;
                }
                prime[i * j] = 0;
            }
        }
    }
    vector<T> ans;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            ans.pb(i);
    }
    return ans;
}
vi Primes(2750135);
int32_t main()
{

    FIO

        int n;
    cin >> n;
    ofstream out;
    out.open("out.txt");

    vi primes = sieve(2750135);

    // unordered_set<int> Primes;
    int pt = 1;
    for (auto p : primes)
        Primes[p] = pt++;

    out << "size of greatest_divisor vector = " << sz(greatest_divisor) << endl;
    out << "greatest_divisor[2750131] = " << greatest_divisor[2750135] << endl;

    // for(auto p : Primes) out << p << ' '; out << endl;
    // for(auto p : greatest_divisor) out << p << ' '; out << endl;

    out.close();

    multiset<int> order;

    l(i, 0, 2 * n)
    {
        int t;
        cin >> t;

        order.insert(t);
    }
    while (sz(order))
    {
        auto it = prev(order.end());
        // O(1) for if condition,,, should work now
        if (*it < 0 or *it >= sz(Primes))
        {
            exit(0);
        }
        if (Primes[*it])
        {
            int num = Primes[*it];
            order.erase(it);
            cout << num << ' ';
            order.erase(order.find(num));
        }
        else
        {
            // this is a composite number and must be a member of a array
            cout << *it << ' ';

            int div = greatest_divisor[*it];
            order.erase(it);

            // need to factorize in less than sqrt(n) time. else tle,, tc = n lgn lgn sqrt(n)
            // or maibi try hashing instead of an ordered set
            order.erase(order.find(div));
        }
    }

    return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/