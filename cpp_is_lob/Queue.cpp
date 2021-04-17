#include<iostream>
using namespace std;
#define for(j, n) for(int i=j; i<n; i++)
class Queue
{
    public:
        int length;
        int head;
        int tail;
        int* queue;
        int size;
        
        
        Queue(int length_arr)
        {
            length = length_arr;
            head = 0;
            tail = 0;
            queue = new int[length_arr];
            size = 0;
        }
        int front()
        {
            if(head!=tail) return queue[head];
            else cout << "queue underflow; returning "; return -1;
        }
};
void Enqueue(Queue &q, int x)
{
    if(q.size==q.length)
    {
        cout << "queue overflow " << endl; return;
    }
    q.size++;
    q.queue[q.tail] = x;
    if(q.tail+1 == q.length)
    {
        q.tail = 0;
    }
    else q.tail++;
}
int Dequeue(Queue &q)
{
    if(q.size==0)
    {
        cout << "queue underflow ";
        return 0;
    }
    q.size--;
    int x = q.queue[q.head];
    if(q.head == q.length-1)
    {
        q.head = 0;
    }
    else q.head++;
    return x;
}
int main()
{
    cout << "please input the size of the queue ";
    int x;
    cin >> x;
    Queue Q(x);

    for(0, 5)
    {
        Enqueue(Q, i);
    }
    cout << "size of queue is " << Q.size << " and the capacity of the queue is "<< Q.length << endl;
    Enqueue(Q, 4);      // on inputint the size as 5 this should produce queue overflow error
    
    for(0, 2)
    {
        cout << "head is pointing to "<< Q.head << endl;
        cout << "size of the queue is " << Q.size << endl;
        Dequeue(Q);
    }
    for(0, 2)
    {
        Enqueue(Q, i);
    }
    for(0, 6)
    {
        cout << Q.head << endl;
        Dequeue(Q);
    }
    return 0;
}