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
void solve(){
    int n, m; cin >> n >> m;

    mii train;

    // id, speed;

    vi in(n); for(auto &p : in) cin >> p;

    int lst = infinity;

    for(int i=0; i < n; i++){
        if(in[i] < lst){
            lst = in[i];

            train[i+1] = lst;
        }
    }
    for(int i = 0; i < m; i++){
        int id, dec; cin >> id >> dec; 

        in[id-1] -= dec;
        while(true){
            auto it = train.lower_bound(id);
            if(it==train.end())break;
            if((*it).ss >= in[id-1]){
                train.erase(it);
            }
            else break;
        }
        auto it = train.lower_bound(id);

        if(it!=train.begin()){
            --it;

            if((*it).ss > in[id-1])
                train[id] = in[id-1];
        }
        else{
            train[id]=in[id-1];
        }
        // for(auto p : train){
        //     cout << p << endl;
        // }
        // cout << endl;
        
        cout << sz(train) << ' ';
    }
    cout << endl;

}
int32_t main(){
        FIO 

        w(T){
            solve();
        }

        return 0;
}
