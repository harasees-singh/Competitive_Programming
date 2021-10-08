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
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int rec(const  string &s, char curr){

        if(sz(s) == 1)
                return (s[0] != curr);

        string first = s.substr(sz(s)/2);
        string second = s.substr(0, sz(s)/2);

        int c1 = sz(s)/2 - count(s.begin(), s.begin() + sz(s)/2, curr);
        int c2 = sz(s)/2 - count(s.begin() + sz(s)/2, s.end(), curr);

        int m1 = c1 + rec(first, curr + 1);
        int m2 = c2 + rec(second, curr + 1);
        
        return min(m1, m2);
}

int32_t main(){
    FIO

    w(t){

            int n; cin >> n;

            string s; cin >> s;

            cout << rec(s, 'a') << endl;
    }

}
