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

    // if 0 is in the middle and only in the middle 11011

    // else simple hai 

    // if all ones simple hai

    test_cases_loop{

        int n; cin >> n;

        string s; cin >> s;

        bool hogya = false;
        int count_zero = 0;

        int zero_index = 0;

        for(int i = 0; i < n;  i++){

            char p = s[i];

            zero_index = i;

            count_zero += p=='0'; 

        }

        if(!count_zero) {
            
            if(n%2==0)
                cout << 1 << space << n << space << n/2 + 1 << space << n << endl;

            else 

                cout << 1 << space << ceil(n/2.0) << space << ceil(n/2.0) << space << n << endl;
            
        }

        else if(count_zero == 1 and s[n/2] == '0' and n%2){ 
            
            // 11011
            
                cout << 1 << space << n << space << (int)(ceil(n/2.0)) << space << n << endl;

        }

        // 1011 or 101101....

        // find nearest zero from back or front 

        // 1101 or 11101 


        else

        {
            
            
            for(int i = 0; i < ceil(n/2.0); i++){

                if(s[i] == '0'){

                    cout << i + 1 << space << n << space << i + 2 << space << n << endl; hogya = true; break;
                }
            }
        

            if(!hogya)

                for(int i = n -1 ; i >= ceil(n/2.0); i--){

                    if(s[i] == '0'){ cout << 1 << space << i + 1  << space << 1 << space << i << endl; break;}
                }
                
        }
    }

    return 0;
}
