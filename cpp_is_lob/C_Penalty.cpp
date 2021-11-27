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

int f(string &s){
    int a = 0, b = 0;
    l(i, 0, 10){
        a += (i%2==0 and s[i]=='1');
        b += (i%2 and s[i]=='1');
        int rem1 = (10 - i)/2;
        int rem2 = (9 - i)/2;
        if(i%2==0){
            if(b + rem1 < a) return i + 1;
            if(a + rem2 < b) return i + 1;
        }
        else{
            if(a + rem2 < b) return i + 1;
            if(b + rem1 < a) return i + 1;
        }
    }
    return 10;
}
void UpDate(string &s, int p){
    l(i, 0, 10){
        if(s[i]=='?'){
                if((i%2)==p) s[i]='1';
                else s[i]='0';
        }
    }
}
int32_t main(){
    FIO

    w(o){
        string s; cin >> s;

        string c(s);
        UpDate(c, 1ll); UpDate(s, 0ll);

        cout << min(f(c), f(s)) << endl;        
    }

}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/