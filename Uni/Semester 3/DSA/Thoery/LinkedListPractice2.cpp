#include<iostream>
using namespace std;

class anydata
{
    public:
        int n;
        anydata():n(-1){}
        anydata(int d): n(d){}
};
class node
{
    public:
        anydata d;
        node* next;
        node* prev;
        node(): next(nullptr), prev(nullptr){}
        node(int n):d(n), next(nullptr), prev(nullptr){}
        node(node* n):d(n->d), next(n->next), prev(n->prev){}
};

class SinglyLinkedList{
    public:
        node *head;
        SinglyLinkedList():head(nullptr){}

        void addNode(node* n)
        {
            if(head == nullptr)
            {
                head = n;
            }
            else
            {
                node* temp = head;
                while(temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = n;
            }
        }
        void display()
        {
            node* temp = head;
            while(temp != nullptr)
            {
                cout<<temp->d.n<<"->";
                temp = temp->next;
            }
            cout<<"null"<<endl;
        }
        void deletenodes(int n)
        {
            if(head == nullptr){return;}
            
            node* temp = head;
            node* prev = nullptr;
            while(temp!= nullptr)
            {
                if(temp->d.n == n)
                {
                    node* deletion = temp;
                    if(prev == head){
                        
                        head = head->next;
                        temp = head;
                    }
                    else
                    {
                        prev->next = temp->next;
                        temp = prev->next;
                    }
                    delete deletion;
                }
                else
                {
                    prev= temp;
                    temp->next = temp;
                }
                
            }
        }
        void pushback(int n)
        {
            node *nn = new node(n);
            if(head == nullptr)
            {
                head = nn;
                return;
            }
            node* temp = head;
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
        void popback()
        {
            if(head == nullptr){return;}
            node* temp = head;
            node* prev = nullptr;
            while(temp!= nullptr)
            {
                prev = temp;
                temp = temp->next;
                
            }
            prev->next = nullptr;
            delete temp;
        }
        void pushfront(int n)
        {
            node* nn = new node(n);
            if(head == nullptr)
            {
                head == nn;
                return;
            }
            nn->next = head;
            head = nn;
            
        }
        void popfront()
        {
            if(head == nullptr)
            {
                return;
            }
            node* temp = head;
            head = head->next;
            delete temp;
        }
        void reverse(int start, int end)
        {
            if(start >= end || head ==nullptr)
            {
                return;
            }
            node dummy(0);
            node* prev = &dummy;
            prev->next = head;

            for(int i = 1; i<start; i++)
            {
                if(prev->next == nullptr)
                {
                    return;
                }
                prev = prev->next;

                node* sub = prev->next;
                node* temp = sub->next;

                for(int i=start; i<end && temp != nullptr; i++)
                {
                    node* next = temp->next;
                    temp->next = prev->next;
                    prev->next = temp;
                    temp = next;
                }

                sub->next = temp;
                head = dummy.next;
            }
        }
};