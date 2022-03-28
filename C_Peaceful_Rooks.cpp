// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE
vi vis;
vector<pii> in;
vi row;         // stores id corresponding to each row number
                // 0 means no element in that row
vi isCycle;
bool dfs(int id){
    if(vis[id]){
        if(isCycle[id] == -1) return true;

        else return false;
    }

    // this id will have a row and a column
    vis[id] = 1;
    int col = in[id].ss;

    if(not row[col]) return isCycle[id] = false;

    return isCycle[id] = dfs(row[col]);   // go to this id
}
int32_t main(){
        
        FIO

        w(t){
            int n, m; cin >> n >> m;

            row = vi(n + 1);

            isCycle = vi(m + 1, -1); // is this id a cycle ?  

            in = vector<pii> (m + 1);

            int already_placed = 0;

            for(int i = 1; i <= m; i++) cin >> in[i], row[in[i].ff] = i, already_placed += (in[i].ff == in[i].ss);

            // index corres to id;

            int cycle = 0;
            // ans is number m - (already at diagonal) + cycles

            vis = vi(m + 1);

            for(int i = 1; i <= m; i++) if(not vis[i] and in[i].ff != in[i].ss) cycle += dfs(i);

            cout << m + cycle - already_placed << endl;
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