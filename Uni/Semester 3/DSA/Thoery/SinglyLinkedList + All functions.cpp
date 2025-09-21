#include<iostream>
using namespace std;

class Node{
        int data;
        Node* nextNode;
    public:
        Node(){nextNode = nullptr;}
        Node(int d=0, Node* n = nullptr): data(d), nextNode(n){}
        Node(Node* n){data = n->data; nextNode = n->nextNode;}
        int getData(){return data;}
        void setData(int d){data =d;}
        Node* getnextNode(){return nextNode;}
        void setnextNode(Node* nn){nextNode =nn;}
        
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
        LinkedList():head(nullptr), tail(nullptr){}
        void pushfront(Node* node)
        {
            if(head== nullptr && tail == nullptr)
            {
                head = tail = node;
                return;
            }
            else{
                node->setnextNode(head);
                head = node;
            }
        }
        void pushback(Node* node)
        {
            if(head== nullptr && tail == nullptr)
            {
                head= tail = node;
            }
            else
            {
                tail->setnextNode(node);
                tail = node;
            }
        }
        Node* searchResult(int data)
        {
            Node* temp(head);
            while(temp != nullptr)
            {
                if(temp->getData() == data){
                    return temp;
                }
                temp = temp->getnextNode();
                
            }
            return nullptr;
        }
        void display()
        {
            if(head== nullptr && tail ==nullptr)
            {
                cout<<"\n List Already Empty"<<endl;
                return;
            }
            else
            {
                Node* temp(head);
                while(temp != nullptr)
                {
                    cout<<temp->getData()<<"->";
                    temp = temp->getnextNode();
                }cout<<"NULL"<<endl;
            }
        }
        void popFront()
        {
            if(head == nullptr && tail== nullptr)
            {
                cout<<"\n List Already Empty"<<endl;
            }
            else
            {
                cout<<head->getData()<<" <- Value Popped"<<endl;
                Node* temp = head;
                head = head->getnextNode();
                temp->setnextNode(nullptr);
                delete temp;
            }
        }
        void popback()
        {
            if(head == nullptr && tail == nullptr)
            {
                cout<<"\nList already empty"<<endl;
            }
           else if(head == tail)
            {
                cout << head->getData() << " <- Value Popped" << endl;
                delete head;
                head = tail = nullptr;
            }
            else
            {
                Node* temp = head;
                Node* prev = nullptr;

                while(temp->getnextNode() != nullptr)
                {
                    prev = temp;
                    temp = temp->getnextNode();
                }

                cout << temp->getData() << " <- Value Popped" << endl;
                tail = prev;
                prev->setnextNode(nullptr);
                delete temp;
            }
            
            
        }
        void mergeLinkedList(LinkedList* l1, LinkedList* l2 )
        {
            if(l1->head == nullptr)
            {
                l1->head = l2->head;
                l1->tail = l2->tail;
                return;
            }

            l1->tail->setnextNode(l2->head);
            l1->tail = l2->tail;
        }
        void sort()
        {
            if(head == nullptr || head->getnextNode() == nullptr)
            {
                return;
            }
            
            bool swapped;
            do{
                swapped = false;
                Node* curr = head;
                while(curr->getnextNode() != nullptr)
                {
                    Node* next = curr->getnextNode();
                    if(curr->getData() > next->getData())
                    {
                        int temp = curr->getData();
                        curr->setData(next->getData());
                        next->setData(temp);
                        swapped = true;
                    }
                    curr = next;
                }
                
            }while(swapped);   
        }

        void searchnDelete(int data)
        {
            Node* temp = head;
            Node* prev;
            bool found = false;
            if(head == nullptr && tail == nullptr)
            {
                cout<<"Empty List"<<endl;
                return;
            }
            while(temp != nullptr){
                if(temp->getData() == data)
                {
                    found = true;
                    if(temp == head)
                    {
                        head = head->getnextNode();
                        if(temp == tail)
                        {
                            tail = nullptr;
                        }
                        delete temp;
                        temp = head;
                    }
                    else
                    {
                            prev->setnextNode(temp->getnextNode());
                            if (temp == tail)
                            {
                                tail = prev;
                            }
                            delete temp;
                            temp = prev->getnextNode();
                    }
                }
                else
                {
                    prev = temp;
                    temp = temp->getnextNode();
                }
                
            }
            if(temp == nullptr && !found)
            {
                cout<<"Value does not exist"<<endl;
            }

        }
        void reverse()
        {
            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;

            tail = head;

            while (curr != nullptr)
            {
                next = curr->getnextNode();   
                curr->setnextNode(prev);      
                prev = curr;                  
                curr = next;                  
            }

            head = prev;
        }
        bool isPalindrome()
        {
            if (head == nullptr || head->getnextNode() == nullptr)
                return true;

            // Step 1: Find middle (slow/fast)
            Node* slow = head;
            Node* fast = head;
            while (fast->getnextNode() != nullptr && fast->getnextNode()->getnextNode() != nullptr)
            {
                slow = slow->getnextNode();
                fast = fast->getnextNode()->getnextNode();
            }

            // Step 2: Reverse second half
            Node* prev = nullptr;
            Node* curr = slow->getnextNode();
            while (curr != nullptr)
            {
                Node* next = curr->getnextNode();
                curr->setnextNode(prev);
                prev = curr;
                curr = next;
            }

            // Step 3: Compare first half and reversed second half
            Node* first = head;
            Node* second = prev;
            bool palindrome = true;
            while (second != nullptr)
            {
                if (first->getData() != second->getData())
                {
                    palindrome = false;
                    break;
                }
                first = first->getnextNode();
                second = second->getnextNode();
            }

            // (Optional) Step 4: Restore the list (reverse second half back)
            curr = prev;
            prev = nullptr;
            while (curr != nullptr)
            {
                Node* next = curr->getnextNode();
                curr->setnextNode(prev);
                prev = curr;
                curr = next;
            }
            slow->setnextNode(prev);

            return palindrome;
        }
        //Leetcode
        void reverseSublist(int start, int end)
        {
            if (start >= end || head == nullptr)
            {
                cout << "Invalid Positions" << endl;
                return;
            }

            Node dummy(0, head);
            Node* prev = &dummy;

            
            for (int i = 1; i < start; i++)
            {
                if (prev->getnextNode() == nullptr)
                {
                    cout << "Start position out of range" << endl;
                    return;
                }
                prev = prev->getnextNode();
            }

            
            Node* sublistTail = prev->getnextNode();
            Node* curr = sublistTail->getnextNode();
            for (int i = start; i < end && curr != nullptr; i++)
            {
                Node* next = curr->getnextNode();
                curr->setnextNode(prev->getnextNode());
                prev->setnextNode(curr);
                curr = next;
            }

            //reconnect tail to remaining part
            sublistTail->setnextNode(curr);

            //update head (in case start == 1)
            head = dummy.getnextNode();
    }

};

int main()
{
    Node* n1 = new Node(4);
    Node* n2 = new Node(5);
    Node* n3 = new Node(6);
    Node* n4 = new Node(7);
    Node* n5 = new Node(8);
    Node* n6 = new Node(9);
    LinkedList l;
    l.pushfront(n1);
    l.pushback(n2);
    l.pushfront(n3);
    l.pushback(n4);
    l.display();
    l.popback();
    if (l.searchResult(5) != nullptr)
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    l.display();
    l.popFront();
    //l.pushback(n2);  <- Cannot reuse a pointer, as it is already destroyed
    l.pushback(n6);
    l.pushfront(n5);
    l.pushfront(new Node(6));
    l.pushback(new Node(6));
    l.display();

    int deletingvalue;
    cout<<"Enter Value(s) to delete: ";
    cin>>deletingvalue;
    cout<<"Deleting "<<deletingvalue <<" ..."<<endl;
    l.searchnDelete(deletingvalue);
    l.display();
    l.sort();
    cout<<"After Sorting"<<endl;
    l.display();
    l.reverseSublist(2, 4);
    l.display();
    
}