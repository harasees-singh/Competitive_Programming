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
string bitstring(int a){
        string ret = "";

        while(a){
                ret = (char)((a % 2) + '0') + ret; a/=2;
        }
        return ret;
}
int32_t main(){
        FIO 

        w(t){
                int a, s; cin >> a >> s;

                string And = bitstring(a);

                string Sum = bitstring(s);

                int len = max(sz(And), sz(Sum));

                while(sz(Sum) < len) Sum = '0' + Sum;
                while(sz(And) < len) And = '0' + And;

                int carry = 0;  
                bool ok = 1;
                // cout << And << endl << Sum << endl;
                for(int i = len - 1; i >= 0; i--){
                        if(And[i] == '1'){
                                // both bits one
                                if(carry){
                                        ok = ok and(Sum[i] == '1');
                                }
                                else{
                                        ok = ok and (Sum[i] == '0');
                                        carry = 1;
                                }
                        }       
                        else{
                                if(Sum[i] == '0');

                                else{
                                        if(carry) carry = 0;
                                }
                        }
                }
                cout << (ok and (not carry) ? "Yes" : "No") << endl;
        }

        return 0;
}
