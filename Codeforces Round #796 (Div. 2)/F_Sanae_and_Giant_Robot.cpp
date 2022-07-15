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
#define w(T)                            int T; cin >> T; while(T--)
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
void subtract(set<int> &notVIS, set<int> &deleteme){
        for(auto p : deleteme){
                assert(notVIS.count(p));

                notVIS.erase(p);
        }
}
void solve(){
        int n, q; cin >> n >> q; 

        vi A(n), B(n);

        for(auto &p : A) cin >> p;
        for(auto &p : B) cin >> p;

        int id=-1;
        int a = 0, b = 0;
        set<pii> seg;
        for(int i=0; i < n; i++){
                if(a == b){
                        id = i + 1;
                }
                a += A[i]; b += B[i];

                if(a == b){
                        seg.insert({id, i + 1});
                }    
        }
        vector<vector<int>> QR(n + 1), QL(n + 1); 

        for(int i=0; i < q; i++){
                int u, v; cin >> u >> v; 

                QR[u].pb(v);
                QL[v].pb(u);
        }
        if(a != b){
                cout << "NO" << endl; return;
        }
        // set<int> notVIS; 
        vi vis(n + 2);
        // for(auto p :seg) cout << p << ' '; 
        vector<bool> start(n + 1), end(n + 1);
        for(auto p : seg){
                start[p.ff] = 1; end[p.ss] = 1;
        }
        for(int i=1; i <= n; i++){
                for(auto j : QR[i]){
                        if(start[i] and end[j]){
                                vis[i]++, vis[j + 1]--; 
                        }
                }
        }
        for(int i=1; i <= n; i++) vis[i] += vis[i - 1];

        set<int> notVIS; 

        for(int i=1; i <= n; i++){
                notVIS.insert(i);
                if(vis[i]) notVIS.erase(i);
        }        
        queue<int> Q;

        for(int i=1; i <= n; i++){
                if(vis[i])
                        Q.push(i);
        }
        while(Q.empty() == false){
                int top = Q.front();

                Q.pop();

                for(auto p : QR[top]){
                        if(notVIS.count(p) == 0 or end[p]){
                                // it's already visited or it's an ending point
                                // we can extend the segment and cover all the unvisited points
                                // lying in this segment
                                set<int> deleteme;

                                auto it = notVIS.upper_bound(top);
                                while(it != notVIS.end() and *it <= p){
                                        int val = *it;
                                        deleteme.insert(val);
                                        Q.push(val);
                                        ++it;
                                }
                                subtract(notVIS, deleteme);
                        }
                }
                for(auto p : QL[top]){
                        if(notVIS.count(p) == 0 or start[p]){
                                set<int> deleteme;

                                auto it = notVIS.lower_bound(p);
                                while(it != notVIS.end() and *it <= top){
                                        int val = *it;
                                        deleteme.insert(val);
                                        Q.push(val);
                                        ++it;
                                }
                                subtract(notVIS, deleteme);
                        }
                }
        }
        for(auto p : notVIS){
                if(A[p - 1] != B[p - 1]){
                        cout << "NO" << endl; return;
                }
        }
        cout << "YES" << endl;
}
int32_t main(){
        
        FIO

        // make a set of pairs maybe representing segments that are swappable independently 

        // when swapping a segment need to check if both of it's ends are 'safe' or not

        // 'safe' for right end : either and ending of a segment or lying in a 'swapped' segment

        // 'safe' for left end : either a starting of a segment or lying in a 'swapped' segment

        w(T){
                solve();
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