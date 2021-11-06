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

struct Pair{
        int f, s; 
        Pair(int a, int b){
                f = a, s = b;
        }
        bool operator< (Pair p) const{
                int one = s - f;
                int two = p.s - p.f;

                if(one == two)
                        return (p.f < f);
                return one < two;
        }
};

int32_t main(){
    FIO

        set<Pair> s;

        // s.insert(Pair(2, 3));
        // s.insert(Pair(3, 6));

        // cout << (*s.begin()).f << endl;
        
        w(t){
                int n; cin >> n;

                set<Pair> s;

                s.insert(Pair(1, n));

                vi ans(n + 1);

                l(i, 1, n + 1){
                        
                        Pair cur = (*prev(s.end()));

                        ans[(cur.f + cur.s)/2] = i;

                        int mean = cur.f + cur.s; mean/=2;

                        Pair t1(cur.f, mean - 1);
                        Pair t2(mean + 1, cur.s);

                        s.erase(cur);

                        if(t1.f <= t1.s) s.insert(t1);
                        if(t2.f <= t2.s) s.insert(t2);
                }
                l(i, 1, n + 1) cout << ans[i] << space; cout << endl;

        }

}
