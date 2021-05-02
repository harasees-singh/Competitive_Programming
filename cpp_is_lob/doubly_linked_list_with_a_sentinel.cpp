#include<iostream>
using namespace std;
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
class Linked_List
{
    public:
        Node* nil = new Node(INT32_MAX);
        // Linked_List()
        // {
            
        // }
        
        auto Search(int val)
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
            if(nil->next)
            {
                
                temp->next = nil->next;
                nil->next->prev = temp;
                temp->prev = nil;
                nil->next = temp;
            }
            else nil->next=temp, temp->prev=nil, temp->next=nil, nil->prev=temp;
        }
        void Delete(int val)
        {
            Node* to_be_removed = Search(val);
            if(to_be_removed)
            {
                to_be_removed->prev->next = to_be_removed->next;
                to_be_removed->next->prev = to_be_removed->prev;
                delete to_be_removed;
            }
            else cout << "error this val does not exist in the linked list " << endl;
        }
        void Print()
        {
            Node* start=nil;
            start=start->next;
            if(start){
                while(start->data!=INT32_MAX && start->next)
                {
                    cout << start->data << endl;
                    start=start->next;
                }
            }
        }
};
int main()
{
    
    Linked_List L;
    
    L.Insert(5);
    L.Insert(9);
    cout << L.Search(9) << endl;
    L.Delete(7);
    cout << L.Search(9) << endl;
    L.Print();

    return 0;
}