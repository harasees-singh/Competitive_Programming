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
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO
    test_cases_loop{
        int n; cin >> n;

        // w possible from 1 to 100 only

        multiset<int> w;

        multiset<int> c;

        

        vi I(n);

        // c = w;
        // cout << c.empty() << endl; 

        l(i, 0, n){
                int t; cin >> t;

                I[i] = t;

                w.insert(t);
        }
        for(auto p : w)
            c.insert(p);
        int maxima = 0;

        l(i, 1, 101){
            int cnt = 0;
            // cout << w.empty() << endl;
            l(j, 0, n){

                if(w.empty())
                    break;


                int curr = I[j];
                // cout << w.count()
                if(w.count(i - curr) and w.count(curr))
                    if(i - curr != curr)
                        cnt++, w.erase(w.find(curr)), w.erase(w.find(i - curr));
                    else    
                        if(w.count(curr) > 1)
                            cnt++, w.erase(w.find(curr)), w.erase(w.find(curr));
            }
            w.clear();
            for(auto p : c)
                w.insert(p);
            maxima = max(maxima, cnt);
            
        }
        cout << maxima << endl;
    }

}