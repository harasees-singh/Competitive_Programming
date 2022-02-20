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
string T = "abc";
string rep1;    // acb types

string buff(string t, int n){
        string temp; for(auto p : t) l(i, 0, n) temp += p;
        return temp;
}

void check(string u, string v, bool concat){
        do{
                string t = T;
                if(concat) t += T;
                bool ok = 1;
                l(i, 0, sz(t) - 1){
                        if(t.substr(i, 2) == u or t.substr(i, 2) == v){
                                ok = 0; break;
                        }
                } 
                if(ok) rep1 = T;
        }
        while(next_permutation(all(T)));

}
int n;

int32_t main(){
        
        FIO

        cin >> n;

        string u, v; cin >> u >> v;

        if(u[0] != u[1] and v[0] != v[1]){
                // ab, ac case : true only for n = 1 and n = 2

                check(u, v, 0);

                cout << "YES" << endl;

                cout << buff(rep1, n) << endl;
        }
        else{
                check(u, v, 1);

                cout << "YES" << endl;

                l(i, 0, n) cout << rep1; cout << endl;
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