#include <iostream>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int val) : data(val), next(nullptr) {}
};

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void printSinglyLinkedList(SinglyLinkedListNode* head) {
    for (SinglyLinkedListNode* cur = head; cur; cur = cur->next)
        cout << cur->data << " -> ";
    cout << "null" << endl;
}

void printDoublyLinkedList(DoublyLinkedListNode* head) {
    for (DoublyLinkedListNode* cur = head; cur; cur = cur->next) {
        int prevData = cur->prev ? cur->prev->data : -1;
        int nextData = cur->next ? cur->next->data : -1;
        cout << "Prev: " << prevData << " <- " << cur->data << " -> Next: " << nextData << endl;
    }
}

void printCircularLinkedList(SinglyLinkedListNode* head) {
    if (!head) { cout << "List is empty." << endl; return; }

    SinglyLinkedListNode* cur = head;
    cout << cur->data;
    cur = cur->next;
    while (cur != head) {
        cout << " -> " << cur->data;
        cur = cur->next;
    }
    cout << " -> (back to Head: " << head->data << ")" << endl;
}

DoublyLinkedListNode* convertSinglyToDoubly(SinglyLinkedListNode* head) {
    if (!head) return nullptr;
    DoublyLinkedListNode* dHead = new DoublyLinkedListNode(head->data);
    DoublyLinkedListNode* dCur = dHead;
    for (SinglyLinkedListNode* sCur = head->next; sCur; sCur = sCur->next) {
        DoublyLinkedListNode* newNode = new DoublyLinkedListNode(sCur->data);
        dCur->next = newNode;
        newNode->prev = dCur;
        dCur = newNode;
    }
    return dHead;
}

SinglyLinkedListNode* convertSinglyToCircular(SinglyLinkedListNode* head) {
    if (!head) return nullptr;
    SinglyLinkedListNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = head;
    return head;
}

int main() {
    SinglyLinkedListNode* singlyHead = new SinglyLinkedListNode(10);
    singlyHead->next = new SinglyLinkedListNode(20);
    singlyHead->next->next = new SinglyLinkedListNode(30);
    singlyHead->next->next->next = new SinglyLinkedListNode(40);

    cout << "Original Singly Linked List:" << endl;
    printSinglyLinkedList(singlyHead);

    DoublyLinkedListNode* doublyHead = convertSinglyToDoubly(singlyHead);
    cout << "\nConverted to Doubly Linked List:" << endl;
    printDoublyLinkedList(doublyHead);

    SinglyLinkedListNode* circularHead = convertSinglyToCircular(singlyHead);
    cout << "\nConverted to Circular Linked List:" << endl;
    printCircularLinkedList(circularHead);

    return 0;
}
