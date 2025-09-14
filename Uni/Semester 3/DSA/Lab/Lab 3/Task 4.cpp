#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char c) : data(c), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void pushfront(char c) {
        Node* n = new Node(c);
        n->next = head;
        head = n;
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

bool ispal(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedList bottom;
    Node* temp = slow->next;
    while (temp) {
        bottom.pushfront(temp->data);
        temp = temp->next;
    }
    temp = bottom.head;
    Node* temp2 = head;
    while (temp && temp2) {
        if (temp2->data != temp->data) return false;
        temp = temp->next;
        temp2 = temp2->next;
    }
    return true;
}

int main() {
    LinkedList test;
    test.pushfront('r');
    test.pushfront('a');
    test.pushfront('c');
    test.pushfront('e');
    test.pushfront('c');
    test.pushfront('a');
    test.pushfront('r');
    test.display();

    if (ispal(test.head)) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;

    return 0;
}
