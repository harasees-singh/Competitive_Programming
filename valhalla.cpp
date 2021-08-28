#include<bits/stdc++.h>
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define cout std::cout
#define cin std::cin
#define safe_unordered_map(int, T) unordered_map<int, T, custom_hash>

using namespace std;
MOD_DEFINE
int32_t main(){
  FIO

    int n, q; cin >> n >> q;

    vi input;

    loop(i, 0, n){int t; cin >> t; input.pb(t);}

    vi copy(input);
    int sum = 0;

    loop(i, 0, n){input[i] = sum + input[i]; sum+=input[i];}

    int fall = 0;

    int T= 0;

    loop(i, 0, q){
        int t; 
        if(fall == n){
            fall=0; 
        
            // loop(i, 0, n){input[i]=copy[i];}

            T=0;
        
        }
        
        cin >> t;
        T+=t;


        fall = (int)(lower_bound(input.begin()+fall, input.end(), T+1) - input.begin());

        // input[fall]-=t;

        cout << n - fall << endl;

        // curr += fall;
    }

  return 0;
}
