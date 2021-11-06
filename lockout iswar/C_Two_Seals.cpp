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
#define float                           long double
#define double                          long double
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int32_t main(){
    FIO

    int n, a, b; cin >> n >> a >> b;

//     if(a > b){
//             swap(a, b);
//     }

    vpii I(n);

    l(i, 0, n){
	    int l, b; cin >> l >> b;

		// if(l > b) swap(l, b);

	    I[i] = make_pair(l, b);
    }

    int maxi = 0;

    l(i, 0, n){

	    l(j, i + 1, n){

		    if((I[i].ff + I[j].ff <= a and I[i].ss <= b and I[j].ss <= b) or (I[i].ss + I[j].ss <= b and I[i].ff <= a and I[j].ff <= a)) 

				maxi = max(maxi, I[i].ff*I[i].ss + I[j].ff*I[j].ss);

            swap(I[j].ff, I[j].ss);

            if((I[i].ff + I[j].ff <= a and I[i].ss <= b and I[j].ss <= b) or (I[i].ss + I[j].ss <= b and I[i].ff <= a and I[j].ff <= a)) 

				maxi = max(maxi, I[i].ff*I[i].ss + I[j].ff*I[j].ss);
            
            swap(I[j].ff, I[j].ss); swap(I[i].ff, I[i].ss);

            if((I[i].ff + I[j].ff <= a and I[i].ss <= b and I[j].ss <= b) or (I[i].ss + I[j].ss <= b and I[i].ff <= a and I[j].ff <= a)) 

				maxi = max(maxi, I[i].ff*I[i].ss + I[j].ff*I[j].ss);
            
            swap(I[j].ff, I[j].ss);

            if((I[i].ff + I[j].ff <= a and I[i].ss <= b and I[j].ss <= b) or (I[i].ss + I[j].ss <= b and I[i].ff <= a and I[j].ff <= a)) 

				maxi = max(maxi, I[i].ff*I[i].ss + I[j].ff*I[j].ss);
	    }
    }
    cout << maxi << endl;

}
