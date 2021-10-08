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

unordered_map<char, char> Reverse = {{'0', '0'}, {'1', '1'}, {'2', '5'}, {'5', '2'}, {'6', '!'}, {'8', '8'}, {'9', '!'}, {'7', '!'}, {'3', '!'}, {'4', '!'}};

bool valid(string h, string m, int H, int M){
    string hour = string(1, Reverse[m[1]]) + string(1, Reverse[m[0]]);
    string minute = string(1, Reverse[h[1]]) + string(1, Reverse[h[0]]);

    // return true if hour and minute are valid;

    if(hour[0] != '!' and hour[1] != '!' and minute[0] != '!' and minute[1] != '!'){
            if(stoi(hour) < H and stoi(minute) < M)
                    return true;
            return false;
    }
    return false;
}

void increment(string &s){
    if(s == "99"){
            s = "100"; 
            return;
    }
    if(s[1] != '9')
            s[1]++;
    else    
            s[1] = '0', s[0]++;
}

int32_t main(){
    FIO

    test_cases_loop{
        int H, M; cin >> H >> M;

        string s; cin >> s;

        // 12:21

        string h = s.substr(0, 2), m = s.substr(3, 2);
        bool ok = 0;

        // cout << h << space << m << endl;
        // string j = "19";
        // increment(j); cout << j << endl;
        // cout << stoi("00") << endl;

        while(stoi(h) < H and !ok){
                while(stoi(m) < M){
                        if(valid(h, m, H, M))
                                {cout << h << ":" << m << endl; ok = 1; break;}
                        else 
                                increment(m);
                }   
                // cout << h << space << m << endl; cout.flush();
                m = "00";
                increment(h);
                
        }
        if(!ok)
                cout << "00:00" << endl;

    }

}
