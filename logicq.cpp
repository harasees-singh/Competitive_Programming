#include<bits/stdc++.h>
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define cout std::cout
#define cin std::cin
#define safe_unordered_map(int, T) unordered_map<int, T, custom_hash>

using namespace std;
MOD_DEFINE
int32_t main(){
  FIO

    string s; getline(cin, s);

    // {[|, [&, A, [!, B]], ..]}

    vector<char> input;

    for(auto p : s){

            if(p == '|' or p == '&' or p == '1' or p == '0' or p == '!' or p == '[' or p == ']'){

                input.pb(p);
            }
    }

    // cout << s << endl;

    // loop(i, 0, sz(input))cout << input[i] << endl;

    
    // while(sz(input) != 3)
    {    
        for (auto i = input.begin(); i != input.end(); ++i) 
        
    {

            // cout << "yo" << endl;

            char p = *i;

            if(p == ']'){

                // cout << "yo" << endl;

                // start solving

                vector<char> elements; 

                while(input[sz(input)-1] != '['){

                    elements.pb(input[sz(input)-1]); input.erase(i);
                }

                input.pop_back();

                loop(i, 0, sz(elements))cout << elements[i] << space; cout << endl;
                // cout << sz(elements) << endl;

                if(sz(elements) == 2){input.pb(elements[0] == '1' ? '0' : '1');}

                else{

                    // cout << elements[2] << endl;

                    if(elements[2] == '|') input.pb((char)((elements[1] - 48) or (elements[0] - 48) + 48));

                    else input.pb((char)((elements[1] - 48) and (elements[0] - 48) + 48));
                }

            }
        }
        // cout << sz(input) << endl;
    }
    cout << input[1] << endl;

    // loop(i, 0, sz(input))cout << input[i] << space; cout << endl;

  return 0;
}
