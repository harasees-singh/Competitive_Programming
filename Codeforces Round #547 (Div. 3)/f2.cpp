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

MOD_DEFINE

vector<pii> ans;
int S = -1;

map<int, vector<pii>> sum_interval;

void mx_number_of_disjoint_intervals(int s){
        int cur = 0;

        int r = -1;

        vector<pii> out;

        for(auto seg : sum_interval[s]){
                if(seg.ff > r){
                        cur++; 

                        r = seg.ss;

                        out.push_back(make_pair(seg.ff + 1, seg.ss + 1));
                }
        }
        if(cur > sz(ans))
                S = s, ans = out;
}
int32_t main(){
        FIO

        int n; cin >> n;

        vi in(n);

        for(auto &p : in) cin >> p;

        for(int j = 0; j < n; j++){
                int cur = 0;
                for(int i = j; i >= 0; i--){
                        cur += in[i];

                        sum_interval[cur].push_back(make_pair(i, j));
                }
        }

        for(auto p : sum_interval){
                mx_number_of_disjoint_intervals(p.ff);
        }
        cout << sz(ans) << endl;

        for(auto p : ans) cout << p.ff << ' ' << p.ss << endl;

        return 0;
}
