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

    test_cases_loop{

        int n; cin >> n;

        int mini = infinity;

        vi input; loop(i, 0, n){int t; cin >> t; input.pb(t); mini = min(mini, t);};

        vi copy(input);

        sort(all(copy));

        bool parity = true;

        loop(i, 0, n){

            int f = input[i]; int s = copy[i];

            if(f != s and f%mini != 0){parity = false; break;}
        }

        cout << (parity ? "YES" : "NO") << endl;
    }
  
  return 0;
}
