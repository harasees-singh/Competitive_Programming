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
#define test_cases_loop                 int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

bool equal(int a, int b){

    if(a == b) return true;
    // if a = 28, b = 29 it will return true and vice versa
    if(a < 30 and b < 30) return true;

    return false;    
}

int32_t main(){
    FIO
    int standardchart[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n; cin >> n;
    int months[n];

    int cnt_29 = 0;

    for(int i = 0; i < n; i++){
            cin >> months[i];
            cnt_29 += (months[i] == 29);
    }

    if(cnt_29 > 1){
            cout << "No" << endl; return 0;
    }    

    bool match = true;
    for(int i = 0; i < 12; i++){
            match = true;
            for(int j = 0; j < n; j++)
                    match = match and equal(months[j], standardchart[(i + j)%12]);

            if(match) break;
    }
    cout << (match ? "Yes" : "No") << endl;
}
