#include <iostream>
#define int long long
#define MOD 1000000007
using namespace std;
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2)%MOD * power(x, y / 2)%MOD;
    else
        return x * power(x, y / 2)%MOD * power(x, y / 2)%MOD;
}
int32_t main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int a = power(2, n)%MOD -1;
	    cout << power(a, m)%MOD << endl;
	}
	return 0;
}
