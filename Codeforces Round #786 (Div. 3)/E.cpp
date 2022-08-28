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

int cut(int i, int j){
    if(i < j) swap(i, j);

    // i > j

    if(i > 2*j){
        return (i + 1)/2;
    }
    return (i + j + 2)/3; 
}
int CUT(int i, int j){
    if(i%2 and j%2){
        return i/2 + j/2 + 1; 
    }
    else return (i/2 + i%2 + j/2 + j%2);

    return 0;
}
int32_t main(){
        FIO 

        int n; cin >> n; 

        vi in(n); for(auto &p : in) cin >> p; 

        vector<pii> temp; for(int i = 0; i < n; i++) temp.push_back(make_pair(in[i], i));

        sort(all(temp));

        pii minids = {temp[0].ss, temp[1].ss};

        temp.clear(); temp.resize(0);

        int ans = in[minids.ff]/2 + (in[minids.ff]%2) + in[minids.ss]/2 + (in[minids.ss]%2);

        for(int i= 0; i < n-1; i++){
            amin(ans, min(cut(in[i], in[i + 1]), cut(in[i + 1], in[i])));
        }
        for(int i =0; i + 2 < n; i++){
            amin(ans, CUT(in[i], in[i + 2]));
        }
        cout << ans << endl;
        return 0;
}