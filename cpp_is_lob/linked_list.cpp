#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;

        node(int val)
        {
            data = val;
            next = NULL;
        }
        //void InsertAtTail(node*, int);
};

void InsertAtTail(node* head, int val)
{
    node* n = new node(val); // new will request memory in heap and return the pointer to the newly allocated memory
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void Display(node* head)
{
    node* temp = head;
    while(temp->next != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    node a(4), b(5), c(6);
    a.next = &b;
    b.next = &c;
    node* head = &a;
    cout << a.data << " " << (a.next)->next->data << endl;
    InsertAtTail(head, 7);

    Display(head);    
}