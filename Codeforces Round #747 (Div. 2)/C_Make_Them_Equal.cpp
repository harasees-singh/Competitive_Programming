#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
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
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE
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
	return ans;
}
int32_t main(){
    FIO

    w(t){

            int n; cin >> n; char t; cin >> t;

            string s; cin >> s;

            if(n%2){

                    bool ok = true;

                    for(auto p : s)
                            ok = ok & (p == t);
                    
                    if(ok)
                            cout << 0 << endl;
                    else{
                            bool odd = false;
                            bool even = false;

                            for(int i = 1; i <= n; i += 2){

                                    odd = odd or (s[i - 1] != t);
                            }
                            for(int i = 2; i < n; i += 2)
                                    even = even or (s[i - 1] != t);

                            if(odd and !even)
                                    cout << 1 << endl << 2 << endl;
                            else{
                                    if(s[n - 1] != t)
                                            cout << 2 << endl << 2 << space << n << endl;
                                    
                                    else
                                            cout << 1 << endl << n << endl;
                            }

                    }

            }
            else{

                    bool ok = true;

                    for(auto p : s)
                            ok = ok & (p == t);
                    
                    if(ok)
                            cout << 0 << endl;
                    else{
                            bool odd = false;
                            bool even = false;

                            for(int i = 1; i <= n; i += 2){

                                    odd = odd or (s[i - 1] != t);
                            }
                            for(int i = 2; i < n; i += 2)
                                    even = even or (s[i - 1] != t);
                            
                            if(odd and !even){

                                    cout << 1 << endl << 2 << endl;
                            }
                            if(!odd and even){
                                    if(s[n - 1] != t)
                                            cout << 
                            }
                    }


            }


    }

}
