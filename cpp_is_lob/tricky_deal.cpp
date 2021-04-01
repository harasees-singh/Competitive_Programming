#include<iostream>
#define ll long long
#include<math.h>
using namespace std;

bool good(int mid, int a)
{
    if (pow(2, mid)-1 < mid*a)
    {
        return true;
    }
    else return false;
}

int main() {
	ll t, a;
	cin >> t;
	while(t--)
	{
	    cin >> a;
	    
	    int left = 0;
	    ll right = 100;
        int ans;
        for(int mid=0; mid<50; mid++)
        {
            if (pow(2, mid)-1 < mid*a)
            {
                ans = mid;
            }
            //else return false;
        }

	    //while(left<=right)
	    //{
	    //    ll mid = (left+right)/2;
	    //    if(good(mid, a))
	    //    {
	    //        left= mid+1;
	    //    }
	    //    else
	    //    {
	    //        right=mid-1;
	    //    }
	    //}
	    cout << ans << " ";

        int number_of_days = ceil((log(a)/log(2)));
	    cout << number_of_days << endl;
	}
	return 0;
}
