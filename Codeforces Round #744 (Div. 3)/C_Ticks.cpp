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

bool findOnesright(vector<vi> &aux, int cnt, vector<string> &mat, int r, int c, int k){

    // if(r == sz(mat) or c == sz(mat[0]))
    //         return cnt >= k;

    bool fill = cnt >= k;

    if(r + 1 < sz(mat) and c + 1 < sz(mat[0]))
            // can call
            if(mat[r + 1][c + 1] == '.' and cnt < k)
                fill = false;
            else if(mat[r + 1][c + 1] == '*')
                fill = findOnesright(aux, cnt + 1, mat, r + 1, c + 1, k);
            else 
                fill = cnt >= k;

    aux[r][c] |= fill;

    return fill;
}
bool findOnesleft(vector<vi> &aux, int cnt, vector<string> &mat, int r, int c, int k){

    // if(r == sz(mat) or c == sz(mat[0]))
    //         return cnt >= k;

    bool fill = cnt >= k;

    if(r + 1 < sz(mat) and c - 1 >= 0)
            // can call
            if(mat[r + 1][c - 1] == '.' and cnt < k)
                fill = false;
            else if(mat[r + 1][c - 1] == '*')
                fill = findOnesleft(aux, cnt + 1, mat, r + 1, c - 1, k);
            else 
                fill = cnt >= k;

    aux[r][c] |= fill;

    return fill;
}


int32_t main(){
    FIO

    test_cases_loop{
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> mat;

        l(i, 0, n){
            string s; cin >> s;

            mat.push_back(s);
        }
        
        vector<vi> aux(n, vi(m, 0));

        // 0 means unvisited or not a part of k len long segment.
        l(r, 0, n)
                l(c, 0, m)
                    if(mat[r][c] == '*')
                        findOnesleft(aux, 0, mat, r, c, k), findOnesright(aux, 0, mat, r, c, k);
        
        // l(r, 0, n){
        //         l(c, 0, m)
        //                 cout << aux[r][c]; cout << endl;}
        vector<vi> ans(n, vi(m));
        l(r, 0, n){
                l(c, 0, m){
                    bool ok = false;
                    cout << aux[r][c];

                    int R = r, C = c;
                    // if(R + 1 < n and C + 1 < m)
                    while(true){

                        if(R and R + 1 < n and C + 1  < m)
                            if(aux[R - 1][C + 1] == 1)
                                {ok = true; break;}
                            else 
                                if(aux[R + 1][C + 1] == 1)
                                    R++, C++;
                                else 
                                    break;
                        else 
                            break;
                        
                    }

                    while(true){
                        if(R and R + 1 < n and C - 1 >= 0)
                            if(aux[R - 1][C - 1] == 1)
                                {ok = true; break;}
                            else 
                                if(aux[R + 1][C - 1] == 1)
                                    R++, C--;
                                else 
                                    break;
                        else 
                            break;

                    }

                    ans[r][c] = ok;

                }
            cout << endl;
        }
        cout << endl;
        l(r, 0, n){
                l(c, 0, m)
                        cout << ans[r][c]; 

                        cout << endl;}
        bool f = true;
        l(r, 0, n)
            l(c, 0, m){

                if(mat[r][c] == '*')
                    f = f and (ans[r][c] == 1);
            }
        cout << (f ? "YES" : "NO") << endl;
    }


    

}
