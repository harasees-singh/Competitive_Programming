#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long int
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopb(i, a, b) for(int i=a; i>=b; i--)
#define testcase int t; cin>>t; while(t--)
#define pii pair<int, int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int32_t main() {
    fastio;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, m; cin>>n>>m;
    vector<pii> data(m);
    int available = 0;
    loop(i, 0, m) {
        cin>>data[i].f>>data[i].s;
        available+=data[i].f;
    }


    sort(data.begin(), data.end(), [](pii&a, pii&b) {
        return a.s > b.s;
    });

    int stolen = 0;
    int matches = 0;

    if(available>=n) {
        loop(i, 0, m) {
            if(stolen<n and data[i].f<=n-stolen) {
                stolen+=data[i].f;
                matches+=(data[i].f)*(data[i].s);
            }
            else if(stolen<n and data[i].f>n-stolen) {
                int stolen_frm_here = n-stolen;
                stolen+=n-stolen;
                matches+=(stolen_frm_here*data[i].s);
            }
            else {
                cout<<matches<<"\n";
                break;
            }
            // cout<<"stolen: "<<stolen<<" "<<"matches: "<<matches<<endl;
        }
    }
    else {
        loop(i, 0, m) {
            matches+=(data[i].f)*(data[i].s);
        }
        cout<<matches<<"\n";
    }
    
    
    return 0;
}