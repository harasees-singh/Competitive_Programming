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
void solve(){
    int a, b; cin >> a >> b;

    string s; cin >> s;
    int n = a + b;
    for(int i = 0, j = n - 1; i < j; i++, j--){
        if(s[i] == s[j] and s[i] == '?') continue;

        else if(s[i] == '?'){
            a -= 2 * (s[j] == '0'); 

            b -= 2 * (s[j] == '1');

            s[i] = s[j];
        }

        else if(s[j] == '?'){
            a -= 2 * (s[i] == '0'); 

            b -= 2 * (s[i] == '1');

            s[j] = s[i];
        }
        else if(s[i] == s[j]){
            a -= 2 * (s[i] == '0'); 

            b -= 2 * (s[i] == '1');

        }
        else{
            cout << -1; return;
        }
    }
    if(a < 0 or b < 0){
        cout << -1; return;
    }
    vi rem = {a, b};

    int pt = 0;

    for(int i = 0, j = n - 1; i <= j; i++, j--){
        if(i == j){
            if(s[i] != '?') {rem[s[i] - '0']--; break;}
            if(rem[pt]) s[i] = pt + '0', rem[pt]--;

            else s[i] = (pt + 1)%2 + '0', rem[(pt + 1)%2]--;

        }
        if(s[i] == '?'){
            if(rem[pt] <= 1){
                pt++; 
                
                pt %= 2;

                // cout << rem[pt] << endl; 
                // cout << pt << endl;
                if(rem[pt] <= 1){ 
                    cout << -1; return;
                }
            }
            s[i] = (pt + '0');
            s[j] = s[i];
            rem[pt] -= 2;
            // cout << rem[0] << ' ' << rem[1] << endl;
        }
    }
    if(rem[0] == rem[1] and rem[0] == 0)
        cout << s;
    else cout << -1;
}
int32_t main(){
        
        FIO

        w(T){
            solve(); cout << endl;
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