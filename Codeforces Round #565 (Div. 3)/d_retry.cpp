// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

vi greatest_divisor(2750136);

template<typename T>
vector<T> sieve(T n){
	vector<int> prime(n+1, 1);
	for(int i = 2; i*i<=n; i++){
		if(prime[i]){
			for(int j = 2; j*i<=n; j++){
                if(prime[i*j]){
                    greatest_divisor[i*j] = j;
                }
				prime[i*j] = 0;
			}
		}
	}
	vector<T> ans;
	for(int i = 2; i<=n;i++){
		if(prime[i]) ans.pb(i);
	}
	return ans;
}
vi input(2750136, 0);
vi Primes;
int32_t main(){
        FIO 

        int n; cin >> n;

        Primes = sieve(2750136ll);
        vi Primes_reverse(2750136);
        int pt = 1;
        for(auto p : Primes) Primes_reverse[p] = pt++;

        for(int i = 0; i < 2*n; i++){
            int t; cin >> t;

            input[t]++;
        }
        ofstream out;
        out.open("out.txt");
        for(int i = 2750135; i >= 0; i--){
            // out << input[i] << endl; 
            assert(input[i] >= 0);
            if(!input[i]) continue;

            if(Primes_reverse[i]){
                input[Primes_reverse[i]] -= input[i];
                l(j, 0, input[i]) cout << Primes_reverse[i] << ' ';
            }
            else{
                int g = greatest_divisor[i];

                input[g] -= input[i];

                l(j, 0, input[i]) cout << i << ' ';
            }
        }
        out.close();
        cout << endl;

        return 0;
}
