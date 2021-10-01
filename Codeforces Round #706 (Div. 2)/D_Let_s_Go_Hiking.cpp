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

    int n; cin >> n;

    vi I(n); 

    l(i, 0, n)
        cin >> I[i];

    vector<pii> slopes;

    bool up = true;
    int cnt = 1;

    l(i, 0, n - 1){
        if(up)
            if(I[i + 1] > I[i])
                cnt++;
            else    
                up = false, slopes.push_back({cnt, 1}), cnt = 2;
        else  
            if(I[i + 1] < I[i])
                cnt++;
            else 
                up = true, slopes.push_back({cnt, 0}), cnt = 2;  

    }

    slopes.push_back({cnt, up});

    int maxHILL = 0;

    for(auto p : slopes)
            if(p.ff > maxHILL)
                    maxHILL = p.ff;

    cnt = 0;

    int pos = -1;

    for(int i = 0; i < sz(slopes); i++)
            if(slopes[i].ff == maxHILL)
                    pos = i,
                    cnt ++;

    if(cnt > 2)
            cout << 0 << endl;

        
    else if(cnt == 1){
            cout << 0 << endl;
    }

    else{
            if(pos and slopes[pos].ss == 0 and slopes[pos - 1].ss == 1)
                    cout << (slopes[pos].ff)%2 << endl;
            else 
                    cout << 0 << endl;
    }

}

