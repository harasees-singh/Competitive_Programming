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
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE

void complement(string &b){
    for(auto &p : b){
        p = (1 - (p - '0')) + '0';
    }
}

// call dis once as it is and once after swapping 1s and zeroes
vector<pair<int, int>> ans;
bool equal(string a, string b, int n){
    int l = n;

    for(int i = 0; i < n; i++){
        if(a[i] == '0'){
            l = i; break;
        }
    }
    if(l == n){
        // cout << "YES" << endl; 

        // cout << 2 << endl;

        // cout << 1 << ' ' << 1 << endl;
        // cout << 2 << ' ' << n << endl;
        ans.push_back({1, 1});
        ans.push_back({2, n});
        return true;
    }
    int r = l; 
    for(int i = r + 1; i < n; i++){
        if(a[i] == '1') break;

        r = i;
    }
    for(int i = 0; i < l; i++){
        if(b[i] == '0'){
            // cout << "NO" << endl; return;
            return false;
        }
    }
    for(int i = l; i <= r; i++){
        if(b[i] == '1'){
            // cout << "NO" << endl; return;
            return false;
        }
    }
    for(int i = r + 1; i < n; i++){
        if(b[i] == '0'){
            // cout << "NO" << endl; return;
            return false;
        }
    }
    // cout << "YES" << endl;
    // cout << 2 << endl; 
    // cout << l + 1 << ' ' << r + 1 << endl; 
    // cout << 1 << ' ' << n << endl; 
    ans.push_back({l + 1, r + 1});
    ans.push_back({1, n});
    return true;
}
void slv(){
        int n; cin >>n; 
        ans.clear();
        string a, b; cin >> a >> b;

        if(n == 1){
            if(b[0]=='1'){
                cout << "NO" << endl; return;
            }
            // 0/1, 0
            cout << "YES" << endl; 

            if(a[0]=='0'){
                cout << 0 << endl; return;
            }
            cout << 1 << endl;
            cout << 1 << ' ' << 1 << endl; return;
        }

        if(a == b){
            // 000111
            // 000111

            // 11000011
            // 11000011
            if(equal(a, b, n)){
                cout << "YES" << endl;

                cout<< ans.size() << endl;

                for(auto p : ans) cout << p << endl;
                return;
            }

            complement(a); complement(b);


            if(equal(a, b, n)){
                ans.push_back({1, 1}); ans.push_back({2, n}); // 1111, 1111 to 0000, 0000
                cout << "YES" << endl;

                cout << ans.size() << endl;

                for(auto p : ans) cout << p << endl;

                return;
            }

            cout << "NO" << endl; return;
        }
        else{
            
            // must be complementary already 
            // 00011100
            // 11100011 else no
            complement(a);

            ans.push_back({1, n});

            if(a != b){
                cout << "NO" << endl; return;
            }

            // 0s must come together or 1s must come together

            // cout << a << endl;
            if(equal(a, b, n)){
                cout << "YES" << endl;

                cout<< ans.size() << endl;

                for(auto p : ans) cout << p << endl;

                return;
            }

            

            complement(a); complement(b);

            if(equal(a, b, n)){
                ans.push_back({1, 1}); ans.push_back({2, n});
                // ans.push_back({1, 1}); ans.push_back({2, n});
                
                cout << "YES" << endl;

                cout << ans.size() << endl;

                for(auto p : ans) cout << p << endl;

                return;
            }

            cout << "NO" << endl; return;
        }
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