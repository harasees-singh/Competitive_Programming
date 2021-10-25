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
// #define int                             long long
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

vi vis;

vector<vi> TSort;

int diff(string &a, string &b){

        int pt(0);

        while(pt < a.size() and pt < b.size() and a[pt] == b[pt])
                pt++;
        
        if(pt < a.size() and pt < b.size())
                return pt;
        
        return -1;
        
}

vi order;

void TopologicalSort(int i, int f){

        for(auto p : TSort[i])
                if(!vis[p])
                        vis[p] = 1, TopologicalSort(p, f);
        
        if(f)
            order.push_back(i);
}

int32_t main(){
    FIO

    int n; cin >> n;

    string prev = "";

    TSort = vector<vi>(26);
    
    bool ok = 1;

    l(i, 0, n){

            string t; cin >> t;

            int difff = diff(prev, t);

            vis = vi(26);

            if(difff != -1){    

                    vis[t[difff] - 'a'] = 1;    

                    TopologicalSort(t[difff] - 'a', 0);

                    if(vis[prev[difff] - 'a'])
                            ok = 0;
                    
                    else if(count(all(TSort[prev[difff] - 'a']), t[difff] - 'a') == 0)
                            TSort[prev[difff] - 'a'].push_back(t[difff] - 'a');
            }

            else{
                    // difff = -1

                    // cases like abcd, abc

                    if(t.size() < prev.size())
                            ok = 0;
            }

            prev = t;
    }

    if(ok){

            vis = vi(26);

            l(i, 0, 26){

                    if(!vis[i]){

                            vis[i] = 1;

                            TopologicalSort(i, 1);
                    }
            }

            reverse(all(order));

            for(auto p : order)
                    cout << (char)(p + 'a');
            cout << endl;
            
    }

    else cout << "Impossible" << endl;
}
