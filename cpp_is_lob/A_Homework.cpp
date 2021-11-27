#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
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
#define fps(x,y)                        fixed<<setprecision(y)<<x
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

vi freq(26);

struct Char{
    char c;

    bool operator<(Char t) const{
        return freq[c - 'a'] < freq[t.c - 'a'];
    }

    Char (char c){
        this->c = c;
    }
};

int32_t main(){
    FIO
    string s; cin >> s;
    int k; cin >> k;

    for(auto p : s) freq[p - 'a']++;
    multiset<Char> order;

    l(i, 0, s.size()){
        Char t(s[i]);

        order.insert(t);
    }
    // for(auto p : order) cout << p.c << endl;
    for(auto p : order){
        if(!k) break;

        int sub = min(k, freq[p.c - 'a']);

        freq[p.c - 'a'] -= sub, k -= sub;
    }
    cout << 26 - count(all(freq), 0ll) << endl;

    for(auto p : s){
        if(freq[p - 'a']) cout << p, --freq[p - 'a'];
    }
    cout << endl;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/