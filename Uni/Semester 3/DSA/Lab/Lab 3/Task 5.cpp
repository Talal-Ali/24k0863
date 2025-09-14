#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
    Node(int d, Node* n, Node* p) : data(d), next(n), prev(p) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertFront(int x) {
        if (!head) {
            head = tail = new Node(x);
        } else {
            Node* n = new Node(x, head, nullptr);
            head->prev = n;
            head = n;
        }
    }

    void insertRear(int x) {
        if (!head) {
            head = tail = new Node(x);
        } else {
            Node* n = new Node(x, nullptr, tail);
            tail->next = n;
            tail = n;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    LinkedList queue;
    queue.insertFront(10);
    queue.insertFront(20);
    queue.insertRear(30);
    queue.insertRear(40);
    queue.insertRear(50);

    queue.display();
    return 0;
}
