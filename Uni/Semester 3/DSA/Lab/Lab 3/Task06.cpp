#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void pushback(int d) {
        Node* n = new Node(d);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void display() {
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->data << "->";
        cout << "null" << endl;
    }
};

Node* mergeSorted(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node* head = nullptr;
    Node* tail = nullptr;

    if (h1->data <= h2->data) {
        head = tail = h1;
        h1 = h1->next;
    } else {
        head = tail = h2;
        h2 = h2->next;
    }

    while (h1 && h2) {
        if (h1->data <= h2->data) {
            tail->next = h1;
            tail = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            tail = h2;
            h2 = h2->next;
        }
    }

    if (h1) tail->next = h1;
    if (h2) tail->next = h2;

    return head;
}

int main() {
    LinkedList l1;
    l1.pushback(1);
    l1.pushback(3);
    l1.pushback(5);

    LinkedList l2;
    l2.pushback(2);
    l2.pushback(4);
    l2.pushback(6);

    LinkedList merged;
    merged.head = mergeSorted(l1.head, l2.head);

    merged.display();
    return 0;
}
