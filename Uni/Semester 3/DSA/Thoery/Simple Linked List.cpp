#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *nextNode;
		Node(){nextNode = nullptr;}
};

void initialisation(){
	Node firstNode;
	Node secondNode;
	
	firstNode.data = 10;
	secondNode.data = 20;
	
	firstNode.nextNode = &secondNode;
	
}

void traversal(Node* firstNode){
	Node* temp = firstNode;
	while(temp != nullptr)
	{
		cout<<temp->data<<endl;
		temp= temp->nextNode;
	}
}

Node* searching(Node* LinkedList, int searchData){
	Node* temp = LinkedList;
	while(temp->data != searchData)
	{
		temp= temp->nextNode;
		if(temp->data == searchData)
		{
			return temp;
		}
	}
	return nullptr;
}

void PushBack(Node*& data, Node* LinkedList)
{
	Node* temp = LinkedList;
	if (LinkedList == nullptr) {// Case 1: Linked List empty ho
        LinkedList = data;
        return;
    }
	while(temp->nextNode != nullptr)// Case 2: Linked List mein kuch bhi ho
	{
		temp= temp->nextNode;
	}
	temp->nextNode = data;
}
void PushFront(Node* data, Node*& LinkedList)
{
	if(LinkedList == nullptr)//Case 1: Empty hai tou humara new head pointer
	{
		LinkedList = data;
		return;
	}
	//Case 2: New Head Pointer but with non empty list
	data->nextNode = LinkedList;
	LinkedList = data;
	
}
void PopFront(Node*& LinkedList)
{
	Node *temp = nullptr;
	if(LinkedList == nullptr)// Case 1: Empty List
	{
		cout<<"Nothing to pop"<<endl;
		return;
	}
	//Case2: General Case
	temp = LinkedList->nextNode;
	delete LinkedList;
	LinkedList = temp;
}
void PopBack(Node*& LinkedList)
{
	Node* temp = LinkedList;
	Node* previousNode;

	if(LinkedList == nullptr)//Case 1: Empty List ka
	{
		cout<<"List is empty already"<<endl;

	}
	if (LinkedList->nextNode == nullptr)// Case 2: Single Node
    {
        delete LinkedList;
        LinkedList = nullptr;
        return;
    }
	while(temp != nullptr)//Case 3: General Case
	{
		previousNode = temp;
		temp = temp->nextNode;
	}
	previousNode->nextNode = nullptr;
	delete temp;

}
void InsertingBeforeSearch(Node* data, Node*& LinkedList, int search)
{
	Node* temp = LinkedList;
	Node* previousNode = nullptr;
	if(LinkedList == nullptr)
	{
		cout<<"Linked List does not exist"<<endl;
		return;
	}
	while(temp != nullptr&& temp->data != search)
	{
		previousNode = temp;
		temp= temp->nextNode;
	}
	if(temp == nullptr)//Value not found
	{
		cout<<"Value note found"<<endl;
		return;
	}
	if (previousNode == nullptr)//New head
    {
        data->nextNode = LinkedList;
        LinkedList = data;
		return;
    }
	//Best Case: Value found and inserted in between
	data->nextNode = temp;
	previousNode->nextNode = data;
	
}
void InsertAfterSearch(Node* data, Node*& LinkedList, int search)
{
	Node* temp = LinkedList;
	if(LinkedList == nullptr)
	{
		cout<<"List does not exist"<<endl;
		return;
	}
	while(temp != nullptr&& temp->data != search)
	{
		temp = temp->nextNode;
	}
	if(temp == nullptr)
	{
		cout<<"Value Not Found"<<endl;
		return;
	}
	data->nextNode = temp->nextNode;
	temp->nextNode = data;
}
void SearchAndErase(Node*& LinkedList, int searchData)
{
	Node* temp = LinkedList;
	Node* previousNode = nullptr;
	if(LinkedList == nullptr)
	{
		cout<<"Linked List does not exist"<<endl;
		return;
	}
	while(temp != nullptr && temp->data != searchData)
	{
		previousNode = temp;
		temp = temp->nextNode;
	}
	if(temp == nullptr)
	{
		cout<<"Value Not Found"<<endl;
		return;
	}
	if (previousNode == nullptr)
	{
		LinkedList = temp->nextNode;
		return;
	}
	previousNode->nextNode = temp->nextNode;
	delete temp;
	
}
Node TopOfFront(Node* LinkedList)
{
	Node garbage;
	garbage.data = 0;
	if(LinkedList == nullptr)
	{
		cout<<"Null ptr returning zero..."<<endl;
		return garbage;
	}
	return *LinkedList;
}
Node TopOfBack(Node* LinkedList)
{
	Node garbage;
	garbage.data = 0;
	if(LinkedList == nullptr)
	{
		cout<<"Null ptr returning zero..."<<endl;
		return garbage;
	}
	Node *temp = LinkedList;
	while(temp->nextNode != nullptr)
	{
		temp = temp->nextNode;
	}
	return *temp;
}
bool isEmpty(Node* LinkedList)
{
	if(LinkedList == nullptr)
	{
		return true;
	}
	return false;
}
void EmptyList(Node*& LinkedList)
{
	Node* temp = LinkedList;
	Node* previousNode;
	while(temp != nullptr)
	{
		previousNode = temp;
		temp = temp->nextNode;
		delete previousNode;
		
	}
	LinkedList = nullptr;
}

int main()
{
	
}