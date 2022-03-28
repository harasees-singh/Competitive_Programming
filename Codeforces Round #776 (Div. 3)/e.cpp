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

int32_t main(){
        FIO 

        w(t){
            int n, d; cin >> n >> d;

            vi in(n);

            for(auto &p : in) cin >> p;

            in.push_back(0), in.push_back(d + 1);

            sort(all(in));
            // int lst_seg = -1;
            // if(count(all(in), d) == 0){
            int lst_seg = d - *(--upper_bound(all(in), d));
            // }
            multiset<int> have;
            int mx = 0;
            for(int i = 1; i <= n; i++){
                have.insert(in[i] - in[i - 1] - 1);

                // cout << in[i] - in[i - 1] - 1 << ' ' << in[i + 1] - in[i] - 1 << endl; 
                
                // if(i < n) have.insert(in[i + 1] - in[i] - 1);
            }
            // for(auto p : have) cout << p << ' '; cout << endl;
            for(int i = 1; i <= n ;i++){
                // remove ith point

                int f2 = 0;

                int f1 = in[i] - in[i - 1] - 1; if(i < n) f2 = in[i + 1] - in[i] - 1;
                // assert(have.count(f1));

                have.erase(have.find(f1)); if(i < n) have.erase(have.find(f2));
                if(i < n) have.insert(f1 + f2 + 1);


                int seg = *have.begin();
                int c = *(prev(have.end()));
                // cout << seg << ' ' << c << ' ' << lst_seg << endl;
                mx = max(min(seg, max(lst_seg - 1, (c - 1)/2)), mx);

                // assert(have.count(f1 + f2  + 1));

                if(i < n) have.erase(have.find(f1 + f2 + 1));

                have.insert(f1); if(i < n) have.insert(f2);
            }
            cout << mx << endl;
        }

        return 0;
}
