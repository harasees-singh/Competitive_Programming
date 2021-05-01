#include"bits.cpp"
#define vi vector<int>
using namespace std;
int ans;
void hop_rabbit(int x, int y, vector<vi> &playfield, vector<vi> &visited, int prev_val)
{   
    if(x>=playfield.size() || y>=playfield[0].size() || x<0 || y<0) return;
    if(visited[x][y]) return;
    // make 4 calls and then mark x, y as visited
    int current_val = playfield[x][y];
    if(abs(current_val-prev_val)==1) return;

    ans += max(abs(current_val - prev_val) - 1, 0);
    playfield[x][y] += ans;

    hop_rabbit(x-1, y, playfield, visited, current_val); 
    hop_rabbit(x, y+1, playfield, visited, current_val); 
    hop_rabbit(x+1, y, playfield, visited, current_val);
    hop_rabbit(x, y-1, playfield, visited, current_val);
    visited[x][y] = 1;
    return;
}   
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vi> playfield(0);
        for(int i=0; i<n; i++) 
        {
            vi temp(0);
            for(int j=0; j<m; j++)    
            {
                int temp_num;
                cin >> temp_num;
                temp.push_back(temp_num);
            }
            playfield.push_back(temp);

        }
        vi m_zeroes(m, 0);
        vector<vi> visited(n, m_zeroes);
        ans=0;
        // cout << "visited vector " << visited[0][0] << " and the size " << visited[0].size() << endl;
        // cout << playfield[1][1] << '\n' << playfield[0].size() << endl;
        hop_rabbit(0, 0, playfield, visited, INT32_MAX);
        cout << ans << endl;
    }   
}