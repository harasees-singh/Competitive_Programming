#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>g ;
vector<int> d;
void dfs(int i, int u){
    
    d[i] = d[u] + 1;
    
    for(auto p : g[i])
        if(p != u) 
            dfs(p, i);
}

int diam = 0;
int f(int x, int p) {
    int len = 0;
    for(int y : g[x]) {
        if(y != p) {
            d[y] = d[x] + 1;
            int cur = 1 + f(y, x);
            diam = max(diam, cur + len);
            len = max(len, cur);
        }
    }
    return len;
}
 
int main() {
	
    int T = 100;

    freopen("tree.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    while(T--){
        int n = 10000;

        diam = 0;
        
        g = vector<vector<int>> (n + 1);
        
        for(int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v; 
            
            g[u].push_back(v);
            
            g[v].push_back(u);
        }
        d = vector<int> (n + 1);
        
        d[0] = -1;

        dfs(1, 0);
        
        int mx = max_element(d.begin(), d.end()) - d.begin();
        
        dfs(mx, 0);
        
        int ans = *max_element(d.begin(), d.end());

        f(1, 0);

        assert(diam == ans);

    }
    cout << "100 test cases OK" << endl;
	
	return 0;
}
