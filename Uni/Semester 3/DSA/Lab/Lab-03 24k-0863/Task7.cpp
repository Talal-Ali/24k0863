#include <iostream>
using namespace std;

class SNode{
    public:
    int data;
    SNode* next;
    SNode(int val){
        data=val;
        next=nullptr;
    }
};

class DNode{
    public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val){
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};

class SinglyLinkedList{
    private:
    SNode* head;

    public:
    SinglyLinkedList(){ head=nullptr; }

    void insertEnd(int val){
        SNode* newNode=new SNode(val);
        if (!head){
            head=newNode;
            return;
        }
        SNode* temp=head;
        while (temp->next) temp=temp->next;
        temp->next=newNode;
    }

    SNode* getHead(){ return head; }

    void display(){
        SNode* temp=head;
        while (temp){
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp=temp->next;
        }
        cout << " -> NULL" << endl;
    }

    DNode* toDoublyLinkedList(){
        if (!head) return nullptr;
        SNode* temp=head;
        DNode* dHead=new DNode(temp->data);
        DNode* dTail=dHead;
        temp=temp->next;

        while (temp){
            DNode* newNode=new DNode(temp->data);
            dTail->next=newNode;
            newNode->prev=dTail;
            dTail=newNode;
            temp=temp->next;
        }
        return dHead;
    }

    SNode* toCircularLinkedList(){
        if (!head) return nullptr;
        SNode* temp=head;
        while (temp->next) temp=temp->next;
        temp->next=head;
        return head;
    }
};

void displayDoubly(DNode* head){
    DNode* temp=head;
    cout << "NULL <-> ";
    while (temp){
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp=temp->next;
    }
    cout << " <-> NULL" << endl;
}

void displayCircular(SNode* head, int count){
    if (!head) return;
    SNode* temp=head;
    for (int i=0; i < count; i++){
        cout << temp->data;
        if (i < count - 1) cout << " -> ";
        temp=temp->next;
    }
    cout << " -> ... (circular)" << endl;
}

int main(){
    SinglyLinkedList sList;
    sList.insertEnd(10);
    sList.insertEnd(20);
    sList.insertEnd(30);
    sList.insertEnd(40);

    cout << "Original Singly Linked List: ";
    sList.display();

    DNode* dHead=sList.toDoublyLinkedList();
    cout << "Converted Doubly Linked List: ";
    displayDoubly(dHead);

    SNode* cHead=sList.toCircularLinkedList();
    cout << "Converted Circular Linked List (showing 8 nodes for demo): ";
    displayCircular(cHead, 8);

    return 0;
}
