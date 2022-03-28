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

MOD_DEFINE
int rem(vi &in, int allowed){
        int have = 1; 

        for(int i = 1; i < sz(in); i++){
                have += (in[i] != in[i - 1]);
        }
        return max(0ll, have - allowed);
}
int get(int I, int n){
        int bits = I * 8;

        int per = bits/n;

        // cout << per << endl; cout.flush();

        int unique = 1;

        for(int i = 0; i < per and unique < n; i++){
                unique *= 2;
        }
        // cout << unique << endl; cout.flush();
        return unique;
}

int32_t main(){
        
        FIO     
        int n, I; cin >> n >> I;

        vi in(n);
        for(auto &p : in) cin >> p;

        sort(all(in));

        int unique = get(I, n);

        // cout << unique << endl; cout.flush();

        int remove = rem(in, unique);

        vi freq;
        int cur = 1;
        for(int i = 1; i < n; i++){
                if(in[i] != in[i - 1]){
                        freq.push_back(cur);

                        cur = 1;
                }
                else cur++;
        }
        freq.push_back(cur);


        vi pref(freq);
        for(int i = 1; i < sz(freq); i++) pref[i] += pref[i - 1];

        vi suffix(sz(freq) + 1);
        // for(auto p : suffix) cout << p << ' '; cout << endl; cout.flush();
        
        for(int i = sz(freq) - 1; i >= 0; i--){
                suffix[i] = suffix[i + 1] + freq[i];
        }

        int slide = sz(freq) - remove;
        // cout << remove << endl;
        // cout << slide << endl; cout.flush();

        int mn = suffix[slide];

        // cout << mn << endl;

        for(int i = 1; i + slide <= sz(freq); i++){
                mn = min(pref[i - 1] + suffix[i + slide], mn);
        }
        cout << mn << endl;

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/