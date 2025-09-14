#include <iostream>
#include <string>
using namespace std;

class BookNode {
public:
    string id, title, author;
    BookNode* next;

    BookNode(string i, string t, string a) : id(i), title(t), author(a), next(nullptr) {}

    void print() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }
};

class BookList {
private:
    BookNode* head;
    int count;

public:
    BookList() : head(nullptr), count(0) {}

    void addFirst(BookNode* book) {
        book->next = head;
        head = book;
        count++;
        cout << "Book added at beginning" << endl;
    }

    void addLast(BookNode* book) {
        if (!head) {
            head = book;
        } else {
            BookNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = book;
        }
        count++;
        cout << "Book added at end" << endl;
    }

    void addAt(int pos, BookNode* book) {
        if (pos < 1 || pos > count + 1) {
            cout << "Invalid position (1 to " << count + 1 << ")" << endl;
            delete book;
            return;
        }
        if (pos == 1) {
            addFirst(book);
            return;
        }
        BookNode* temp = head;
        for (int i = 1; i < pos - 1; i++) temp = temp->next;

        book->next = temp->next;
        temp->next = book;
        count++;
        cout << "Book added at position " << pos << endl;
    }

    void removeFirst() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        BookNode* temp = head;
        head = head->next;
        delete temp;
        count--;
        cout << "Book removed from beginning" << endl;
    }

    void removeLast() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            BookNode* temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        count--;
        cout << "Book removed from end" << endl;
    }

    void removeAt(int pos) {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 1 || pos > count) {
            cout << "Invalid position (1 to " << count << ")" << endl;
            return;
        }
        if (pos == 1) {
            removeFirst();
            return;
        }
        BookNode* temp = head;
        BookNode* prev = nullptr;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
        count--;
        cout << "Book removed from position " << pos << endl;
    }

    void search(string id) {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        BookNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->id == id) {
                cout << "Book found at position " << pos << ": ";
                temp->print();
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Book with ID " << id << " not found" << endl;
    }

    void showAll() {
        if (!head) {
            cout << "No books available" << endl;
            return;
        }
        cout << "\nBook List" << endl;
        cout << "Total: " << count << endl;
        BookNode* temp = head;
        int pos = 1;
        while (temp) {
            cout << pos << ". ";
            temp->print();
            temp = temp->next;
            pos++;
        }
        
    }

    ~BookList() {
        BookNode* current = head;
        while (current) {
            BookNode* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    BookList store;

    cout << "\n1. Adding books..." << endl;
    store.addFirst(new BookNode("101", "ABC", "Ali"));
    store.addLast(new BookNode("102", "DEF", "Ahmed"));
    store.addAt(2, new BookNode("103", "GHI", "Bilal"));
    store.showAll();

    cout << "\n2. Removing books..." << endl;
    store.removeFirst();
    store.showAll();
    store.removeLast();
    store.showAll();

    cout << "\n3. Adding more books..." << endl;
    store.addFirst(new BookNode("104", "JKL", "John"));
    store.addLast(new BookNode("105", "MNO", "Doe"));
    store.addAt(2, new BookNode("106", "PQR", "Joel"));
    store.showAll();

    cout << "\n4. Removing at position..." << endl;
    store.removeAt(2);
    store.showAll();

    cout << "\n5. Searching books..." << endl;
    store.search("105");
    store.search("999");

    return 0;
}
