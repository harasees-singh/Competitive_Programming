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
vector<vector<string>> dp;  // stores the string which when put at ith id maximizes our answer for dat k // "-1" if no valid answer can be formed for {i, k};
vector<string> HASH = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int can_make(string f, char to){
    string t = HASH[to - '0'];

    int cnt = 0;

    for(int i = 0; i < 7; i++){
        if(t[i] == '1') cnt += f[i] == '0';

        else if(f[i] == '1') return -1;
    }
    return cnt;
}
bool maximize(vector<string>& s, int k, int i){
    if(i == sz(s)) return k == 0;

    if(dp[i][k] != ""){
        if(dp[i][k] == "-1") return false;

        return true;
    }

    string cur = s[i];

    for(char make = '9'; make >= '0'; make--){
        int get = can_make(cur, make);

        if(get == -1 or get > k) continue;

        // s[i] = make;

        if(maximize(s, k - get, i + 1)){
            dp[i][k] = HASH[make - '0'];

            return true;
        }
    }
    dp[i][k] = "-1";

    return false;
}

int32_t main(){
        
        FIO

        int n; cin >> n;

        vector<string> have;

        int k; cin >> k;

        dp = vector<vector<string>> (n, vector<string>(k + 1, ""));

        for(int i = 0; i < n; i++){
            string t; cin >> t;

            have.pb(t);
        }

        bool ret = maximize(have, k, 0);

        if(not ret){
            cout << -1; 
        }
        else{
            for(int i = 0; i < n; i++){
                string out = dp[i][k];
                char put = find(all(HASH), out) - HASH.begin() + '0';
                k -= can_make(have[i], put);

                cout << put;
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