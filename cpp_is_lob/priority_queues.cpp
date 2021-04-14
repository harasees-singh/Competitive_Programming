#include"heap.cpp"
using namespace std;
class MaxHeap
{
    public:
        int heapsize;
        int* root;          // root pointer; will point to the arr
        MaxHeap(int* arr, int n)
        {
            BuildAMaxHeap(arr, n);
            root = arr;
            heapsize = n;
        }
        
};
int Parent(int child)
{
    return ceil(child/2.00 - 1);
}
int Maximum(MaxHeap H)
{
    return H.root[0];
}
int HeapExtractMax(MaxHeap &H)
{
    int* arr = H.root; int n = H.heapsize; int temp = arr[0];
    swap(arr[0], arr[n-1]);
    H.heapsize--;
    heapify(arr, 0, n);     // O(lgn)
    return temp;
}
void HeapIncreaseKey(MaxHeap &H, int i, int key)
{
    if(key < H.root[i])
    {
        cout << "error: the new key must be greater than the pervious key; key provided = " << key << " and the original key = " << H.root[i] << endl;
    }
    H.root[i] = key;
    while (i>0 && H.root[Parent(i)]<H.root[i])
    {
        swap(H.root[i], H.root[Parent(i)]);
        i = Parent(i);
    }
}
void MaxHeapInsert(MaxHeap &H, int val)
{
    //H.root = H.IncreaseHeapsize();
    H.heapsize++;
    H.root[H.heapsize-1] = -1*INT32_MAX;
    HeapIncreaseKey(H, H.heapsize-1, val);
}
void Print(MaxHeap H)
{
    int* arr = H.root;
    for(int i=0; i<H.heapsize; i++)
    {
        cout << H.root[i] << " ";
    }
    cout << endl;

}
int main()
{
    int arr[8] = {2, 4, 5, 8, 9, 6, 1, 3};
    MaxHeap H(arr, 8);
    cout << HeapExtractMax(H) << endl;
    Print(H);
    HeapIncreaseKey(H, 5, 10);
    cout << "the highest priority in the queue references to " << Maximum(H) << endl;
    Print(H);
    // arr[20] = 100;      // this is not raising warnings or errors, lower level languages are weird;
    // cout << "how the fk is this possible " << arr[20] << endl;
    // for(int i=0; i<100; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    MaxHeapInsert(H, 32);
    
    Print(H);
}