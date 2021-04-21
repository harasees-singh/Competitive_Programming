#include<iostream>
using namespace std;
class Linked_List
{
    public:
        class Node
        {
            public:
                int data;
                Node* next;
                Node* prev;
                Node(int val)
                {
                    data=val;
                    next=NULL;
                    prev=NULL;
                }
        };
        Node* nil = new Node(-1);
        Node* Search(int val)
        {
            Node* temp = nil;
            while(temp->next!=nil && temp->data!=val)
            {
                temp=temp->next;
            }
            return temp->data==val ? temp : NULL;
        }
        void Insert(int val)
        {
            Node* temp = new Node(val);
            temp->next = nil->next;
            nil->next->prev = temp;
            temp->prev = nil;
            nil->next = temp;
        }
        void Delete(int val)
        {
            Node* to_be_removed = Search(val);
            if(to_be_removed)
            {
                to_be_removed->prev->next = to_be_removed->next;
                to_be_removed->next->prev = to_be_removed->prev;
            }
            else cout << "error this val does not exist in the linked list " << endl;
        }
};
int main()
{
    Linked_List L;
    L.Insert(5);
    L.Insert(9);
    cout << L.Search(9) << endl;
    L.Delete(9);
    cout << L.Search(9) << endl;
    return 0;
}