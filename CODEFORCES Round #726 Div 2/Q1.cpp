#include<bits/stdc++.h>
#define infinity 999999999999999999
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
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
MOD_DEFINE
int __gcd(int a, int b){
    if(b==0) return a;
    return __gcd(b, a%b);
}
int32_t main(){
    FIO
    test_cases_loop{
        int n; cin >> n;
        vi input;
        float sum = 0;
        loop(i, 0, n){
            int temp; cin >> temp;
            input.pb(temp);
            sum += temp;
        }
        float mean = sum/n;
        if(mean >= 1){
            cout << (int)sum - n << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    return 0;
}