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

bool Ascent(vi &arr){

    int mini = infinity;

    for(auto p : arr){
        if(p < mini)
            mini = p;

        if(p > mini) return true;
    }
    return false;
}

int32_t main(){
    FIO

    int n; cin >> n;

    vector<int> Maxx;

    vector<int> Minn;

    int reject = 0;

    for(int i = 0; i < n; i++){
        int t; cin >> t;

        vi temp(t); 

        l(j, 0, t)
                cin >> temp[j];
        
        if(!Ascent(temp))
                Maxx.push_back(*max_element(all(temp))), 
                Minn.push_back(*min_element(all(temp)));
    
    }

    sort(all(Maxx));
    sort(all(Minn));

    int pt = 0;

    for(auto p : Minn){
            int find = p;

            while(pt < Maxx.size() and Maxx[pt] <= find)
                    pt++;
            
            reject += pt;
    }

    cout << n*n - reject << endl;

}
