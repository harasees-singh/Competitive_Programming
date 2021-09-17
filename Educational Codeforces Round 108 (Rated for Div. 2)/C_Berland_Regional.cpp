#include<bits/stdc++.h>
using namespace std;

#define cout std::cout
#define cin std::cin
#define int long long

int32_t main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int te; cin >> te; 
    
    while(te--)
    {
        int n; cin >> n;
    
        vector<vector<int>> I(n + 1);
        
        vector<int> supplement;
        
        for(int i = 0; i < n; i++){
            
            int t; cin >> t; supplement.push_back(t);
        }

        for(int i = 0; i < n; i++){
            int t; cin >> t; 
            
            // std::cout << t << ' '; std::cout.flush();
            
            I[supplement[i]].push_back(t);
        }
        
        for(int i = 1; i <= n; i++){
            
            // I[i].push_back(1e9 + 1); 
            
            sort(I[i].begin(), I[i].end(), greater<int>());
        }
        
        for(int i = 1; i <= n; i++){
            
            // I[i][0] = 0;
            
            for(int j = 1; j < I[i].size(); j++)
            
                I[i][j] = I[i][j - 1] + I[i][j];

            
        }

        // for(auto p : I[1]) cout << p << ' '; cout.flush();
        
        vector<int> ans(n + 1);
        
        for(int i = 1; i <= n; i++)
        
            for(int k = 1; k <= I[i].size(); k++)

                    ans[k] += I[i][I[i].size() - (I[i].size())%k - 1];
            
        for(int i = 1; i <= n; i++)
            
            cout << ans[i] << ' '; cout << '\n';
    }
}