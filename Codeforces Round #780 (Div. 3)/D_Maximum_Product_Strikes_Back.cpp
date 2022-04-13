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

pair<int, pii> get(pii compute, vi &in){
    int neg = 0;

    int cnt = 0;

    if(compute.ff > compute.ss) return {0, compute};

    for(int i = compute.ff; i <= compute.ss; i++) {
    
        if(in[i] < 0) neg ^= 1;

        cnt += (abs(in[i]) == 2);    
    }
    int cost2 = 0;
    pii ret = compute;
    pii cpy = ret;
    int Cost = infinity;
    int cost = 0;
    if(neg){
        for(int i = ret.ff; ; i++) {
            if(in[i] < 0){
                cost += (in[i] == -2);
                compute = {i + 1, ret.ss};

                break;
            }
            if(in[i] == 2) cost++;
        }
        for(int i = ret.ss; ; i--){
            if(in[i] < 0){
                cost2 += (in[i] == -2);
                
                if(cost2 < cost){
                    compute = {ret.ff, i - 1};
                }
                break;
            }
            cost2 += (in[i] == 2);
        }
    }
    Cost = min(cost, cost2);
    // cout << Cost << endl;
    return {cnt - Cost, compute};
}

int32_t main(){
        
        FIO

        w(T){
            int n; cin >> n; 

            vi in(n);

            for(auto &p : in) cin >> p;

            vpii compute;
            int lst = 0;
            for(int i = 0; i < n; i++){
                if(in[i] == 0){
                    compute.push_back(make_pair(lst, i - 1)); 

                    lst = i + 1;
                }
            }
            
            compute.push_back(make_pair(lst, n - 1));

            int mx = 0; 

            pii ans = {n, n - 1};

            for(auto p : compute){
                auto ret = get(p, in);

                int val = ret.ff; 


                if(val > mx){
                    mx = val; 

                    ans = ret.ss;
                }
            }
            assert(ans.ff + n - ans.ss - 1 <= n);
            cout << ans.ff << ' ' << n - ans.ss - 1 << endl;
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