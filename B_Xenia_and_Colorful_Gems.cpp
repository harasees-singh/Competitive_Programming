// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        INT64_MAX
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
// if we can prove that search space is monotonous then ez
// take every red stone one by one
// bin search for the optimal green stone
// to find the optimal green stone, bin search for the optimal blue stone
// time complexity : n * lgn * lgn

// bin searching for blue stone : for a fixed green and red stone : moving to either left or right will improve the answer
// proof : it's the same as distance of a point {x, x} from a fixed point {a, b}

// bin searching for green stone : for a fixed red stone : if we pick one green stone and find the optimal blue stone for the pair {red stone, green stone}
// moving in either left or right direction should improve the answer
// proof : none

// 3, 4, 7, 8
// 5, 6, 9
// 1, 4, 5, 10
int mini = infinity;
vi red, green, blue;
int sq(int a){return a * a;}
int cost(int a, int b, int c){
    return sq(a - b) + sq(b - c) + sq(c - a);
}
bool direction_blue(int mid, int r, int g){
    // true means right, false means left

    int cur = cost(mid, r, g);

    if(cost(mid + 1, r, g) < cur) return true;

    return false;
}
bool direction_green(int g, int r){
    int beg = 0, end = sz(blue) - 1;
    int local_mini = infinity;
    while(beg <= end){
        int mid = (beg + end)/2;
        
        amin(local_mini, cost(blue[mid], r, g));
        amin(mini, local_mini);

        if(direction_blue(blue[mid], r, g)) beg = mid + 1;

        else end = mid - 1;
    }
    g = g + 1;

    beg = 0, end = sz(blue) - 1;

    int contender = infinity;

    while(beg <= end){
        int mid = (beg + end)/2;

        amin(contender, cost(blue[mid], r, g));

        if(direction_blue(blue[mid], r, g)) beg = mid + 1;

        else end = mid - 1;
    }
    if(contender < local_mini)
        return true;

    return false;
}
int32_t main(){
        
        FIO

        w(t){
            int nr, ng, nb; cin >> nr >> ng >> nb;

            red = vi(nr), green = vi(ng), blue = vi(nb);

            for(auto &p : red) cin >> p; for(auto &p : green) cin >> p; for(auto &p : blue) cin >> p;

            mini = infinity;

            sort(all(red)); sort(all(blue)); sort(all(green));

            for(auto r : red){
                int beg = 0, end = sz(green) - 1;

                while(beg <= end){
                    int mid = (beg + end) / 2;

                    if(direction_green(green[mid], r)) beg = mid + 1;

                    else end = mid - 1;
                }
            }
            cout << mini << endl;
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