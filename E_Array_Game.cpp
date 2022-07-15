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
int m;
void cur(){
    cout << (m ? "Bob" : "Alice") << endl; 
}
void alter(){
    cout << (m ? "Alice" : "Bob") << endl;
}
void slv(){
        int n; cin >> n; vi in(n);

        cin >> in;

        m = 0;

        vi pref(n), suff(n);
        pref[0] = 1;

        int i = 1;
        for(; i < n; i++) if(in[i] > in[i - 1]) pref[i] = i + 1; else break;
        reverse(pref.begin(), pref.begin() + i);

        suff[n - 1] = 1;

        i = n - 2; 

        for(; i >= 0; i--) if(in[i] > in[i + 1]) suff[i] = n - i; else break;

        reverse(suff.begin() + i + 1, suff.end());

        // cout << pref << suff << endl;
        int lst = -1;
        i = 0; int j = n - 1;
        for(; i < j; m ^= 1){
            if(max(in[i], in[j]) <= lst){
                alter(); return;
            }

            if(in[i] == in[j]){
                
                if(pref[i]%2 or suff[i]%2){
                    cur(); return;
                }

                alter(); return;
            }
            
            if(in[i] > in[j]){
                if(pref[i]%2){
                    cur(); return;
                }
                else{
                    if(in[j] <= lst){
                        alter(); return;
                    }
                    lst = in[j]; j--;
                }
            }
            else{
                if(suff[j]%2){
                    cur(); return;
                }
                else{
                    if(in[i] <= lst){
                        alter(); return;
                    }
                    lst = in[i]; i++;
                }
            }

        }
        cout << ((n&1) ? "Alice" : "Bob") << endl;
}

int32_t main(){
        
        FIO

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