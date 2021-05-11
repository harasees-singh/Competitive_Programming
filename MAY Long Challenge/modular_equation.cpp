#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define int long long
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
void fastscan_integer(int &number)      // for fastest possible integer input
{   
    bool negative = false; register int c; number = 0; c = getchar();
    if (c=='-') negative = true, c = getchar();
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;      
}
using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
int32_t main()
{
    FIO;
    int t;cin>>t;

    while(t--)
    {
        Linked_List l;
        for(int i=0; i<1000; i++)
        {
            l.Insert(i);
        }
        
        int n,m;
        cin>>n>>m;

        long long count = 0;

        vector<vector<int>> v(m+1);

        bool check[m+1];

        long maxi = 0;

        for(int i = 2;i<=n;i++)
        {
            long p = m%i;

            v[p].push_back(i);
            check[p] = true;

            maxi = max(maxi, p);

        }

        for(int i = 0;i<=maxi;i++)
        {
            if(check[i])
            {
                long long size = v[i].size();

                if(size>= 2)
                    count += (size*(size-1))/2;

                for(int j = 0;j<size;j++)
                {
                    long long k = i+v[i][j];

                    int r = 0;

                    while(k<=maxi)
                    {
                        if(check[k])
                            r += v[k].size();

                        k += v[i][j];
                    }

                    count += r;
                }
            }
        }
        for(int j=0; j<500; j++)
        {
            l.Search(j);
        }

        cout<<n-1 + count<<"\n";
    }
}