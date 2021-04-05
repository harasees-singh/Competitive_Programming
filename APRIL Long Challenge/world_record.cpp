#include<iostream>
#define ll long long;
#include<math.h>
#include<string>

using namespace std;

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
        
        double resultant_speed = v*k1*k2*k3;
        double time_taken = 100/resultant_speed;
        
        float time_float = op(time_taken);
        
        if(time_float < ussain_bolt)
        {
            cout << "Yes\n";
        }
        else
        {   
            cout << "NO\n";
        }
    }
    return 0;
}