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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

int32_t main(){
        
        FIO
        // maintain minimum and maximum

        w(t){
            int n; cin >> n;

            vi in(n);

            for(auto &p : in) cin >> p;

            vector<pii> store(n);

            if(in[n - 2] > in[n - 1]){
                cout << -1 << endl; continue;
            }

            pii put = {n - 2, n - 1}; // mini and maxi;

            vector<vi> ans;

            for(int i = n - 3; i >= 0; i--){
                
                store[i] = put;

                int place = in[put.ff] - in[put.ss];

                if(place < in[i]){
                    ans.push_back({i + 1, put.ff + 1, put.ss + 1});

                    
                }
                amin(in[i], place);

                if(in[i] < in[put.ff]) put.ff = i;

                else if(in[i] > in[put.ss]) put.ss = i;

            }

            vi cpy(in); sort(all(cpy)); if(cpy != in){cout << -1 << endl; continue;}
            
            cout << sz(ans) << endl;
            for(auto vec : ans){
                cout << vec[0] << ' ' << vec[1] << ' ' << vec[2] << endl;
            }
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