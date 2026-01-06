#include <iostream>
using namespace std;
class CloseHashingTable {
    int table[7];

    int hashfunc(int key) {
        return key % 7;
    }

public:
    CloseHashingTable() {
        for (int i = 0; i < 7; i++)
            table[i] = 0;
    }

    void insert(int key) {
        int index = hashfunc(key);

        // Linear probing
        int start = index;
        while (table[index] != 0) {
            index = (index + 1) % 7;
            if (index == start) {
                cout << "Hash table full\n";
                return;
            }
        }
        table[index] = key;
    }

    void display() {
        cout << "\nLinear Probing:\n";
        for (int i = 0; i < 7; i++)
            cout << i << ": " << table[i] << endl;
    }
};
class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class OpenHashingTable {
    Node* table[7];

    int hashfunc(int key) {
        return key % 7;
    }

public:
    OpenHashingTable() {
        for (int i = 0; i < 7; i++)
            table[i] = nullptr;
    }

    void insert(int key) {
        int index = hashfunc(key);
        Node* newNode = new Node(key);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    void display() {
        cout << "\nSeparate Chaining\n";
        for (int i = 0; i < 7; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int keys[] = {76, 93, 40, 47, 10, 55};

    CloseHashingTable closed;
    OpenHashingTable open;

    for (int k : keys) {
        closed.insert(k);
        open.insert(k);
    }

    closed.display();
    open.display();

    return 0;
}
