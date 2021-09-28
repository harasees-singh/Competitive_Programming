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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

bool comp(pii &a, pii &b){return ((double)a.ff)/a.ss > ((double)b.ff)/b.ss;}

int32_t main(){
    FIO
    test_cases_loop{

        int n, m; cin >> n >> m;

        vector<pii> I(n);

        // vector<pii> S(n)

        vi ones;

        vi twos;

        int summ = 0;

        l(i, 0, n){
                cin >> I[i].ff;
                summ += I[i].ff;
        }
        l(i, 0, n)
                cin >> I[i].ss;
        // sort(all(I), comp);

        for(int i = 0; i < n; i++)
                if(I[i].ss == 1)
                        ones.pb(I[i].ff);
                else    
                        twos.pb(I[i].ff);

        sort(all(ones), greater<int>()), sort(all(twos), greater<int>());

        l(i, 1, sz(ones))
                ones[i] += ones[i - 1];
        l(i, 1, sz(twos))
                twos[i] += twos[i - 1];

        if(summ < m){
                cout << -1 << endl; continue;
        }

        int minima = infinity;

        int pt2 = sz(twos) - 1;

        l(i, 0, sz(ones)){

                if(ones[i] >= m)
                        minima = min(minima, i + 1);
                else{
                        while(pt2 >= 1 and ones[i] + twos[pt2 - 1] >= m)
                                pt2--;
                
                        if(pt2 >= 0 and twos[pt2] + ones[i] >= m)
                                minima = min(minima, i + 1 + (pt2 + 1)*2);
                }
        }
        int alltwos = lower_bound(all(twos), m) - twos.begin() + 1;

        if(alltwos == sz(twos) + 1)
                alltwos = infinity;

        cout << min(minima, 2*alltwos) << endl;
                
    }
    return 0;
}
