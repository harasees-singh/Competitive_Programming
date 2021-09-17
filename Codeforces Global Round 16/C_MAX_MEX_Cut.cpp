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

int32_t main(){
    FIO 

    test_cases_loop{

        int n; cin >> n;

        string a, b; cin >> a >> b;

        int i = 0; 

        int cnt = 0;

        while(i < n){

            // cout << i << space << cnt << endl;

            if(a[i] == b[i]){

                if(i < n - 1 and a[i + 1] == b[i + 1] and a[i + 1] != a[i]) cnt += 2, i ++;

                else{ cnt += (a[i] == '0');}
            }

            else cnt +=2; 

            i++;
        }

        cout << cnt << endl;
    }

    return 0;
}
