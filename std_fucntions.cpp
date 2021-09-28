#include<bits/stdc++.h>
#define pb(a) push_back((a))
#define MOD 1000000007
#define int long long
using namespace std;

typedef long long ll;

template<typename T>
T power(T x, T y, ll p) { 
    T res = 1;     
  
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
template<typename T>
T modInverse(T n, T p){
    return power(n, p-2, p)%p; 
} 
ll fac[1000001] = {1};
void factorial(){
    fac[0] = 1;
    for(ll i=1;i<1000001;i++){
        fac[i] = (((((fac[i-1])+MOD)%MOD)*i)+MOD)%MOD;
    }
}
ll C(ll a,ll b){
    if(b>a)
        return 0;
    if(b==0||b==a)
        return 1;
    if(a==0)
        return 0;
    int div = ((fac[b]*fac[a-b]))%MOD;
    div = modInverse(div, (long long)MOD);
    return (fac[a]*div)%MOD;
}
int32_t main(){
    factorial();

    cout << C(5ll, 3ll) << endl;
    
}