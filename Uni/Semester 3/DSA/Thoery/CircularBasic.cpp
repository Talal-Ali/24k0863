#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* nn;
};

class CircularLinkedList{
    public:
    Node* head; 
    Node* tail;
    Node* curr;

    CircularLinkedList(Node* h =nullptr, Node* t = nullptr, Node* c = nullptr): head(h), tail(t), curr(c){}

    void pushFront(Node* n){
        if (head == nullptr)
        {
            head = tail = n;
            n->nn = head;  
        }
        else
        {
            n->nn = head;     
            head = n;         
            tail->nn = head;  
        }

    }
    
    void traversal()
    {
        if(head==nullptr){return;}
        Node* temp = head;
        cout<<temp->data<<endl;
        temp = temp->nn;
        while(temp != head)
        {
            cout<<temp->data<<endl;
            temp = temp->nn;
        }
    }
    void pushBack(Node* n){
        if(head==nullptr){return;}
        Node* prev;
        Node* temp = head;
        temp = temp->nn;
        prev = temp;
        while(temp != head)
        {
            prev = temp;
            temp = temp->nn;
        }
        prev->nn = n;
        tail = n;
        n->nn = head;
    }
    

};