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

int count_characters(string &s, char a){

    int ans = 0;

    for(auto p : s) if(p == a) ans++;

    return ans;
}

bool aaa_compare(string &a, string &b){

    int count_1 = 0, count_2 = 0;

    count_1 = 2*count_characters(a, 'a'); count_2 = 2*count_characters(b, 'a');

    count_1 -= sz(a); count_2 -= sz(b);

    return count_1 > count_2;
}


bool bbb_compare(string &a, string &b){

    int count_1 = 0, count_2 = 0;

    count_1 = 2*count_characters(a, 'b'); count_2 = 2*count_characters(b, 'b');

    count_1 -= sz(a); count_2 -= sz(b);

    return count_1 > count_2;
}


bool ccc_compare(string &a, string &b){

    int count_1 = 0, count_2 = 0;

    count_1 = 2*count_characters(a, 'c'); count_2 = 2*count_characters(b, 'c');

    count_1 -= sz(a); count_2 -= sz(b);

    return count_1 > count_2;
}


bool ddd_compare(string &a, string &b){

    int count_1 = 0, count_2 = 0;

    count_1 = 2*count_characters(a, 'd'); count_2 = 2*count_characters(b, 'd');

    count_1 -= sz(a); count_2 -= sz(b);

    // if(count_1 == count_2) return sz(a) < sz(b);

    return count_1 > count_2;
}


bool eee_compare(string &a, string &b){

    int count_1 = 0, count_2 = 0;

    count_1 = 2*count_characters(a, 'e'); count_2 = 2*count_characters(b, 'e');

    count_1 -= sz(a); count_2 -= sz(b);

    return count_1 > count_2;
}

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;

        vector<string> input;

        loop(i, 0, n){

            string t; cin >> t;

            input.pb(t);
        }

        int aginlo = 0, nona = 0;

        
        sort(all(input), aaa_compare);
        

        int maxima = 0;



        int ans = n;

        aginlo = 0; nona = 0;

        

        loop(i, 0, n){
            
            int temp = count_characters(input[i], 'a');

            aginlo += temp;

            nona += sz(input[i]) - temp;

            if(aginlo <= nona) {ans = i; break;}
        }

        maxima = max(ans, maxima);

        //---------------------------

        ans = n;

        aginlo = 0; nona = 0;

        sort(all(input), bbb_compare);

        

        loop(i, 0, n){
            
            int temp = count_characters(input[i], 'b');

            aginlo += temp;

            nona += sz(input[i]) - temp;

            if(aginlo <= nona) {ans = i; break;}
        }

        maxima = max(ans, maxima);


        ans = n;

        aginlo = 0; nona = 0;

        sort(all(input), ccc_compare);

        // for(auto p : input) cout << p << space;

        loop(i, 0, n){
            
            int temp = count_characters(input[i], 'c');

            aginlo += temp;

            nona += sz(input[i]) - temp;

            if(aginlo <= nona) {ans = i; break;}
        }

        maxima = max(ans, maxima);



        ans = n;

        aginlo = 0; nona = 0;

        sort(all(input), ddd_compare);

        // for(auto p : input) cout << p << space;

        loop(i, 0, n){
            
            int temp = count_characters(input[i], 'd');

            aginlo += temp;

            nona += sz(input[i]) - temp;

            if(aginlo <= nona) {ans = i; break;}
        }

        maxima = max(ans, maxima);

        ans = n;

        aginlo = 0; nona = 0;

        sort(all(input), eee_compare);

        loop(i, 0, n){
            
            int temp = count_characters(input[i], 'e');

            aginlo += temp;

            nona += sz(input[i]) - temp;

            if(aginlo <= nona) {ans = i; break;}
        }

        maxima = max(ans, maxima);

        cout << maxima << endl;
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

