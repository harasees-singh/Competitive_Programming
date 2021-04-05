#include<iostream>
using namespace std;
class tree
{
    public:
        int data;
        tree* left;
        tree* right;
        tree(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};
tree* make_a_node_in_heap(int val)
{
    tree* n = new tree(val);
    return n;
}
void Insert(tree* &root, int val)
{
    if (root==NULL)
    {
        root = make_a_node_in_heap(val);
        return;
    }
    tree* temp = make_a_node_in_heap(val);
    tree* pointer = root;
    while(pointer != NULL)
    {
        if(pointer->data > val)     // go left
        {
            pointer = pointer->left;
        }
        else
        {
            pointer = pointer->right;   // go right
        }
    }
    pointer = temp;
}
int main()
{
    tree* root = NULL;
    tree a(4);
    root = &a;
    //Insert(root, 4);
    root->data = 5;
    tree* b = root->left;
    tree* c = root->right;
    tree* d = b->left;
    tree* e = b->right;
    b->data = 3;
    c->data = 4;
    d->data = 5;
    e->data = 6;
    //root->left->left->data = 3;
    //root->left->data = 4;
    //root->right->data = 6;
    //root->right->left->data = 5;
    //root->right->right->data = 8;
    //int t = 2;
    //while(t--)
    //{
    //    int val;
    //    cin >> val;
    //    Insert(root, val);
    //}
    cout << root->data << endl << root->left->data;
}