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
using namespace std;
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
int max(int a, int b){int answer; a > b ? answer =  a : answer = b; return answer;}

bool good_func(int burgers_required, int saus_required, int cheese_required, int p1, int p2, int p3, int b, int s, int c, int money){
    int cost = max((burgers_required - b)*p1, 0) + max((saus_required - s)*p2, 0) + max((cheese_required - c)*p3, 0);
    if(cost <= money) return 1;
    return 0;
}
int32_t main(){
    FIO
    string recipie; cin >> recipie;
    int burgers_required=0, saus_required=0, cheese_required=0;
    for(auto a:recipie){
        if(a == 'B') burgers_required++;
        if(a == 'S') saus_required++;
        if(a == 'C') cheese_required++;
    }
    int b, s, c;
    cin >> b >> s >> c;
    int burger_cost, sausage_cost, cheese_cost;
    cin >> burger_cost >> sausage_cost >> cheese_cost;
    int money; cin >> money;
    int left = 0; int right = 1e15;         // important : signed int overflow if i choose right something like 1e17 or 1e18;
    while(left <= right){

        int mid = (left + right) >> 1;

        if(good_func(mid*burgers_required, mid*saus_required, mid*cheese_required, burger_cost, sausage_cost, cheese_cost, b, s, c, money)) 
            
            left = mid + 1;
        
        else right = mid - 1;
    }
    cout << right << endl;
    return 0;
}

// ██████████████████████████
// ▌════════════════════════▐
// ▌══▄▄▓█████▓▄═════▄▄▓█▓▄═▐ 
// ▌═▄▓▀▀▀██████▓▄═▄▓█████▓▌▐
// ▌═══════▄▓███████████▓▀▀▓▐ 
// ▌═══▄▓█████████▓████▓▄═══▐
// ▌═▄▓████▓███▓█████████▓▄═▐ 
// ▌▐▓██▓▓▀▀▓▓███████▓▓▀▓█▓▄▐
// ▌▓▀▀════▄▓██▓██████▓▄═▀▓█▐
// ▌══════▓██▓▀═██═▀▓██▓▄══▀▐
// ▌═════▄███▀═▐█▌═══▀▓█▓▌══▐ 
// ▌════▐▓██▓══██▌═════▓▓█══▐
// ▌════▐▓█▓══▐██═══════▀▓▌═▐
// ▌═════▓█▀══██▌════════▀══▐
// ▌══════▀═══██▌═══════════▐ 
// ▌═════════▐██▌═══════════▐
// ▌═════════▐██════════════▐
// ▌═════════███════════════▐
// ▌═════════███════════════▐ 
// ▌════════▐██▌════════════▐
// ▌▓▓▓▓▓▓▓▓▐██▌▓▓▓▓▓▓▓▓▓▓▓▓▐
// ▌▓▓▓▓▓▓▓▓▐██▌▓▓▓▓▓▓▓▓▓▓▓▓▐
// ▌▓▓▓▓▓▄▄██████▄▄▄▓▓▓▓▓▓▓▓▐ 
// ██████████████████████████

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

