#include<iostream>
#define ll long long;
#include<math.h>
#include<string>
#define STRING(num) #num
using namespace std;
string helper(string time)
{
    string ans = "";
    int i=0;
    while(time[i] != '.')
    {
        
        ans = ans + time[i];
        i++;
    }
    ans = ans + '.' + time[i+1] + time[i+2];
    return ans;
}
float str_to_float(string time)
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
float op(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

int main()
{
    long long t;
    cin >> t;
    double k1, k2, k3, v;
    float ussain_bolt = 9.58;
    while(t--)
    {
        cin >> k1 >> k2 >> k3 >> v;
        //cout << k1 << k2 << k3 << v << endl;
        double resultant_speed = v*k1*k2*k3;
        double time_taken = 100/resultant_speed;
        //string time_string(std::to_string(time_taken));
        //time_string = "%0.2f";
        //cout << "\ntime string is " << time_string;
        //time_string = helper(time_string);
        float time_float = op(time_taken);
        //cout << "\ntime string = " << time_string  << " " << "float " << time_float<< endl;
        if(time_float < ussain_bolt)
        {
            cout << "Yes";
        }
        else
        {   
            cout << "NO";
        }
    }
    return 0;
}