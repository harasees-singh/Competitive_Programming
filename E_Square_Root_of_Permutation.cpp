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
vi in;
bool ok(vi & in, vi & squareroot){
    for(int i=1; i <= sz(in); i++){
        if(in[i] != squareroot[squareroot[i]]) return false;        
    }
    return true;
}
void shift(vector<vi> &cycles){
    vector<vi> ans;
    for(auto &p : cycles){
        if(sz(p)==1){
            ans.pb(p); continue;
        };

        if(sz(p)%2){
            vi q; 

            for(int i=0; i < sz(p); i++){
                q.pb(p[(i*2) % sz(p)]);
            }
            ans.pb(q);
        }
        else{
            vi q, Q;
            for(int i=0; i < sz(p); i+=2)
                q.pb(p[i]);
            for(int i=1; i < sz(p); i+=2)
                Q.pb(p[i]);
            ans.pb(q); 
            ans.pb(Q);
        }
    }
    cycles=ans;
}
int32_t main(){
        
        FIO

        int n; cin >> n;

        in = vi(n + 1);
        for(int i=1; i <= n; i++) 
            cin >> in[i];

        vector<vi> cycles;

        vi vis(n + 1);

        for(int i = 1; i <= n; i++){
            if(vis[i])
                continue;
            vi cycle;
            int j=i;
            while(not vis[j]){
                vis[j]=1;
                cycle.pb(j); j = in[j]; 
            }
            cycles.pb(cycle);
        }   
        shift(cycles);
        for(auto p : cycles){
            for(auto q : p)
                cout << q << ' ';
                cout << endl;
        }
        // cout << "OK" << endl; cout.flush();
        vi ans(n + 1);
        int tot=0;
        for(auto &p : cycles){
            tot += sz(p);
            for(int i=0; i <sz(p); i++){
                ans[p[i]] = p[(i+1) % sz(p)];
            }
        }
        // for(auto p : ans) cout << p << ' ';
        assert(tot==n);
        if(ok(in, ans)){
            for(int i=1; i<=n; i++)cout << ans[i] << ' ';
        }
        else cout << -1;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/