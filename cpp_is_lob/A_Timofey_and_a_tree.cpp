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
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

vpii g;
int color[(int)1e5 + 1];
int n;

bool checkValidRoot(int root){

        for(auto p : g){

                if(p.ff == root or p.ss == root)
                        continue;

                if(color[p.ff] != color[p.ss])
                        return false;
        }

        return true;
}

int32_t main(){
    FIO

        cin >> n;

        g = vpii();

        l(i, 0, n - 1){
                int u, v; cin >> u >> v; 

                g.push_back(make_pair(u, v));
        }

        l(i, 1, n + 1)
                cin >> color[i];
        bool ok = 0;
        
        for(auto p : g){
                if(color[p.ff] != color[p.ss]){
                        if(checkValidRoot(p.ff)){
                                cout << "YES" << endl << p.ff << endl;
                        }
                        else if(checkValidRoot(p.ss)){
                                cout << "YES" << endl << p.ss << endl;
                        }
                        else{        
                                cout << "NO" << endl; 
                        }
                        ok = 1;

                        break;
                }
        }

        if(!ok)
                        cout << "YES" << endl << 1 << endl;
        
        return 0;
}
