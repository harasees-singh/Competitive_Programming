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

int32_t main(){
    FIO

    w(t){

	    int n; cin >> n;

		int spit = 0;

	    vi I(n);
	    for(auto &p : I)
			cin >> p;
		
		sort(all(I));

		bool ok = 0;
		
		for(int i = 0; i < n; i++){


				mii div;

				int t = I[i];
				for(int j = i; j < n; j++){

						I[j] -= t;
				}
				
				// for(int j = i; j < n; j++)	cout << I[j] << space; cout << endl;

				for(int it = i; it < n; it++){	

						int p = I[it];
						
						for(int k = 1; k < (int)sqrt(p) + 1; k++){
								if(p%k == 0){
										div[k]++, div[p/k]++;

										if(p/k == k)
												div[k]--;
								}
								
						}
				}

				int cnt = n/2 - count(I.begin() + i, I.end(), 0ll);

				if(cnt <= 0){
						cout << -1 << endl; ok = 1; break;
				}
				// cout << "COunt " << cnt << " map " << div[10] << endl;

				for(auto p : div)

						if(p.ss >= cnt)
								spit = max(spit, p.ff);


		}
		if(!ok)
				cout << spit << endl;
	}

		
}
