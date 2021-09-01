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

    int sum = 0;

    loop(i, 0, n){sum+=input[i]; input[i] = sum;}

    int fall = 0;

    int T= 0;

    loop(i, 0, q){
        int t; 

        cin >> t;

        T+=t;

        fall = (int)(lower_bound(input.begin(), input.end(), T + 1) - input.begin());

        if(fall == n) fall = 0, T=0;

        cout << n - fall << endl;

    }

  return 0;
}
