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
// bool get(int i, int j, string &s){
//     if(i < 0 or j < 0 or i >= sz(s) or j >= sz(s)){
//         return true;
//     } 
//     else{
//         if(s[i] == s[j] and s[i] != 'W') return false;
//     }
//     return true;
// }
void ok(string &s){
    // return get(i - 1, i - 2, s) and get(i + 1, i + 2, s);
    pair<bool, bool> BR = {false, false};
    for(int i= 1; i < sz(s); i++){
        if(s[i] == 'W'){
            if(BR.ff ^ BR.ss){
                cout << "NO" << endl; return;
            }
            BR = {false, false};
        }
        else if(s[i] == 'B'){
            BR.ff = true;
        }
        else{
            BR.ss = true;
        }
        
    }
    cout << "YES" << endl; return; 
}

int32_t main(){
        
        FIO
        // WBB or BBW not allowed

        w(T){
            int n; cin >> n;

            string s; cin >> s;

            s = 'W' + s + 'W';

            ok(s);
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