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
struct FenwickTree{
    // zero based indexing
    // use query(l, r) to get the sum of elements in range[l, r]
    // exceptions handled when l = 0; (read(-1) returns 0)
    // increase and query take logn time and constant space.
    // constructor takes vector<int> input (a const reference) to construct the tree (ft) in nlogn time.

    vector<int> ft;

    FenwickTree(vector<int> const &I){
        ft.assign(I.size(), 0);

        for(int i = 0; i < I.size(); i++){
            increase(i, I[i]);
        }
    }

    int read(int idx){
        if(idx < 0) return 0;

        int ret = 0;

        for(int i = idx; i >= 0; i = (i&(i + 1)) - 1){
            ret += ft[i];
        }
        return ret;
    }

    void increase(int i, int delta){
        for(int j = i; j < ft.size(); j = j|(j + 1)){
            ft[j] += delta;
        }
    }

    int query(int l, int r){
        return read(r) - read(l - 1);
    }
};
int32_t main(){
        FIO 

        int n, m, q; cin>> n >> m >> q; 

        vector<string> in(n); for(auto &p : in) cin >> p; 
        vi hash(n * m); 
        for(int i= 0; i < n * m; i++){
            hash[i] = (in[i%n][i/n] == '*');
        }

        FenwickTree ft(hash);

        // for(auto p: hash) cout << p  << " ";  cout << endl; // ok

        int tot = accumulate(all(hash), 0ll);
        // cout << tot << endl; // wrong

        for(int i= 0; i < q; i++){
            int x, y; cin >> x >> y; 

            int id = (y - 1) * n + (x - 1);

            if(hash[id]){
                ft.increase(id, -1); tot--;
            }
            else ft.increase(id, 1), tot++;
            // cout << tot << ' ' << ft.query(0, tot- 1) << endl;

            cout << tot - (ft.query(0, tot - 1)) << endl;
        
            hash[id] ^= 1;
        }

        return 0;
}
