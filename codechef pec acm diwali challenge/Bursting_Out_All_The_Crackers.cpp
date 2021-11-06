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

vi div(int g){

        vi ans;

        for(int i = 1; i*i <= g; i++){
                if(g%i == 0)
                        ans.push_back(i), ans.pb(g/i);

                if(i*i == g)
                        ans.pop_back();
        }
        return ans;
}

int32_t main(){
    FIO

    w(t){
            int n; cin >> n;

            vi I(n);

            for(auto &p : I)
                    cin >> p;

            if(*max_element(all(I)) == 0){
                    l(i, 1, n + 1) cout << i << space; cout << endl; continue;
            }
            
            vi cnt(35);

            for(auto p : I){

                    int i = 0;

                    while(p){
                            cnt[i] += (p&1);
                            i++;
                            p/=2;
                    }
            }

            int gcd = 0;

            for(auto p : cnt) gcd = __gcd(gcd, p);

            // cout << div(gcd) << endl;

            vi k(div(gcd));

            sort(all(k));

            for(auto p : k)
                    cout << p << space; cout << endl;
    }
}
