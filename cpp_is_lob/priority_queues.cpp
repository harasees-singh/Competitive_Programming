#include"bits.cpp"
#define ll long long
using namespace std;
class Heap
{   
    public:
        ll* start;
        ll Heap_size;
        ll array_length;
        ;
        Heap(ll* arr, ll size, ll length)
        {
            //root.index = 0;
            start = arr;
            Heap_size = size;
            array_length = length;
        }
        void Build_a_heap()
        {

        }
};


class Node
{
    public:
        ll index;
        int value;
        ll left_child_index, right_child_index;
        ll Parent(ll i)
        {
            return i/2;
        }
        ll Left_child()
        {
            return 2*index;
        }
        ll Right_child()
        {
            return 2*index+1;
        }
        Node(int num1, ll num2)
        {
            value = num1;
            index = num2;
        }
};
void Max_heapify(ll* arr, Node i)
{
    ll left = i.Left_child();
    ll right = i.Right_child();
    ll largest = i.index;
    if(arr[left] > arr[i.index] && left < sizeof(arr)/sizeof(arr[0]))
    {
        largest = left;
    }
    if(arr[right] > arr[largest] && right < sizeof(arr)/sizeof(arr[0]))
    {
        largest = right;
    }
    if(largest != i.index)
    {
        swap(arr[largest], arr[i.index]);
        // max_heapify(arr, largest) but largest is of the class long long and we need to pass a Node obj
    }
}
int main()
{
    ll array_size;
    cin >> array_size;
    ll* arr = new ll[array_size];
    for(int i=0; i<array_size; i++)
    {
        int temp;
        arr[0] = temp;
    }
    Heap tree_like_structure(arr, array_size, array_size);
}