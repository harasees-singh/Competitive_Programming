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
#define MOD_DEFINE                      const int MOD = 1346140268867;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        x += 0x9e3779b97f4a7c15;
    
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
    
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int limit = 2e7;
    
unordered_set<int, custom_hash> ban;

vi answer(10);

int reccount = 0;

int summand = 0;

int Hash(vi &arr){

    int p = 1; 

    int ret = 0;

    l(i, 0, sz(arr))

        ret += (p*(arr[i]))%MOD, ret%=MOD, p*=(2e5 + 1), p%=MOD;

    return ret;
}
int recursion = 0;

// bool hogya = false;

void rec(int i, const vector<vi> &adj, int summ, vi fill, int w){

    reccount++; 

    if(reccount > limit) return;

    if(i == sz(adj)){

        recursion += (summ > summand);
        if(summ > summand and ban.find(Hash(fill)) == ban.end()){

            summand = summ;

            for(int j = 0; j < sz(fill); j++)

                answer[j] = fill[j];
        }
        
        return;
    }


    for(int j = sz(adj[i]) - 1; j >= max(0ll, sz(adj[i]) - w); j--){

        if(reccount > limit) return;
        fill.pb(j + 1);

        rec(i + 1, adj, summ + adj[i][j], fill, w);

        fill.pop_back();
    }
}


// void recLastfour(int i, const vector<vi> &adj, int summ, vi fill){

//     // assert(i == sz(fill));
//     // if(hogya) return;

    

//     // cout << i << endl;

//     // if(reccount > limit) return;

//     if(i == sz(adj)){
//         recursion += (summ > summand);
//         if(summ > summand and ban.find(Hash(fill)) == ban.end()){

//             summand = summ;

//             for(int j = 0; j < sz(fill); j++)

//                 answer[j] = fill[j];
//         }
        
//         return;
//     }

//     // for(auto p : fill) cout << p << space; cout << endl;

//     for(int j = sz(adj[i]) - 1; j >= max(0ll, sz(adj[i]) - 4); j--){

//         fill.pb(j + 1);

//         rec(i + 1, adj, summ + adj[i][j], fill, w);

//         fill.pop_back();
//     }
// }





int32_t main(){
    FIO

    int n; cin >> n;

    vector<vi> mat(n);

    l(i, 0, n){

        int cnt; cin >> cnt; 

        l(j, 0, cnt){

            int t; cin >> t;  

            mat[i].pb(t);
        }
    }

    int m; cin >> m;

    l(i, 0, m){

        vi t; 

        l(j, 0, n){

            int temp; cin >> temp; t.pb(temp);
        }
        // 1, 2, 3

        // 321
        ban.insert(Hash(t));
    }
    vi emptyy;

    int pt = 1;
    while(reccount < limit)
            rec(0, mat, 0, emptyy, pt), pt++;

    // if(summand == 0)
        
    //     rec(0, mat, 0, emptyy);

    // assert(recursion);
    // assert(summ > summand);
    for(int i = 0; i < n; i++) 

        cout << answer[i] << space; cout << endl;
}
