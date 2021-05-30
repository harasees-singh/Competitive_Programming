#include<bits/stdc++.h>
#define debug(a) cout << a << endl;
#define debug_(a, b) cout << a << " " << b << endl;
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
int32_t main(){
    test_cases_loop{
        int n, m;
        cin >> n >> m;
        map<int, int> pos_zeroes;
        string s;
        cin >> s;
        bool parity=false;
        int count_zeroes=0; int pos = 0; int curr_pos = -1;
        for(auto a: s){
            if(a=='1'){
                parity = true;
                pos_zeroes[curr_pos] = count_zeroes;
                count_zeroes = 0;
                curr_pos = pos;
            }
            else{
                count_zeroes++;
            }
            pos++;
        }
        // pos_zeroes[curr_pos] = count_zeroes;
        int trailing_zeroes = s.size()-curr_pos-1;
        string trail="";
        if(trailing_zeroes){
            for(int j=0; j<trailing_zeroes;j++){
                j<m ? trail+='1':trail+='0';
            }
        }
        // cout << pos_zeroes[2] << endl;
        string final_ans;
        if(parity)
        {    
            int init_zeroes=0;
            string init;
            bool found_1 = false;
            for(auto ch:s){if(ch=='0')init_zeroes++;else{found_1 = true; break;}}
            if(init_zeroes<=m){
                loop(i, 0, init_zeroes)init+='1';
            }
            else{
                loop(j, 0, init_zeroes){
                    j<init_zeroes-m ? init+='0':init+='1';
                }
            }
            
            found_1 ? final_ans = init:final_ans="";
            loop(i, 0, s.size()){
                if(s[i]=='1'){
                    // cout << i << endl;
                    int zeroes = pos_zeroes[i];
                    string curr = "1";
                    if(zeroes >= 2*m){
                        
                        loop(j, 0, zeroes){j<m Or j>zeroes-m-1 ? curr+='1':curr+='0';}
                    }
                    else{
                        if(zeroes%2==0){
                            loop(j, 0, zeroes){curr+='1';}
                        }
                        else{
                            loop(j, 0, zeroes){j==zeroes/2 ? curr+='0':curr+='1';}
                        }
                    }
                    final_ans += curr;
                    // cout << curr << endl;
                }
            }
            final_ans+=trail;
        }
        else final_ans = s;
        cout << final_ans << endl;
    }
}