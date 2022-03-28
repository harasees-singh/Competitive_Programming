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

// brute forcing
int n;
vector<string> mat;
bool hori(int i, int j){
        int have = n - j; if(have < 6) return false;
        
        int cnt = 0;
        
        for(int col = j; col < j + 6; col++){
                cnt += mat[i][col] == '.';
        }
        return cnt < 3;
}
bool vert(int i, int j){
        int have = n - i; if(have < 6) return false;
        
        int cnt = 0;
        
        for(int col = i; col < i + 6; col++){
                cnt += mat[col][j] == '.';
        }
        return cnt < 3;
}
bool diag(int i, int j){
        int have = n - max(i, j); if(have < 6) return false;
        
        int cnt = 0;
        
        for(int col = 0; col < 6; col++){
                cnt += mat[i + col][j + col] == '.';
        }
        if(cnt < 3) return true;

        return false;
        
}
bool diag2(int i, int j){
        int cnt = 0;
        if(i + 5 >= n or j - 5 < 0) return false;

        for(int it = 0; it < 6; it++){
                cnt += mat[i + it][j - it] == '.';
        }

        return cnt < 3;
}

int32_t main(){
        
        FIO

        cin >> n;

        mat = vector<string> (n);

        for(auto &p : mat) cin >> p;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        if(diag(i, j) or diag2(i, j) or hori(i, j) or vert(i, j)){
                                cout << "Yes"; return 0;
                        }
                }
        }
        cout << "No";

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/