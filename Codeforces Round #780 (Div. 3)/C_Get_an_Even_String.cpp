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
string s; 
vector<vi> nxt;
vi dp;
int get(int i){
    if(i == sz(s)) return 0;

    if(dp[i] != -1) return dp[i];

    int mn = infinity;
    // if(i < sz(s) - 1 and s[i] == s[i + 1]) mn = get(i + 2);

    amin(mn, 1 + get(i + 1));

    int skip = nxt[s[i] - 'a'][i];

    if(skip != -1){
        amin(mn, skip - i - 1 + get(skip + 1));
    }

    return dp[i] = mn;
}

int32_t main(){
        
        FIO

        w(T){
            cin >> s;

            nxt = vector<vi> (26, vi(sz(s), -1));
            int n = sz(s);
            for(int i = n - 2; i >= 0; i--){

                for(int c = 0; c < 26; c++){
                    // for(int j = 0; j < n - 1; j++)
                    nxt[c][i] = nxt[c][i + 1];
                }

                nxt[s[i + 1] - 'a'][i] = i + 1;

                // for(int i = 0; i < 26; i++){
                //     for(int j = 0; j < n - 1; j++)
                //         nxt[i][j] = nxt[i][j + 1], cout << nxt[i][j] << ' '; 

                //         cout << endl;

                // }

            }
            

            dp = vi(sz(s), -1);

            cout << get(0) << endl;
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