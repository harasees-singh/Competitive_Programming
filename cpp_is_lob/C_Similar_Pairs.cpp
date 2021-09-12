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
#define pb(n)                           push_back(n)
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

int32_t main(){
    FIO 

    test_cases_loop{

        int n; cin>> n;

        int odd = 0, even = 0;

        vi arr(n); l(i, 0, n) {
            
            cin >> arr[i];

            int t = arr[i]%2;

            odd += t; even += !t;
            
        }

        sort(all(arr));

        bool close = false;

        l(i, 0, n - 1){

            if(arr[i] == arr[i + 1] - 1) close = true;
        }

        if((odd%2) ^ (even%2) == 0){

            if(odd%2){ 
                
                if(close)
                    cout << "YES" << endl;

                else cout << "NO" << endl;
            }
            else cout << "YES" << endl;
        } 

        else cout << "NO" << endl;
    }

    return 0;
}
