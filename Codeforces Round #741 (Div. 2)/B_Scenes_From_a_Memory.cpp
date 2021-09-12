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

bool isPrime(int n){

    bool answer = true;

    if(n == 1) return false;

    if(n == 2) return true;

    if(n%2 == 0) return false;

    for(int i = 3; i <= sqrt(n); i+=2){

        if(n%i == 0) return false;
    }

    return true;
}

int32_t main(){
    FIO 

    test_cases_loop{

        int n; cin >> n;

        string s; cin >> s;

        bool hogya = false;

        int minima = infinity;

        int answer;

        for(int i = 0; i < n ; i++){

            if(!isPrime(s[i] - '0')) {cout << 1 << endl << s[i] << endl; hogya = true; break;}

            // if (hogya) break;

            for(int j = i + 1; j < n ; j++){

                string temp; temp += s[i]; temp += s[j];
                
                int check = stoi(temp);

                if(!isPrime(check)) {
                    // hogya = true;

                    // cout << 2 << endl << check << endl; break;

                    answer = check;
                }
            }
        }

        if(!hogya) cout << 2 << endl << answer << endl;
    }

    return 0;
}
