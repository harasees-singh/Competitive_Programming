#include<bits/stdc++.h>
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

using namespace std;
MOD_DEFINE

int32_t main(){
    FIO 

    test_cases_loop{

        int W, H; cin >> W >> H;

        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        int w, h; cin >> w >> h;

        

        if((h + y2 - y1 > H and w + x2 - x1 > W) or (h > H or w > W)) cout << -1 << endl;

        // else if(y1 >= h or H - y2 >= h or x1 >= w or W - x2 >= w) cout << fps((long double)0, 6) << endl;

        else{

            if(h + y2 - y1 > H) H = -infinity, y1 = -infinity;

            if(w + x2 - x1 > W) W = -infinity, x1 = -infinity;

            // long double Xmove = min(max(0ll, w - x1), max(0ll, w - (W - x2)));

            // long double Ymove = min(max(0ll, h - y1), max(0ll, h - (H - y2)));

            // cout << fps(sqrt(Xmove*Xmove + Ymove*Ymove), 6) << endl;

            cout << min(min(max(0ll, h - y1), max(0ll, h - H + y2)), min(max(0ll, w - x1), max(0ll, w - W + x2))) << endl;
        }
    }

    return 0;
}
