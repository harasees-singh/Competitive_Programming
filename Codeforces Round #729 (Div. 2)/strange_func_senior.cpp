#include "bits/stdc++.h"
#define int long long
#define endl '\n'
//#define MOD 998244353
#define MOD 1000000007
//ull MOD = 1000000007;
#define single solve(0);
#define testCases int t; cin>>t; for(int z1=1; z1<=t; z1++){ solve(z1);}
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define lld long double
#define ull unsigned long long
#define endl '\n'
#define root2 1.41421
#define root3 1.73205
#define sz(s) s.size()
#define INF 10000000000000000
#define mp make_pair
#define vi vector<int>
#define ss second
#define pb push_back
#define ff first
#define pii pair<int,int>
#define vii vector<pii>
#define mii map<int,int>
#define si set<int>
#define pq priority_queue<int>
#define pdq priority_queue<int, vi, greater<int> >
#define print(x) {cout<<x<<endl;}
#define gcd __gcd
#define rep(i,st,en) for(int i=st;i<en;i++)
#define printArr(arr) for(auto x:arr){ cout<<x<<" "; } cout<<"\n";
using namespace std;

int __gcd(int a,int b){
    if(b==0)
        return a;
    if(b>a)
        return __gcd(b,a);
    return __gcd(b,a%b);
}

int power(int x, unsigned int y){
    int res = 1;
    x = x%MOD;
    if(x==0) return 0;

    while(y>0){
        if(y&1) res = ((res*x)%MOD+MOD)%MOD;
        y = y>>1;
        x = ((x*x)%MOD+MOD)%MOD;
    }
    return res%MOD;
}

void solve(int test){
    
    int n;
    cin>>n;
//    int N = n;
    int i = 2;
    
    int ans = n;
    int l = 1;
    while(l<=n){
        ans += n/l;
        ans %= MOD;
        l = (l*i)/gcd(l,i);
        i++;
        // cout << l << endl;
    }
    
    cout<<ans<<"\n";
}

signed main(){
    
    fastIO;
    
//    single;
    testCases;
    
    return 0;
}