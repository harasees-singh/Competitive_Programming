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
bool f(string& s, int i){
        return s[i] == '*';
}
void slv(){
        int n; cin >> n; 

        string s1, s2; cin >> s1 >> s2;

        int l, r;

        for(int i = 0; i < n; i++){
                if(s1[i]=='*' or s2[i]=='*'){
                        l = i; break;
                }
        }
        for(int i = n - 1; i >= 0; i--){
                if(s1[i]=='*' or s2[i]=='*'){
                        r = i; break;
                }
        }
        vector<vi> dp(n, vi(2));

        dp[l][0] = s2[l]=='*';
        dp[l][1] = s1[l]=='*';

        for(int i = l + 1; i <= r; i++){
                if(f(s1, i) and f(s2, i)){
                        dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);

                        dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);

                }
                else if(f(s1, i)){
                        dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);

                        dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
                }
                else if(f(s2, i)){
                        dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);

                        dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 2);
                }
                else{
                        dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);

                        dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
                }
        }
        cout << min(dp[r][0], dp[r][1]) << endl;
}

int32_t main(){
        
        FIO

        w(T) 
                slv();
        
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/