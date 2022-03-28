// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
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
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE
// 15! is greater than 1e12
// form all subsets of first 15 factorials
// 1 << 15 subsets formed
// brute force over them by turning on the remaining bits and taking overall minimum
mii val_cnt;
vi facs(16);
void go(int id, int cnt, int abhitak){
    if(id == 16) return;

    int milgaya = facs[id] + abhitak;

    if(val_cnt.count(milgaya)){
        amin(val_cnt[milgaya], cnt + 1);
    }
    else val_cnt[milgaya] = cnt + 1;

    go(id + 1, cnt + 1, milgaya);

    go(id + 1, cnt, abhitak);
}
int mn = infinity;

void cmp(int n, int contender){
    // cout << val_cnt[contender] << endl;
    if(contender > n) return;
    int need = n - contender;
    int cnt = 0;

    if((contender & 1) and (need & 1) or ((contender >> 1) & 1) and ((need >> 1) & 1)) return;

    for(int i = 0; i < 40; i++){
        cnt += (need >> i) & 1;
    }
    amin(mn, val_cnt[contender] + cnt);
}
vi twopowers = {1};
int32_t main(){
        
        FIO
        val_cnt[0] = 0;
        facs[0] = 1;

        for(int i = 1; i < 16; i++) facs[i] = facs[i - 1] * i;

        go(1, 0, 0);

        vi it; for(auto p : val_cnt) it.push_back(p.ff);
        
        w(t){
            int n; cin >> n;

            mn = infinity;

            for(auto p : it) cmp(n, p);

            // cmp(n, 0);

            cout << mn << endl;
        }

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/