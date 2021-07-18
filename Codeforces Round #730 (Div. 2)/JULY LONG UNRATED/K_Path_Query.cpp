#include<bits/stdc++.h>
#define infinity INT32_MAX
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

int min_(int a, int b){
    int ans; 
    a < b ? ans = a : ans = b;
    return ans;
}

void dfs(int node, int parent, int depth, vi &depth_map, vector<vector<pii>> &directions, const vector< vi> &adjacency_list){

    // cout << "debug " << node << endl;

    depth_map[node] = depth; 

    // directions[node] = directions[parent];
    loop(i, 0, sz(directions[parent])) directions[node].push_back(directions[parent][i]);

    if(node != 1 and sz(adjacency_list[node]) == 1){

        return;
    }

    
    if(sz(adjacency_list[node]) == 2 and node != 1){
        // linear chain 
        int child;

        adjacency_list[node][0] == parent ? child = adjacency_list[node][1] : child = adjacency_list[node][0];

        dfs(child, node, depth+1, depth_map, directions, adjacency_list);

    }

    else{

        loop(i, 0, sz(adjacency_list[node])){

            if(adjacency_list[node][i] != parent){

                int child = adjacency_list[node][i];

                directions[child].push_back({node, i});

                dfs(child, node, depth+1, depth_map, directions, adjacency_list);
            }
        }
    }

    return;
}

int32_t main(){
    FIO
    // time complexity = O(nlogn + klogn)
    test_cases_loop{

        int n; cin >> n;

        if(n == 1){
            int q; cin >> q;

            loop(i, 0, q){
                int a; cin >> a; int t; cin >> t;
            }

            cout << "YES" << endl;

            continue;
        }

        vector<vi> adjacency_list(n+1);

        loop(i, 0, n-1)
        {
            int parent, child; cin >> parent >> child;

            adjacency_list[parent].pb(child); adjacency_list[child].pb(parent);
        }

        vector<vector<pii>> directions(1+n);

        directions[0] = {{0, 0}};

        vi depth_map(n+1);

        int q; cin >> q;

        

        dfs(1, 0, 0, depth_map, directions, adjacency_list);

        // loop(i, 1, n+1){
        //     cout << i << space << ":"  << endl;
        //     loop(j, 0, sz(directions[i])){
        //         cout << directions[i][j].first << space << directions[i][j].second << endl;
        //     }
        //     cout << endl;
        // }

        loop(i, 0, q){
            
            int a; cin >> a; 

            // -----------------------------------------
            if(a == 1 or a == 2){                      \
                loop(i, 0, a){int t; cin >> t;}         \   
                cout << "YES" << endl;                      \
                continue;                                       \
            }                                                       \
            // -----------------------------------------

            vector<pii> node_direction_parity(n+1, {-1, -1});

            // multimap<int, int> node_direction_parity;

            bool partition = false; 
            
            bool answer = true;

            int dep_of_partition = -infinity;

            int least_depth = infinity;

            loop(j, 0, a){

                int node; cin >> node;
                
                least_depth = min_(least_depth, depth_map[node]);

                loop(i, 0, sz(directions[node])){

                    int key, val;

                    pii key_val = directions[node][i];

                    key = key_val.first, val = key_val.second;

                    // cout << "debug " << key << space << val << endl;

                    if(node_direction_parity[key].first != -1){

                        if(val != node_direction_parity[key].first and val != node_direction_parity[key].second){
                            
                            // partition spotted;
                            if(!partition){
                                
                                partition = true;

                                dep_of_partition = depth_map[key];

                                node_direction_parity[key].second = val;
                            }

                            else answer = false;
                        }

                    }

                    else{

                        node_direction_parity[key] = {val, -1};
                    }
                }  
            }
            
            if(answer){

                if(least_depth >= dep_of_partition){
                    
                    cout << "YES" << endl;

                }

                else{
                    // cout << "debug " << endl;
                    cout << "NO" << endl;
                }

            }   

            else cout << "NO" << endl;
        }
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

