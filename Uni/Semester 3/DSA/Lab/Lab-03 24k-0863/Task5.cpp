#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        data=x;
        prev=next=nullptr;
    }
};

class Deque{
    private:
    Node* front;
    Node* rear;

    public:
    Deque(){
        front=rear=nullptr;
    }

    void insertFront(int x){
        Node* newNode=new Node(x);
        if (front == nullptr){
            front=rear=newNode;
        } else{
            newNode->next=front;
            front->prev=newNode;
            front=newNode;
        }
    }

    void insertRear(int x){
        Node* newNode=new Node(x);
        if (rear == nullptr){
            front=rear=newNode;
        } else{
            rear->next=newNode;
            newNode->prev=rear;
            rear=newNode;
        }
    }

    void deleteFront(){
        if (front == nullptr){
            cout<<"Deque is empty!"<<endl;
            return;
        }
        Node* temp=front;
        front=front->next;
        if (front) front->prev=nullptr;
        else rear=nullptr;
        delete temp;
    }

    void deleteRear(){
        if (rear == nullptr){
            cout<<"Deque is empty!"<<endl;
            return;
        }
        Node* temp=rear;
        rear=rear->prev;
        if (rear) rear->next=nullptr;
        else front=nullptr;
        delete temp;
    }

    int getFront(){
        if (front == nullptr){
            cout<<"Deque is empty!"<<endl;
            return -1;
        }
        return front->data;
    }

    int getRear(){
        if (rear == nullptr){
            cout<<"Deque is empty!"<<endl;
            return -1;
        }
        return rear->data;
    }

    void display(){
        if (front == nullptr){
            cout<<"Deque is empty!"<<endl;
            return;
        }
        Node* temp=front;
        while (temp != nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Deque dq;

    cout<<"Inserting elements at rear: 10, 20, 30"<<endl;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.display();

    cout<<"Inserting elements at front: 5, 2"<<endl;
    dq.insertFront(5);
    dq.insertFront(2);
    dq.display();

    cout<<"Front element: "<<dq.getFront()<<endl;
    cout<<"Rear element: "<<dq.getRear()<<endl;

    cout<<"Deleting front"<<endl;
    dq.deleteFront();
    dq.display();

    cout<<"Deleting rear"<<endl;
    dq.deleteRear();
    dq.display();

    cout<<"Front element: "<<dq.getFront()<<endl;
    cout<<"Rear element: "<<dq.getRear()<<endl;

    return 0;
}
