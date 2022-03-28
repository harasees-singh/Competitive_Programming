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
vi have(3), need(3);

int32_t main(){
        
        FIO
        int n; cin >> n;
        string s; cin >> s;

        // place 0's first 
        // then 1s from left to right by replacing 2's then from right toleft by replacing 1s
        // then place 2's replacing 1's and 0's from right to left

        vi cnt(3);

        for(char i = '0'; i <= '2'; i++) cnt[i - '0'] = count(all(s), i);

        for(int i = 0;i < 3; i++){
            have[i] = cnt[i] - n/3; need[i] = n/3 - cnt[i]; 
        }

        
        for(auto &p : s){
            if(need[0] < 1) break;
            if(have[p - '0'] > 0){
                have[p - '0']--;

                p = '0';

                need[0]--;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(need[2] < 1) break;

            if(have[s[i] - '0'] > 0) have[s[i] - '0']--, need[2]--, s[i] = '2';
        }
        // 0's done

        for(auto &p : s){
            if(need[1] < 1) break;
            if(p == '2' and have[2] > 0) p = '1', have[2]--, need[1]--;
        }
        for(int i = n - 1; i >= 0; i--){
            if(need[1] < 1) break;

            if(s[i] == '0'){
                assert(have[0] > 0);

                need[1]--;

                s[i] = '1';
            }
        }

        // 1's done

        cout << s << endl;
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/