#include<iostream>
#include<string>
#include<math.h>
using namespace std;

float str_to_int(string time)
{
    int len = time.size();
    int temp;
    float ans=0;
    int d = 0;
    for(int i = 0; i<len-3; i++)
    {
        
        int it = len - i -4;
        //cout << "iterator = " << it << endl << "value at it = "<< time[it] << endl;  
        d = int(time[it])-48;
        //cout << "\nd = " << d<<"\n";
        ans = ans + d*pow(10, i);       // first part of float obtained
        //cout << "currently answer is = " << ans << endl;
        temp = i;
    
          
        // now i is pointing to '.'  
    }
    int i = len - 3;
    ans = ans + float(int(time[i+1])-48)/10 + float(int(time[i+2])-48)/100;
    return ans;
}

int main()
{
    
    cout << str_to_int("67.98");

}

