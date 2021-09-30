#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x
#define in(x)                           cin >> x;

MOD_DEFINE
bool equal(char a, int b){
        return (a == '*' and b == 1 or a == '.' and b == 0);
}

int32_t main(){
    FIO     

    // for every '*' if it is unvisited, keep going in this \ direction, if u find >= k '*'s then increment all of em by 1, then go in / direction do the same.
    // at the end for every '*' 2 conditions must be met
    // 1) it should be marked with a number >= 1
    // 2) it must be connnected to a number > 1 in either / or \ direction.

        test_cases_loop{
                int n, m, k;

                in(n) in(m) in(k)

                vector<string> mat(n);

                l(i, 0, n)
                        cin >> mat[i];
                
                vector<vi> ans(n, vi(m));

                for(int i = n - 1; i >= 0; i--){
                        l(j, 0, m){

                                int cnt;
                                int r = i, c = j;
                                
                                if(mat[r][c] == '*'){
                                        cnt = 0;
                                        int leftup = false;
                                        int rightup = false;
                                        
                                        r--, c--;

                                        while(r >= 0 and c >= 0 and mat[r][c] == '*')
                                                r--, c--, cnt++;
                                        
                                        leftup = cnt;

                                        cnt = 0;

                                        r = i, c = j;
                                        r--, c++;

                                        while(r >= 0 and c < m and mat[r][c] == '*')
                                                r--, c++, cnt++;

                                        rightup = cnt;

                                        int up = min(leftup, rightup);

                                        if(up >= k){

                                                r = i, c = j;

                                                while(up + 1)
                                                        ans[r][c] = 1, r--, c--, up--;
                                                r = i, c = j;

                                                up = min(leftup, rightup);

                                                while(up + 1)
                                                        ans[r][c] = 1, r--, c++, up--;
                                                
                                        }
                                }       

                        }
                }
                bool allone = true;

                l(i, 0, n)
                        l(j, 0, m)
                                allone = allone & equal(mat[i][j], ans[i][j]);
                cout << (allone ? "YES" : "NO") << endl;
        }

    return 0;
}
