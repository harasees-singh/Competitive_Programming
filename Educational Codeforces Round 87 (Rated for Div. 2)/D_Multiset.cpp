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
// #define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(T)                            int T; cin >> T; while(T--)
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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
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
int get(int pos, FenwickTree &ft){
    int l = 0, r = 1e6;

    while(l <= r){
        int mid = (l + r)/2;

        int tot = ft.query(0, mid);

        if(tot >= pos) r = mid - 1;

        else l = mid + 1;
    }
    return l;
}
int32_t main(){
        
        FIO

        int n, q; cin >> n >> q;

        vi freq(1e6 + 1);

        for(int i = 0; i < n; i++){
            int t; cin >> t;

            freq[t]++;
        }
        FenwickTree ft(freq);

        for(int i = 0; i < q; i++){
            int t; cin >> t;
            if(t > 0) ft.increase(t, 1);

            else{
                int id = get(abs(t), ft);

                assert(id >= 1 and id <= 1e6);

                ft.increase(id, -1);
            }
        }
        for(int i = 1; i <= 1e6; i++){
            if(ft.query(i, i)){
                cout << i << endl; return 0;
            }
        }
        cout << 0;
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/