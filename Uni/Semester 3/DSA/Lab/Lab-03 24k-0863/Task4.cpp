#include <iostream>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
    Node(char c){
        data=c;
        next=nullptr;
    }
};

class LinkedList{
    private:
    Node* head;

    Node* reverseList(Node* node){
        Node* prev=nullptr;
        Node* curr=node;
        Node* next=nullptr;
        while (curr != nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    public:
    LinkedList(){
        head=nullptr;
    }

    void insertChar(char c){
        Node* newNode=new Node(c);
        if (!head){
            head=newNode;
            return;
        }
        Node* temp=head;
        while (temp->next != nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    bool ispal(){
        if (!head || !head->next) return true;

        Node* slow=head;
        Node* fast=head;
        while (fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        Node* secondHalf=reverseList(slow->next);

        Node* firstHalf=head;
        Node* copySecond=secondHalf;
        bool palindrome=true;

        while (secondHalf != nullptr){
            if (firstHalf->data != secondHalf->data){
                palindrome=false;
                break;
            }
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }

        slow->next=reverseList(copySecond);

        return palindrome;
    }
};

int main(){
    LinkedList word;
    string input;
    cout<<"Enter a word: ";
    cin>> input;

    for (char c : input){
        word.insertChar(c);
    }

    if (word.ispal()){
        cout<<"true"<<endl;
    } else{
        cout<<"false"<<endl;
    }

    return 0;
}
