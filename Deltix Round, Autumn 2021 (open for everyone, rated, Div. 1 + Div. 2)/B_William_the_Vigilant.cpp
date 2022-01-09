// ਹਰਅਸੀਸ ਸਿੰਘ

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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE
int cnt = 0;
string s;
void process(char r, int pos){
        for(int i = max(0ll, pos - 3); i < pos; i++){
                if(s.substr(i, 3) == "abc") cnt--;
        }
        s[pos - 1] = r;

        for(int i = max(0ll, pos - 3); i < pos; i++){
                if(s.substr(i, 3) == "abc") cnt++;
        }
}

int32_t main(){
        
        FIO

        int n, q; cin >> n >> q;

        cin >> s;

        l(i, 0, n){
                if(s.substr(i, 3) == "abc") cnt++;
        }

        l(i, 0, q){
                int pos; cin >> pos; char r; cin >> r;

                process(r, pos);

                // cout << s << endl;

                cout << max(0ll, cnt) << endl;
        }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/