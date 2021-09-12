#include<bits/stdc++.h>
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

using namespace std;
MOD_DEFINE

bool better(vi &best, vi &competition){

    int cnt = 0; 

    l(i, 0, 5){

        if(best[i] > competition[i]) cnt++;
    }

    return cnt >= 3;
}

int32_t main(){
    FIO 

    test_cases_loop{

        int n; cin >> n;
        
        vector<vector<int>> I(n, vector<int>(5));

        l(i, 0, n)

            l(j, 0, 5)

                cin >> I[i][j];

        int best = 0;

        l(i, 1, n){

            if(better(I[best], I[i])) best = i;
        }

        bool ok = true;

        l(i, 0, n){

            if(better(I[best], I[i])) ok = false;
        }

        cout << (ok ? best + 1 : -1) << endl;
    }
    return 0;
}
