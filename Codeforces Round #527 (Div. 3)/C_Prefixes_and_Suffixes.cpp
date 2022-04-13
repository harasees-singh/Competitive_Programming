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
set<string> PREF;
vector<string> input;
multiset<string> in;
bool get(pair<string, string> pref_suff, int n){
    
    string pref, suff; 

    pref = pref_suff.ff.substr(0, n - 2);

    suff = pref_suff.ss.substr(1);

    PREF.clear();

    in.clear(); for(auto p : input) in.insert(p);

    while(sz(pref_suff.ff)){
        // ans[pref_suff.ff] = 'P';
        PREF.insert(pref_suff.ff);
        if(in.count(pref_suff.ff) == 0) return false;
        in.erase(in.find(pref_suff.ff));
        pref_suff.ff.pop_back();
    }
    while(sz(pref_suff.ss)){
        // ans[pref_suff.ss] = 'S';
        if(in.count(pref_suff.ss) == 0) return false;
        in.erase(in.find(pref_suff.ss));
        pref_suff.ss = pref_suff.ss.substr(1);
    }        
    return true;
}

int32_t main(){
        
        FIO

        int n; cin >> n;

        pair<string, string> pref_suff = {"", ""}; 


        for(int i = 0; i < 2 * n - 2; i++){
            string s; cin >> s;
            input.push_back(s);
            in.insert(s);

            if(sz(s) == n - 1) (pref_suff.ss == "" ? pref_suff.ss : pref_suff.ff) = s;
        }
        if(n == 2){
            cout << 'P'; cout << 'S' << endl; return 0;
        }
        // cout << pref_suff << endl; cout.flush(); 
        if(get(pref_suff, n)); 

        else get({pref_suff.ss, pref_suff.ff}, n);
        
        for(auto p : input){
            if(PREF.count(p)){
                cout << "P"; PREF.erase(p);
            }
            else
                cout << "S";
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