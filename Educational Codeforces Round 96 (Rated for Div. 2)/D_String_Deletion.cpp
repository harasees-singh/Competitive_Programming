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
// 110111010001
// need block sizes, nearest block works
// 2 1 3 1 1 3 1
// put block sizes in a set of pairs {size, id}
// or use two pointers
// if currently at a block simply increment i by block size 
// j ptr should point to nearest block(nearest number > 1)
// keep decrementing it till it reduces to 1
int32_t main(){
        
        FIO

        w(t){
                int n; cin >> n;

                string s; cin >> s; s.push_back(s.back() == '0' ? '1' : '0');

                vi hash; 

                int cur = 0; char seg = s[0];

                for(auto p : s){
                        if(p == seg)
                                cur++;
                        else 
                                hash.push_back(cur), cur = 1, seg = p;
                }
                n = sz(hash);
                int op = 0;
                for(int i = 0, j = 0; i < n; i++){
                        while(j < n and hash[j] == 1) j++;

                        op++;

                        if(j == n) {i++; continue;}

                        if(j == i) {j++; continue;}

                        hash[j]--;
                }
                cout << op << endl;
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