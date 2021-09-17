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

        string s; cin>>s;

        string process;

        int i = 0; 

        while(i < sz(s)){

            char curr = s[i];

            process.pb(curr);

            i++;

            while(i < sz(s) and s[i] == curr){

                i++;
            }
        }

        if(sz(process) > 3) cout << 2 << endl;

        else if(sz(process) == 3) cout << (process[0] == '1' ? 1 : 2) << endl; 

        else if (sz(process) == 2) cout << 1 << endl;

        else cout << (process[0] == '0' ? 1 : 0) << endl;
    }

    return 0;
}
