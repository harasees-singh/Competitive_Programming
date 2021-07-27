#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        int n; cin >> n;

        int F[n + 1];

        for(auto &p : F) p = 1;

        vector<int> input = {0};

        for(int i = 0; i < n; i++){

            int t; cin >> t; input.push_back(t);
        }

        for(int i = 1; i <= n/2; i++){

            int j = 2;

            while(i*j <= n){
                
                if(input[i*j] > input[i]) 
                    
                    F[i*j] = max(1 + F[i], F[i*j]);
                
                j++;     
            }
        }

        int ans = 1; for(auto &p : F) ans = max(ans, p); cout << ans << '\n';
    }
}