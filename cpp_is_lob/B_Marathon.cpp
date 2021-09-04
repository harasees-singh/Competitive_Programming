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
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define cout std::cout
#define double long double
#define cin std::cin
#define safe_unordered_map(int, T) unordered_map<int, T, custom_hash>
#define fps(x,y)         fixed<<setprecision(y)<<x


using namespace std;
MOD_DEFINE
typedef long long ll;
template<typename T>
void print(array<T,2> &arr);
template<typename T>
void print(vector<T> &v);
template<typename T>
void print(deque<T> &v); 
template<typename T>
T _gcd(T a, T b);
template<typename T>
vector<T> sieve(T n);
template<typename T>
T power(T x, T y, ll p = LLONG_MAX);
ll nxt();
// // Returns n^(-1) mod p 
template<typename T>
T modInverse(T n, T p);
ll gcd(vector<int> &diff);
bool isPowerof2(ll x);
vector<int> divisors(ll n){
	vector<int> ans;
	for(int i = 2;i<=sqrt(n);i++){
		if(n % i ==0){
			ans.pb(i);
			if(n/i != i) ans.pb(n/i);
		}
	}
	ans.pb(1);
	return ans;
}
int binomial_cofficient(int n, int r){
    
    if(r == 0) return 1;
    return n*binomial_cofficient(n-1, r-1)/r;
}
int power_modulus(int x, int y)
{
    if (y == 0)
        return 1;

    else if (y % 2 == 0)
    {
        int chloe = power_modulus(x, y/2);
        
        return (chloe*chloe)%MOD;
    }
    else
    {
        int mermaid = power_modulus(x, y/2);
        
        return (((mermaid*mermaid)%MOD)*x)%MOD;
    }

}
int pow_good(int a, int b){
    
    return (int)round(pow(a, b));
}
struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        x += 0x9e3779b97f4a7c15;
    
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
    
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    
        return splitmix64(x + FIXED_RANDOM);
    }
};
// ░░░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░░░░░
// ░░░░░▄▄▄▄█▀▀▀░░░░░░░░░░░░▀▀██░░░░░░░░░░░
// ░░▄███▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄░░░░░░░
// ▄▀▀░█░░░░▀█▄▀▄▀██████░▀█▄▀▄▀████▀░░░░░░░
// █░░░█░░░░░░▀█▄█▄███▀░░░░▀▀▀▀▀▀▀░▀▀▄░░░░░
// █░░░█░▄▄▄░░░░░░░░░░░░░░░░░░░░░▀▀░░░█░░░░
// █░░░▀█░░█░░░░▄░░░░▄░░░░░▀███▀░░░░░░░█░░░
// █░░░░█░░▀▄░░░░░░▄░░░░░░░░░█░░░░░░░░█▀▄░░
// ░▀▄▄▀░░░░░▀▀▄▄▄░░░░░░░▄▄▄▀░▀▄▄▄▄▄▀▀░░█░░
// ░█▄░░░░░░░░░░░░▀▀▀▀▀▀▀░░░░░░░░░░░░░░█░░░
// ░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄██░░░░
// ░░▀█▄░░░░░░░░░░░░░░░░░░░░░░░░░▄▀▀░░░▀█░░
// █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
// █░░█▀▄ █▀▀ █▀█ █░░░░█░▄░█ █ ▀█▀ █░█░░█ ▀█▀░█
// █░░█░█ █▀▀ █▀█ █░░░░▀▄▀▄▀ █ ░█░ █▀█░░█ ░█░░█
// █░░▀▀░ ▀▀▀ ▀░▀ ▀▀▀░░░▀░▀░ ▀ ░▀░ ▀░▀░░▀ ░▀░░█
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

int32_t main(){
    FIO

    double a, d; cin >> a >> d;

    double d__ = d;

    int n; cin >> n;

    vector<double> querylist;

    double pushhhh = -4*a;

    while(pushhhh <= 1e6) querylist.push_back(pushhhh + 4*a), pushhhh += 4*a; 

    // print<double>(querylist);
    auto ptr = lower_bound(all(querylist), d);
    
    if(*ptr > d) {ptr--;} 

    double x = d - *ptr;

    double std_addition = *ptr;

    double propermultiple = *ptr;

    loop(i, 0, n){

        while(propermultiple + 4*a <= d) propermultiple += 4*a;

        // x = d - propermultiple;

        x = d - ((int)(d/(4*a)))*(4*a);

        // double x = d - *ptr; //cout << "debug " << x << endl;

        // cout << x << " debug "<< endl;

        double X, Y;

        if(x >= 3*a) X=0, Y = 4*a - x ;

        else if(x > a and x < 2*a) X = a, Y = x - a;

        else if(x >= 2*a and x < 3*a) X = a - x + 2*a, Y = a;

        else X = x, Y = 0;

        // fixed<<setprecision(4)<<X;
        // cout << X << space << Y << endl;
        cout << fps(X,4) << space << fps(Y,4) << endl;

        d += d__;

        propermultiple += std_addition;
        // cout << "d " << d__ << endl;
    }                                                                 

    return 0;
}

//          ▄              ▄    
//         ▌▒█           ▄▀▒▌   
//         ▌▒▒█        ▄▀▒▒▒▐   
//        ▐▄█▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐   
//      ▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐   
//    ▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌   
//   ▐▒▒▒▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▌  
//   ▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐  
//  ▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌ 
//  ▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌ 
// ▌▒▒▒▄██▄▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▐ 
// ▐▒▒▐▄█▄█▌▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▒▒▌
// ▐▒▒▐▀▐▀▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▐ 
//  ▌▒▒▀▄▄▄▄▄▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▒▌ 
//  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▒▄▒▒▐  
//   ▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▄▒▒▒▒▌  
//     ▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀   
//       ▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀     
//          ▀▀▀▀▀▀▀▀▀▀▀▀       

template<typename T>
T power(T x, T y, ll p) { 
    T res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    // cout <<"x= "<< x << endl;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    // cout << "res" << res << endl;
    return res; 
} 
 
template<typename T>
vector<T> sieve(T n){
	vector<int> prime(n+1, 1);
	for(int i = 2; i*i<=n; i++){
		if(prime[i]){
			for(int j = 2; j*i<=n; j++){
				prime[i*j] = 0;
			}
		}
	}
	vector<T> ans;
	for(int i = 2; i<=n;i++){
		if(prime[i]) ans.pb(i);
	}
	return prime;
}
template<typename T>
T _gcd(T a, T b){
	T temp1 = max(a,b), temp2 = min(a,b);
	a = temp1, b = temp2;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a%b ==0) return b;
	return _gcd(b, a%b);
}
 
template<typename T>
void print(array<T,2> &arr){
	cout << arr[0] << " " << arr[1] << endl;
}
 
template<typename T>
void print(vector<T> &v){
	for(T x: v) cout << x << " ";
	cout << endl;
}
 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
 
template<typename T>
void print(deque<T> &v){
	for(auto x: v) cout << x << " ";
	cout << endl;
}
 
ll nxt(){
    ll x;
    cin >> x;
    return x;
}
 
bool isPowerof2(ll x){
	return !(x && (x & (x-1)));
}

