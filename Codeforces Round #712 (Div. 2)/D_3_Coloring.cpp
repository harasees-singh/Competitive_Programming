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

int n;

int row(int p){

    return p/n;
}
int col(int p){

    return p%n;
}

int32_t main(){
    FIO

    cin >> n;

    vector<vector<int>> mat(n, vi(n));

    l(r, 0, n){
        l(c, 0, n){
            mat[r][c] = ((r + c)%2 ? 3 : 2);
        }
    }

    int pt2 = 0, pt3 = 1;

    // cout << mat[row(pt2)][col(pt2)] << space << mat[row(pt3)][col(pt3)] << endl;
    // cout.flush();

    while(pt2 < n*n or pt3 < n*n){

            int curr; cin >> curr;

            if(curr == 3 or curr == 1){

                if(pt2 == n*n){

                    cout << (curr == 3 ? 1 : 3) << space << row(pt3) + 1 << space << col(pt3) + 1 << endl;
                    cout.flush();

                    pt3++;

                    while(pt3 < n*n and mat[row(pt3)][col(pt3)] != 3) pt3++;

                    continue;
                }

                cout << 2 << space << row(pt2) + 1 << space << col(pt2) + 1 << endl; 
                cout.flush();

                pt2++;

                while(pt2 < n*n and mat[row(pt2)][col(pt2)] != 2) pt2++;
            }

            else{
                
                if(pt3 == n*n){

                    cout << (curr == 2 ? 1 : 2) << space << row(pt2) + 1 << space << col(pt2) + 1 << endl;
                    cout.flush();
                    pt2++;

                    while(pt2 < n*n and mat[row(pt2)][col(pt2)] != 2) pt2++;

                    continue;
                }

                cout << 3 << space << row(pt3) + 1 << space << col(pt3) + 1 << endl; 
                cout.flush();

                pt3++;

                while(pt3 < n*n and mat[row(pt3)][col(pt3)] != 3) pt3++;

            }
    }

}
