#include <iostream>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
        int n=0;
	    cin >> n;
	    int arr[n];
	    int start = n;
	    int sum = 0;
	    while(n--)
	    {
	        scanf("%d", &arr[start-n]);
	        sum = sum + arr[start-n];
	    }
	    if(sum%2 == 0)
	    {
	        printf("1\n");
	    }
	    else
	    {
	        printf("2\n");
	    }
	}
	return 0;
}
