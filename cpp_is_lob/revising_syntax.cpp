#include<iostream>
using namespace std;
int ans_arr[int(1e5)];
void square(int* arr, int n)
{
    int i = 0;
    while(n--)
    {
        arr[i] = arr[i]+arr[i];
        i++;
    }
    
}

int homie(int* arr, int n)
{
    int j = 0, previous_number = 0;
    int next_number;
    int i = 0;
    int current = 0;
    
    int count = 0;
    while(n--)
    {
        
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
    return count;
}

int main()
{
    int a[20];
    a[0] = 45;
    a[19] = 45;
    
    
    int n = 4;
    int temp;
    
    
    int arr[10];
    square(arr, 20);
    //cout << "hey";
    

    int sample[50];
    for(int i=0; i<50; i++)
    {
        sample[i] = i;
        
    }
    int len_arr = homie(sample, 50);
    //int* ans = homie(arr, 20);
    cout << ans_arr[0] << endl <<  ans_arr[1] << endl << ans_arr[2] << endl << ans_arr[3] << "\nsuccessful\n";
    cout << "len of array returned = " << len_arr;
}