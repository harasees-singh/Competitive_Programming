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

int compute(int n){
    return (bool)n + 2*(n - 1)*(bool)n;
}

int32_t main(){
    FIO

    w(t){
        int n, k; cin >> n >> k;

        string s; cin >> s;

        int init = 1 + (n - 1)*2;

        int cur = count(all(s), 'L') - k;

        if(count(all(s), 'L') == n){
            cout << (1 + (min(n, k) - 1)*2)*(bool)k << endl;
            continue;
        }

        int corner = 0;

        
        int id = 0;

        while(id < n and s[id] == 'L') id++, corner++;

        s = s.substr(id);

        id = sz(s) - 1;

        while(id >= 0 and s[id] == 'L') id--, corner++;

        if(id >= 0){
            s = s.substr(0, id + 1);
        }

        while(corner and cur > 0){
            corner--, init-=2; cur--;
        }

        int cnt = 0;
        vi Lcount;
        for(auto p : s){
            if(p == 'W') Lcount.pb(cnt), cnt = 0;

            else cnt++;
        }

        sort(all(Lcount), greater<int>());

        int pt = 0;

        while(cur > 0){
            init -= 3;
            cur--;
            Lcount[pt]--;
            int sub = min(cur, Lcount[pt]);

            init -= sub*(2);

            cur -= sub; pt++;
        }
        cout << init << endl;
    }   

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/