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

        int k, n, m;

        cin >> k >> n >> m;

        vi a, b;

        loop(i, 0, n){int t; cin >> t; a.pb(t);}

        loop(i, 0, m){int t; cin >> t; b.pb(t);}

        a.pb(infinity); b.pb(infinity);

        vi answer;

        int i = 0, j = 0;

        while(true){

            // if(min(a[i], b[j]) > k) break;
            // cout << i << space << j << endl;

            while(a[i] == 0) answer.pb(0),k++,i++; while(b[j] == 0) answer.pb(0),k++,j++;

            if(a[i] < b[j]){

                if(a[i] > k) break;

                else answer.pb(a[i]), i++;
            }

            else{

                if(b[j] > k) break;

                else answer.pb(b[j]), j++;
            }
        }

        if(i == n and j == m){

            for(auto p : answer) cout << p << space;

            cout << endl;
        }

        else cout << -1 << endl;
    }

  return 0;
}
