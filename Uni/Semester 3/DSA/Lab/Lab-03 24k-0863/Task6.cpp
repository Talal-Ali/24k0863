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

    void insertEnd(int val){
        Node* newNode=new Node(val);
        if (!head){
            head=newNode;
            return;
        }
        Node* temp=head;
        while (temp->next){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    Node* gethead(){
        return head;
    }

    void sethead(Node* h){
        head=h;
    }

    void display(){
        Node* temp=head;
        while (temp){
            cout<<temp->data;
            if (temp->next) cout<<" -> ";
            temp=temp->next;
        }
        cout<<" -> NULL"<<endl;
    }

    static Node* mergeSorted(Node* head1, Node* head2){
        if (!head1) return head2;
        if (!head2) return head1;

        Node* mergedHead=nullptr;
        Node* tail=nullptr;

        if (head1->data <= head2->data){
            mergedHead=head1;
            head1=head1->next;
        } else{
            mergedHead=head2;
            head2=head2->next;
        }
        tail=mergedHead;

        while (head1 && head2){
            if (head1->data <= head2->data){
                tail->next=head1;
                head1=head1->next;
            } else{
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }

        if (head1) tail->next=head1;
        if (head2) tail->next=head2;

        return mergedHead;
    }
};

int main(){
    LinkedList listA, listB, merged;

    listA.insertEnd(1);
    listA.insertEnd(3);
    listA.insertEnd(5);

    listB.insertEnd(2);
    listB.insertEnd(4);
    listB.insertEnd(6);

    cout<<"List A: ";
    listA.display();
    cout<<"List B: ";
    listB.display();

    Node* mergedHead=LinkedList::mergeSorted(listA.gethead(), listB.gethead());
    merged.sethead(mergedHead);

    cout<<"Merged List: ";
    merged.display();

    return 0;
}
