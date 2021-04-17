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
        bool empty = true;
        
        
        Queue(int length_arr)
        {
            length = length_arr;
            head = 0;
            tail = 0;
            queue = new int[length_arr];
        }
        int front()
        {
            if(head!=tail) return queue[head];
            else cout << "queue underflow; returning "; return -1;
        }
};
void Enqueue(Queue &q, int x)
{
    q.queue[q.tail] = x;
    if(q.tail+1 == q.length)
    {
        q.tail = 0;
    }
    else q.tail++;
}
int Dequeue(Queue &q)
{
    if(q.head==q.tail)
    {
        cout << "queue underflow ";
        return 0;
    }
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

    // cout << Dequeue(Q) << endl;
    // Enqueue(Q, 8); cout << "front is " << Q.front() << endl;
    // cout << Dequeue(Q) << endl;
    // Enqueue(Q, 15); cout << "front is " << Q.front() << endl;
    // cout << Dequeue(Q) << endl;
    // Enqueue(Q, 18); cout << "front is " << Q.front() << endl;
    // cout << Dequeue(Q) << endl;
    // Enqueue(Q, 19); cout << "front is " << Q.front() << endl;
    // cout << Dequeue(Q) << endl;
    for(0, 50)
    {
        Enqueue(Q, i);
    }
    
    for(0, 40)
    {
        Dequeue(Q);
        cout << "head is pointing to "<< Q.head << endl;
    }
    return 0;
}