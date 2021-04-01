//1
//6
//4 16 32 6 8 2
//32 8
//32

//1 2 2 3 4
//4

//1 2 2 4 3
//4 

//1 5 4 2 5 1 4 1
//5 4 5
//5 5
//

//
#include<iostream>
using namespace std;
int arr[int(1e6)];
int PeakFinder(int* arr, int n)
{
    
    if(n <= 1)
    {
        return 1;
    }

    int i = 0;
    int ans_arr[n/2 + 1];
    int count = 0;

    int previous_number = 0;
    int current = 0, next_number;
    int ans = 0;
    int j = 0;
    //cout << j << endl;
    
    while(n--)
    {
        //cout << j << endl;
        next_number = arr[j];
        if((previous_number < current) && (next_number < current)) // peak found
        {
            ans_arr[i] = current;
            i++;
            count += 1;
        }
        previous_number = current;
        current = next_number;
        j++;
    }
    if(previous_number < current)
    {
        ans_arr[i] = current;
        count += 1;
    }
    ans = 1 + PeakFinder(ans_arr, count);
    return ans;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        //int previous_number = 0;
        int i = 0;
        
        cin >> n;
        int arr[n];
        int count = 0;
        int temp;
        if(n==1)
        {
            cout << 1 << endl;
            continue;
        }
        //int current = 0, next_number;
        //printf("hey what up\n");
        while(n--)
        {
            //cout << "working fine till here" << endl;
            cin >> temp;
            arr[i] = temp;
            i++;
            count++;
        }
        
        cout << PeakFinder(arr, count) << endl;
    }
    //printf("code ran successfully!");
    return 0;
}