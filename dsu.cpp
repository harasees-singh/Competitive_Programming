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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

// 
int n = 10;
vector<int> parent(n + 1);

vector<int> Rank(n + 1);

int findParent(int i){
    if(parent[i] == i) return i;

    return findParent(parent[i]);   // path compression

}
void Union(int u, int v){
    int U = findParent(u), V = findParent(v);

    if(U == V) return;

    if(Rank[U] > Rank[V]){

        parent[V] = U;
    }
    else if(Rank[U] == Rank[V]){
        parent[V] = U;

        Rank[U]++;
    }
    else{
        // rank of v is greater than rank of u

        parent[U] = V;
    }
}

int32_t main(){
        FIO 

        for(int i = 1; i <= n; i++) parent[i] = i;

        for(int i = 1; i <= n; i++) Rank[i] = 0;
        
        // MakeSet()

        Union(1, 3);

        Union(3, 5);

        cout << findParent(5);

        return 0;
}
