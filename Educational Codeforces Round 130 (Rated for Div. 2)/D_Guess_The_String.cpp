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
#define w(T)                            int T; cin >> T; while(T--)
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
int query(int i, int j){
        cout << "? 2 " << i << ' ' << j << endl; cout.flush();

        int ret; cin >> ret; 

        return ret;
}
int32_t main(){
        
        FIO

        int n; cin >> n; 

        int cnt = 0;

        vi f(26, -infinity);

        string s(n, 'a');

        for(int i=1; i <= n; i++){
                int distinct = query(1, i);

                if(distinct > cnt){
                        // new char found make the query

                        cout << "? 1 " << i << endl; cout.flush();

                        char put; cin >> put;

                        s[i - 1] = put;

                        cnt++;

                        f[put - 'a'] = i;
                }
                else{
                        // cout << "i am here " << i << endl; cout.flush();
                        vi srch(f); sort(all(srch));

                        int l = 0, r = 25; 

                        while(l <= r){
                                int mid = (l + r)/2;

                                if(srch[mid] == -infinity){
                                        l = mid + 1; continue;
                                }
                                // cout << "about to query " << srch[mid] << ' ' << i << endl; cout.flush();
                                int distinct = query(srch[mid], i);

                                if(distinct == 26 - mid + 1)
                                        r = mid - 1;

                                else l = mid + 1;
                        }
                        s[i - 1] = find(all(f), srch[r]) - f.begin() + 'a';

                        f[s[i - 1] - 'a'] = i;
                }
        }
        cout << "! " << s << endl; 

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/