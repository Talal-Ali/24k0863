#include <iostream>
#include <string>
using namespace std;

class Book{
    public:
    int bookID;
    string title;
    string author;
    Book* next;

    Book(int id, string t, string a){
        bookID=id;
        title=t;
        author=a;
        next=nullptr;
    }
};

class BookList{
    private:
    Book* head;
    public:
    BookList(){
        head=nullptr;
    }

    void insertAtBeginning(int id,string t, string a){
        Book* newBook=new Book(id, t, a);
        newBook->next=head;
        head=newBook;
    }

    void insertAtEnd(int id, string t, string a){
        Book* newBook=new Book(id, t, a);
        if(head==nullptr){
            head=newBook;
            return;
        }
        Book* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newBook;
    }

    void insertAtPosition(int id, string t, string a, int pos){
        if(pos==0){
            insertAtBeginning(id, t, a);
            return;
        }
        Book* newBook=new Book(id, t, a);
        Book* temp=head;
        for(int i=0; i<pos-1 && temp!=nullptr; i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"Position out of bounds"<<endl;
            delete newBook;
            return;
        }
        newBook->next=temp->next;
        temp->next=newBook;
    }

    void deleteAtBeginning(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Book* temp=head;
        head=head->next;
        delete temp;
    }

    void deleteAtEnd(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->next==nullptr){
            delete head;
            head=nullptr;
            return;
        }
        Book* temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }

    void deleteAtPosition(int pos){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        if(pos==0){
            deleteAtBeginning();
            return;
        }
        Book* temp=head;
        for(int i=0; i<pos-1 && temp!=nullptr; i++){
            temp=temp->next;
        }
        if(temp==nullptr || temp->next==nullptr){
            cout<<"Position out of bounds"<<endl;
            return;
        }
        Book* toDelete=temp->next;
        temp->next=toDelete->next;
        delete toDelete;
    }

    void searchByID(int id){
        Book* temp=head;
        while(temp!=nullptr){
            if(temp->bookID==id){
                cout<<"Book found: "<<temp->title<<" by "<<temp->author<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Book with ID "<<id<<" not found"<<endl;
    }

    void displayBooks(){
        if(head==nullptr){
            cout<<"No books in the list"<<endl;
            return;
        }
        Book* temp=head;
        while(temp!=nullptr){
            cout<<"ID: "<<temp->bookID<<", Title: "<<temp->title<<", Author: "<<temp->author<<endl;
            temp=temp->next;
        }
    }
};

int main(){
    BookList bl;
    bl.insertAtEnd(1, "Hello", "Ali");
    bl.insertAtBeginning(2, "Wolrd", "Hasan");
    bl.insertAtPosition(3, "86", "Goat", 1);
    bl.displayBooks();
    bl.searchByID(2);
    bl.deleteAtPosition(1);
    bl.displayBooks();
    bl.deleteAtBeginning();
    bl.displayBooks();
    bl.deleteAtEnd();
    bl.displayBooks();
    return 0;
}