#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList(){
        head=nullptr;
    }

    void insertAtEnd(int val){
        Node* newNode=new Node(val);
        if (head == nullptr){
            head=newNode;
            return;
        }
        Node* temp=head;
        while (temp->next != nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void rearrangeEvenOdd(){
        if (!head || !head->next) return;

        Node* evenHead=nullptr;
        Node* evenTail=nullptr;
        Node* oddHead=nullptr;
        Node* oddTail=nullptr;

        Node* current=head;

        while (current != nullptr){
            if (current->data % 2 == 0){
                if (!evenHead){
                    evenHead=evenTail=current;
                } else{
                    evenTail->next=current;
                    evenTail=evenTail->next;
                }
            } else{
                if (!oddHead){
                    oddHead=oddTail=current;
                } else{
                    oddTail->next=current;
                    oddTail=oddTail->next;
                }
            }
            current=current->next;
        }

        if (!evenHead || !oddHead) return;

        evenTail->next=oddHead;
        oddTail->next=nullptr;
        head=evenHead;
    }

    void display(){
        if (head == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        while (temp != nullptr){
            cout<<temp->data;
            if (temp->next) cout<<" -> ";
            temp=temp->next;
        }
        cout<<" -> NULL"<<endl;
    }
};

int main(){
    LinkedList list;

    int n, val;
    cout<<"Enter number of elements: ";
    cin >> n;

    cout<<"Enter elements: ";
    for (int i=0; i < n; i++){
        cin >> val;
        list.insertAtEnd(val);
    }

    cout<<"\nOriginal List: ";
    list.display();

    list.rearrangeEvenOdd();

    cout<<"Modified List: ";
    list.display();

    return 0;
}
