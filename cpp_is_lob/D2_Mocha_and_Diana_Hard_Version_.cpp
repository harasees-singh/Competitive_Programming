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

int Parent1[(int)1e5 + 1];
int Rank1[(int)1e5 + 1];

int Parent2[(int)1e5 + 1];
int Rank2[(int)1e5 + 1];

void MakeSet(int Parent[]){ 
        l(i, 1, 1e5 + 1)
                Parent[i] = i;
}

int findParent(int u, int Parent[]){
        if(Parent[u] == u)
                return u;
        
        return Parent[u] = findParent(Parent[u], Parent);
}

void Union(int u, int v, int Rank[], int Parent[]){

        u = findParent(u, Parent);
        v = findParent(v, Parent);
        
        if(u < v)

                Parent[v] = u;
        
        // else if(Rank[u] < Rank[v])

        //         Parent[u] = v;

        else{
                Parent[u] = v;
        }
}

int32_t main(){
        FIO

        queue<int> a;

        cout << a.size() << endl;

        int n, m1, m2; cin >> n >> m1 >> m2;

        MakeSet(Parent1);
        MakeSet(Parent2);

        int vis1[n + 1] = {0};
        int vis2[n + 1] = {0};

        l(i, 0, m1){
                int u, v; cin >> u >> v;

                Union(u, v, Rank1, Parent1);
        }

        l(i, 0, m2){

                int u, v; cin >> u >> v;

                Union(u, v, Rank2, Parent2);

        }

        

        vpii ans;
        
        l(i, 2, n + 1){
                if(findParent(i, Parent1) != findParent(1, Parent1) and findParent(i, Parent2) != findParent(1, Parent2)){

                        Union(1, i, Rank1, Parent1), Union(1, i, Rank2, Parent2);

                        ans.push_back(make_pair(i, 1));


                }
        }
        vi One, Two;

        l(i, 1, n + 1){
                int p = findParent(i, Parent1);
                if(p != 1 and !vis1[p])
                        vis1[p] = 1, One.pb(p);

        }

        l(i, 1, n + 1){
                int p = findParent(i, Parent2);
                if(p != 1 and !vis2[p])
                        vis2[p] = 1, Two.pb(p);
        }
        cout << sz(ans) + min(sz(One), sz(Two)) << endl;
        for(auto p : ans) cout << p.ff << space << p.ss << endl;

        l(i, 0, min(sz(One), sz(Two))){
                cout << One[i] << space << Two[i] << endl;
        }

}
