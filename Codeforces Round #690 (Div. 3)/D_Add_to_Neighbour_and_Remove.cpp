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

int func(vi &I, int summ, int start){

    if(start == sz(I))
            return 1; 
    
    int pt = start;

    int cnt = 1;

    int curr;

    while(pt < sz(I)){

        curr = 0;

        while(pt < sz(I) and curr < summ)
                curr += I[pt], pt++;

        if(curr > summ)
                return -infinity;
        else 
                cnt++;
    }

    if(curr < summ)
            return -infinity;

    return cnt; 
}

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;

        vi I(n);

        l(i, 0, n)
                cin >> I[i];
        
        int compare = 0;

        int minima = infinity;

        for(int i = 0; i < n; i++){
                compare += I[i];
                // func returns connected components cnt

                int op = n - func(I, compare, i + 1);

                minima = min(op, minima);
        }

        cout << minima <<  endl;
    }

}
