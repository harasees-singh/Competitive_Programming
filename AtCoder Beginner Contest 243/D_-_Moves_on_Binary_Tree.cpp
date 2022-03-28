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
string bin(int x){
    string out = "";

    while(x){
        if(x & 1) out.push_back('1');

        else out.pb('0');

        x /= 2;
    }
    reverse(all(out));

    return out;
}
int get(vi &have, int it){
    int ret = 0;

    for(int i = 0; it >= 0; i++, it--){
        ret += (1ll << it) * have[i];
    }
    return ret;
}
int32_t main(){
        
        FIO

        int n, x; cin >> n >> x;

        // represent x as a vector

        string s = bin(x);
        // cout << s;

        vi have(1e6 + 1);

        for(int i = 0; i < sz(s); i++) have[i] = s[i] - '0';

        string perform; cin >> perform;

        int it = sz(s) - 1;

        // cout << it << endl; 

        for(auto p : perform){
            if(p == 'U') have[it--] = 0;

            else if(p == 'L') it++;

            else have[++it] = 1;
        }

        cout << get(have, it);

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/