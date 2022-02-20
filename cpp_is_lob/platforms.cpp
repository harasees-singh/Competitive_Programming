
#include<bits/stdc++.h>

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

int32_t main(){
	w(t){
		int n; cin >> n;

                vi arr(n); 

                for(auto &p : arr){
                        string s; cin >> s;
                        p = stoi(s);
                }
                multiset<pii> ms;

                for(int i = 0; i < n; i++){
                        string b; cin >> b;

                        ms.insert(make_pair(arr[i], stoi(b)));

                }
                int cnt = 0;

                for(; ; cnt++){
                        auto it = ms.begin();

                        while(it != ms.end()){
                                pii t = *it; ms.erase(it);
                                it = ms.upper_bound(make_pair(t.ss, -1));
                        }
                        if(sz(ms) == 0) break;

                }
                cout << cnt + 1 << endl;
	}
}
