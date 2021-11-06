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

int raise(int n){
    
    int i = 1;

    l(j, 0, n)
                i*=10;

        return i;
}

int32_t main(){
    FIO
        
    w(t){
            int n, k; cin >> n >> k;

            k++;

            vi I(n);

            l(i, 0, n)
                    cin >> I[i];
                    
            int amnt = 0;

            int c =  0;

            for(int j = 0; j < n; j++){
                
                    int temp = raise(I[j])*k;

                    if(j < n - 1){

                                int plus = raise(I[j + 1]) - raise(I[j]);

                                int notes = plus/raise(I[j]);

                                notes = min(notes, k);

                                amnt += notes*raise(I[j]);

                                k -= notes;
                        
                    }    

                    else{
                            amnt += temp; k = 0;
                    }   

                    if(!k)
                            break;
            }

            cout << amnt << endl;
    }
    return 0;

}