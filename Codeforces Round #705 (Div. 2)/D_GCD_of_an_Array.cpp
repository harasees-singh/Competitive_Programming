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
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

// int n = 10;

const int N = 2e5;

int T[4*N + 1];

void build(vi &a, int v, int tl, int tr){
    // v being the current tree node number.
    // tl and tr being the left and right boundaries of indices that node v will store the answer to
    if(tl == tr)
            T[v] = a[tl];
    
    else{
            int tm = (tl + tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2 + 1, tm + 1, tr);

            // T[v] = T[v*2] + T[v*2 + 1];
            T[v] = __gcd(T[v*2], T[v*2 + 1]);
    }
}

int QuerySum(int v, int tl, int tr, int l, int r){

        if(tl >= l and tr <= r) 
                return T[v];
        if(tr < l or tl > r)
                return 0;
                
        int mid = (tl + tr)/2;

        int Q1 = QuerySum(2*v, tl, mid, l, r);
        int Q2 = QuerySum(2*v + 1, mid + 1, tr, l, r);

        if(Q1 == 0)
                Q1 = Q2;
        if(Q2 == 0)
                Q2 = Q1;
        
        return __gcd(Q1, Q2);

        // return QuerySum(2*v, tl, mid, l, r) + QuerySum(2*v + 1, mid + 1, tr, l, r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) 
                T[v] = new_val;

        else{
                int tm = (tl + tr) / 2;

                if (pos <= tm)
                        update(v*2, tl, tm, pos, new_val);
                else
                        update(v*2+1, tm+1, tr, pos, new_val);
                        
                T[v] = __gcd(T[v*2], T[v*2+1]);
        }
}

int32_t main(){
    FIO

    int n, q; 

    cin >> n >> q;

    vi I(n + 1);

    l(i, 1, n + 1)
            cin >> I[i];
    
    build(I, 1, 1, n);

    l(i, 0, q){

        int id, val; cin >> id >> val;

        update(1, 1, n, id, val*I[id]); I[id] = val*I[id];

        cout << QuerySum(1, 1, n, 1, n)%MOD << endl;
    }


}
