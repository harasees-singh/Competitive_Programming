#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define Set                             tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

int32_t main(){
    FIO

    test_cases_loop{

        int n; cin >> n;

        vector<string> I(3);

        l(i, 0, 3) cin >> I[i];

        string one_major, two_major;

        vector<pii> s;

        l(i, 0, 3){

            int cnt_ones = 0;
            for(auto p : I[i]) cnt_ones += (p == '1');

            s.push_back({cnt_ones, i});
        }

        sort(all(s));

        bool zero_major = false;

        if(s[1].first < n or s[2].first < n){

            zero_major = true;

            for(auto &p : I[s[0].second]) p = {p == '1' ? '0' : '1'};

            for(auto &p : I[s[1].second]) p = {p == '1' ? '0' : '1'};

            one_major = I[s[0].second], two_major = I[s[1].second];
        }

        else 

            one_major = I[s[1].second], two_major = I[s[2].second];

        string ans;

        int pt1 =0, pt2 =0;

        while(pt1 < 2*n or pt2 < 2*n){

            while(pt1 < 2*n and one_major[pt1] == '0')

                ans += '0', pt1++;
            
            while(pt2 < 2*n and two_major[pt2] == '0')

                ans += '0', pt2++;

            if(pt1 < 2*n or pt2 < 2*n)

                ans += '1';

            pt1++, pt2++;
        }

        if(zero_major) for(auto &p : ans) p = (p == '1' ? '0' : '1');

        cout << ans << endl;
    }
}