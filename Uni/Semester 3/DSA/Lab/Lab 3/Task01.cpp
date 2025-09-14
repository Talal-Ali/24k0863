#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    string rollNo;
    string dept;

    Student(string n, string r, string d) 
        : name(n), rollNo(r), dept(d) {}

    void display() {
        cout << name << " | " << rollNo << " | " << dept << endl;
    }
};

class Node {
public:
    Student data;  
    Node* next;

    Node(Student s) : data(s), next(nullptr) {}
};

class StudentList {
    Node* head;
public:
    StudentList() : head(nullptr) {}

    void add(Student s) {
        Node* node = new Node(s);
        if (!head) {
            head = node;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }

    void remove(string roll) {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data.rollNo == roll) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Student removed" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp) {
            if (temp->data.rollNo == roll) {
                prev->next = temp->next;
                delete temp;
                cout << "Student removed" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Student not found" << endl;
    }

    void displayAll() {
        if (!head) {
            cout << "No students in the list" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            temp->data.display();
            temp = temp->next;
        }
    }

    ~StudentList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    StudentList students;

    students.add(Student("Ali Khan", "1001", "Computer Science"));
    students.add(Student("Sara Ahmed", "1002", "Mechanical Engineering"));
    students.add(Student("Omar Farooq", "1003", "Economics"));

    cout << "All students:" << endl;
    students.displayAll();

    students.add(Student("Ayesha Malik", "1004", "Law"));

    cout << "\nAfter adding one student:" << endl;
    students.displayAll();

    students.remove("1002");

    cout << "\nAfter removing roll number 1002:" << endl;
    students.displayAll();

    return 0;
}
