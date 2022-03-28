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
map<pii, vector<pii>> g;
map<int, vi> row, col;
int h, w;
void add_edges(int i, int j){
        int id;
        // vert
        
        id = (lower_bound(all(col[j]), i) - col[j].begin()) - 1;

        if(id >= 0 and col[j][id] < i - 1) g[make_pair(i, j)].pb(make_pair(col[j][id] + 1, j));

        id = (lower_bound(all(col[j]), i + 2) - col[j].begin());

        if(id < col[j].size()) g[make_pair(i, j)].pb(make_pair(col[j][id] - 1, j));

        // hori

        id = (lower_bound(all(row[i]), j) - row[i].begin()) - 1;

        if(id >= 0 and row[i][id] < j - 1) g[make_pair(i, j)].pb(make_pair(i, row[i][id] + 1));

        id = (lower_bound(all(row[i]), j + 2) - row[i].begin());

        if(id < row[i].size()) g[make_pair(i, j)].pb(make_pair(i, row[i][id] - 1));
}

void put(pii a){
        add_edges(a.ff, a.ss);
}

int32_t main(){
        
        FIO

        int n; cin >> h >> w >> n;

        pii S, G; cin >> S >> G;
        S.ff--; S.ss--; G.ff--; G.ss--;

        vector<pii> in(n);

        for(int i = 0; i < n; i++){
                int r, c; cin >> r >> c;

                r--, c--;

                row[r].pb(c);
                
                col[c].pb(r);        

                in[i] = {r, c};
        }
        for(auto p : in){
                if(p.ff > 0) put({p.ff - 1, p.ss});

                if(p.ff < h - 1) put({p.ff + 1, p.ss});

                if(p.ss > 0) put({p.ff, p.ss - 1});

                if(p.ss < w - 1) put({p.ff, p.ss + 1});
        }
        put(S);

        // cout << endl;
        // for(auto p : g){
        //         cout << "adjacent to " << p.ff <<  endl;

        //         for(auto q : p.ss) cout << q << ' '; cout << endl;

        // }
        queue<pii> Q; 
        map<pii, int> d;
        Q.push(S);
        map<pii, bool> vis;
        vis[S] = 1;
        d[S] = 0;
        while(Q.empty() == false){
                pii top = Q.front(); Q.pop();

                for(auto p : g[top]){
                        if(vis[p])continue;
                        vis[p] = 1; d[p] = d[top] + 1;

                        if(p == G) break;

                        Q.push(p);
                }
        }               
        if(d.find(G) == d.end()){
                cout << -1;
        }
        else cout << d[G] << endl;
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/