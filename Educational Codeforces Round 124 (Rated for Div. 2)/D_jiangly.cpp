// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

// dfs won't work for obvious reasons

// need a multisource bfs

map<pii, int> id;

map<pii, pii> ans;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

int32_t main(){
        FIO         

        int n; cin >> n;

        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y;

            id[{x, y}] = i;
        }   
        map<pii, int> idcpy(id);

        queue<pii> Q;

        for(auto p : id){
            pii t = p.ff;

            for(int i = 0;i  < 4; i++){
                pii coordinate = {t.ff + dx[i], t.ss + dy[i]};

                if(not id.count(coordinate) and ans.count(coordinate) == 0) ans[coordinate] = coordinate, Q.push(coordinate);
            }
        }

        while(Q.empty() == false){
            pii top = Q.front();
            Q.pop();

            for(int i = 0; i < 4; i++){
                pii t = {top.ff + dx[i], top.ss + dy[i]};

                if(not id.count(t)) continue;

                ans[t] = ans[top];

                id.erase(t);

                Q.push(t);
            }
        }

        vector<pii> out(n);
        for(auto p : idcpy){
            auto t = p.ff;

            int idx = p.ss;

            out[idx] = ans[t];
        }
        for(auto p : out) cout << p << ' ' << endl;

        return 0;
}
