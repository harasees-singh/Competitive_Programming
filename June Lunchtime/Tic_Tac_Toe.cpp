#include<bits/stdc++.h>
#define infinity 999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
// #define int long long
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
void whatever(int p_, int &alice, unordered_map<int, int> &heirarchy, int m, int k){
    int maxi = -infinity;
            pii p = {p_/m , p_%m};
            int row_low_limit = p.first - k, row_up_limit = p.first;
            int column_low_limit = p.second - k, column_up_limit = p.second;

            loop(i, row_low_limit+1, row_up_limit+1){

                loop(j, column_low_limit+1, column_up_limit+1){

                    int check = heirarchy[(i+1)*m + (j+1)];
                    check > maxi ? maxi = check : maxi = maxi;
                }
            }
            maxi < alice ? alice = maxi : alice = alice;
}
int32_t main(){
    FIO
    test_cases_loop{
        int n, m, k;
        cin >> n >> m >> k;
        // map<pii, int> heirarchy;
        unordered_map<int, int> heirarchy;
        // vector<vi> input(n, vi(m));
        int input[n][m];
        int parity = 1;
        loop(i, 0, n*m){
            pii temp;
            cin >> temp.first >> temp.second;
            // heirarchy[{temp.first - 1, temp.second - 1}] = i;
            heirarchy[temp.first*m + temp.second] = i;
            input[temp.first - 1][temp.second -1] = parity; parity = parity^1;
        }
        // loop(i, 0, n){
        //     loop(j, 0, m){
        //         cout << input[i][j] << space;
        //     }
        //     cout << endl;
        // }
        loop(i, 0, n){
            loop(j, 0, m){
                int store = input[i][j];
                if(j-1 >= 0) input[i][j] = input[i][j-1] + input[i][j];
                if(i-1 >= 0) input[i][j] = input[i-1][j] + input[i][j];
                if(i And j) input[i][j] -= input[i-1][j-1];
            }
        }
        
        // loop(i, 1, n){
        //     loop(j, 0, m){
        //         input[i][j] = input[i-1][j] + input[i][j];
        //     }
        // }
        
        
        // loop(i, 0, n){
        //     loop(j, 0, m){
        //         cout << input[i][j] << space;
        //     }
        //     cout << endl;
        // }
        int alice = infinity;
        int bob = infinity;
        // unordered_set<int> check_for_alice, check_for_bob;
        loop(i, k-1, n){
            loop(j, k-1, m){
                int val = input[i][j];
                
                if(i-k>=0) val -= input[i-k][j];
                if(j-k>=0) val -= input[i][j-k];
                if(i-k>=0 And j-k>=0) val += input[i-k][j-k];

                if(val == k*k) whatever(i*m + j, alice, heirarchy, m, k);
                if(val == 0) whatever(i*m + j, bob, heirarchy, m, k);
            }
        }
        
        string winner;
        if(alice == infinity And bob == infinity){ cout << "Draw" << endl; continue;}
        bob < alice ? winner = "Bob" : winner = "Alice";
        cout << winner << endl;
    }
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

