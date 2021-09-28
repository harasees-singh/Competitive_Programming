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

        vector<vi> I(n, vi(3));

        l(i, 0, n){

            int a, b ; cin >> a >> b;

            I[i][0] = max(a, b), I[i][1] = min(a, b);

            I[i][2] = i + 1;
        }

        sort(all(I));

        // sorted acc to heights

        vector<int> ans(n);

        int minwidth = infinity;

        int index = I[0][2];

        int pt = 0;

        while(pt < n){

            int curr = I[pt][0];

            int blockminima = infinity;

            int indexblock = pt;

            while(pt < n and curr == I[pt][0]){

                if(I[pt][1] < blockminima)
                        blockminima = I[pt][1], indexblock = I[pt][2];

                if(minwidth < I[pt][1])

                    ans[I[pt][2] - 1] = index;
                else 
                    ans[I[pt][2] - 1] = -1;
                
                pt++;
            }

            if(minwidth > blockminima)
                    index = indexblock, minwidth = blockminima;
        }

        l(i, 0, n)
            cout << (ans[i]) << space; cout << endl;   
    }

}
