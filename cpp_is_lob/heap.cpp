#include"bits.cpp"
#include<math.h>
using namespace std;
void heapify(int* arr, int i, int n)        // lg(n) time complexity
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if(l<n && arr[l]>arr[i] )
    {
        largest = l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest = r;
    }
    if(largest!=i)
    {
        swap(arr[i], arr[largest]);
        return heapify(arr, largest, n);
    }

}
void BuildAMaxHeap(int* arr, int n)         // O(n) time complexity
{
    int index = floor(n/2);
    for(int i=index; i>=0; i--)
    {
        heapify(arr, i, n);
    }                   
}
void HeapSort(int* arr, int n)          // O(nlgn) time complexity
{
    BuildAMaxHeap(arr, n); 
    for(int i = n-1; i>=1; i--)
    {   swap(arr[0], arr[i]); 
        heapify(arr, 0, i);
    }   
}
// int main()
// {
//     int arr[5];
//     arr[50] = 87;
//     for(int i=0; i< 100; i++)
//     {
//         cout << arr[i] << endl;
//     }
// }
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     int n;
//     cin >> n;
//     int* arr = new int[n];
    
//     for(int i=0; i<n; i++)
//     {
//         int temp;
//         cin>> temp;
//         arr[i] = temp;
//     }
    
//     int brr[] = {5, 4, 8, 9, 6, 2};
//     HeapSort(brr, 6); 
//     // BuildAMaxHeap(brr, 6);
//     for(int i = 0; i<6; i++)
//     {
//         cout<< brr[i] << " ";
//     }
    
// }
