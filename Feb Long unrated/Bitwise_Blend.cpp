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

MOD_DEFINE
vector<pii> ans;

void fill(int parity, vi &in){
        int n = sz(in);
        int sentinel = -1;
        for(int i = parity; i < n; i += 2){
                if(in[i]%2)
                        {sentinel = i; break;}
        }
        assert(sentinel != -1);
        for(int i = parity; i < n; i += 2){
                if(not (in[i] % 2))
                        ans.push_back(make_pair(i + 1, sentinel + 1));
        }
        for(int i = parity xor 1; i < n; i += 2){
                if(in[i] % 2)
                        ans.push_back(make_pair(i + 1, sentinel + 1));
        }
}

int32_t main(){
        
        FIO

        w(t){
                int n; cin >> n;

                ans.clear();

                vi in(n);
                int even = 0, odd = 0; // number of odds at even indices and odd indices resp
                for(int i = 0; i < n; i++){
                        cin >> in[i];

                        even += (i%2==0) * (in[i]%2);

                        odd += (i%2) * (in[i]%2);
                }
                if(n==1){
                        cout << 0 << endl; continue;
                }
                if(even==0 and odd==0){
                        cout << -1 << endl; continue;
                }
                int odd_indices = n/2;

                int even_indices = n - n/2;

                int cost_even = even_indices - even + odd;
                int cost_odd = odd_indices - odd + even;

                if(cost_even < cost_odd){
                        fill(0, in);
                }
                else 
                        fill(1, in);
                
                cout << sz(ans) << endl; 
                for(auto &p : ans)
                        cout << p.ff << ' ' << p.ss << endl;
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