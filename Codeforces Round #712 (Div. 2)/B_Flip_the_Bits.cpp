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

int32_t main(){
    FIO

    test_cases_loop{
        int n; cin >> n;

        string a, b; cin >> a >> b;

        // vector<pii> A;

        if(a == b){
            cout << "YES" << endl;
            continue;
        }

        while(a[sz(a) - 1] == b[sz(b) - 1])
                a.pop_back(), b.pop_back();
        int pt = 0; 

        n = sz(a);

        bool equal;

        pii temp = {0, 0};

        bool ok = true;

        while(pt < n){

                temp = {0, 0};

                if(a[pt] == b[pt])
                        equal = true;
                
                while(pt < n and a[pt] == b[pt])
                        temp.ff += (a[pt] == '0'), 
                        temp.ss += (a[pt] == '1'), 
                        pt++;
                
                if(temp.ff != temp.ss){

                        // cout << temp.ff << space << temp.ss << endl;
                        ok = false; break;
                }

                // cout << temp.ff << space << temp.ss << endl;

                temp = {0, 0};

                while(pt < n and a[pt] != b[pt])
                        temp.ff += (a[pt] == '0'), 
                        temp.ss += (a[pt] == '1'),
                        pt++;
                
                if(temp.ff != temp.ss){
                        ok = false; break;
                }
                // cout << temp.ff << space << temp.ss << endl;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

}
