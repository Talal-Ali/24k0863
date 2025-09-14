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

    void pushBack(int d) {
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
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

LinkedList* updateList(LinkedList* l) {
    LinkedList* even = new LinkedList();
    LinkedList* odd = new LinkedList();

    Node* temp = l->head;
    while (temp) {
        if (temp->data % 2 == 0)
            even->pushBack(temp->data);
        else
            odd->pushBack(temp->data);
        temp = temp->next;
    }

    if (even->head && !odd->head) return even;
    if (odd->head && !even->head) return odd;

    Node* tail = even->head;
    while (tail->next) tail = tail->next;
    tail->next = odd->head;

    return even;
}

int main() {
    LinkedList* l = new LinkedList();

    cout << "Enter 6 numbers: ";
    for (int i = 0; i < 6; i++) {
        int n;
        cin >> n;
        l->pushBack(n);
    }

    cout << "\nOriginal list:" << endl;
    l->display();

    l = updateList(l);

    cout << "\nUpdated list (even first, then odd):" << endl;
    l->display();

    return 0;
}
