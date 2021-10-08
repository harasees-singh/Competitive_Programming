#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE
int summ = 0;
struct Pair
{
	int F, S;
	Pair(int x, int y):F(x), S(y){}
	bool operator<(Pair other) const {
		int tmp1 = F-((S/2)*(F/S));
		int tmp2 = other.F-((other.S/2)*(other.F/other.S));
		return tmp1 <= tmp2;
	}
};
set<Pair> F;

int dfs(int sum, vector<vector<pii>> &adj, int curr, int p, int w){

        if(sz(adj[curr]) == 1 and curr != 1){
                summ += sum;
                // F[w] += 1;
                if(w != 0){
                    Pair u(w, w);
                    F.insert(u);
                }
                return 1;
        }
        int cnt = 0;
        l(i, 0, sz(adj[curr])){

            int child = adj[curr][i].ff;
            if(child != p){

                cnt += dfs(sum + adj[curr][i].ss, adj, child, curr, adj[curr][i].ss);
            }
        }

        if(w*cnt != 0){

            Pair p(w*cnt, w);
            F.insert(p);

        }
    return cnt;
}

int32_t main(){
    FIO

    test_cases_loop{

        int n, S; cin >> n >> S;

        // multiset<int> F;

        summ = 0;
        // priority_queue<pii> pq;

        // set<int> F;
        F.clear();

        // unordered_map<int, int, custom_hash> id;

        vector<vector<pii>> adj(n + 1);
        l(i, 0, n - 1){

            int a, b; cin >> a >> b;
            
            int t; cin >> t; 
            // s = max(s, t);
            
            adj[a].push_back({b, t});
            adj[b].push_back({a, t});

        }

        dfs(0, adj, 1, 0, 0);

        int cnt = 0;


        while(summ > S){

                int curr, w;

                Pair p = *(prev(F.end()));

                curr = p.F;
                w = p.S;

                F.erase(prev(F.end()));
                
                summ -= curr;
                int count = curr/w;
                w/=2;
                curr = w*count;
                summ += curr;
                if(curr != 0){
                    Pair u(curr, w);
                    F.insert(u);
                }

                cnt++;
                
        }
        cout << cnt << endl;
        
    }

}
