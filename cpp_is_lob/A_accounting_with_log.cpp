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

    int a, b, n; cin >> a >> b >> n;

    int a__ = a, b__ = b;

    a = abs(a); b = abs(b);

    if(a == 0 and b != 0) cout << "No solution" << endl;

    else if(b == 0) cout << 0 << endl;

    else{
        int val = b/a;

        if((b%a)){

            cout << "No solution" << endl;
        }
        else{

            if(n == 1){ cout << b__/a__ << endl; return 0;}

            double answer = (log10(val))/(double)n;

            answer = round(pow(10, answer));

            if(a__<0 ^ b__<0)answer=-answer;

            if((int)round(pow(answer, n)) == b__/a__) cout << answer << endl; else cout << "No solution" << endl;
        }
    }
    return 0;
}
