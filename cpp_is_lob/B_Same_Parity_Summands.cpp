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

        int n, k; cin >> n >> k;

        if(n%2 and k%2==0) cout << "NO" << endl;

        else if(n%2){

            // now k is odd;

            // k - 1 is even

            if(k > n) cout << "NO" << endl;

            else{
                cout << "YES" << endl;

                l(i, 0, k - 1) cout << 1 << space; cout << n - (k - 1) << endl;
            }
        }

        else{

            // now n is even;

            if(k%2){

                if(2*k > n)  cout << "NO" << endl;

                else{

                    cout << "YES" << endl;

                    l(i, 0, k - 1) cout << 2 << space; cout << n - 2*(k - 1) << endl;
                }
            }
            else{
                if(k > n) cout << "NO" << endl;

                else{
                    cout << "YES" << endl;

                    l(i, 0, k - 1) cout << 1 << space; cout << n - (k - 1) << endl;
                }
                
            }
        }
    }

    return 0;
}
