#include "IntLinkedListLS.h"
#include <iostream>
using namespace std;

/*
Constructor - initializes the fields.
*/
IntLinkedListLS::IntLinkedListLS()
{
	head = NULL;
	size = 0;
}
/*
- returns the size of the list
*/
int IntLinkedListLS::getSize()
{
	return size;
}
/*
- deletes every node
*/
IntLinkedListLS::~IntLinkedListLS(){
	IntNode* curr = head;
	if (head != NULL){
		while (curr != NULL){
			curr = curr->next;
			delete head;
			head = curr;
		}
	}
	size = 0;
}

/*
- adds a new node to the start of the list
*/
void IntLinkedListLS::addToStart(int value){
	IntNode* start = new IntNode;
	start->data = value;
	start->next = head;
	head = start;
	size++;
}

/*
- removes a node from the start of the list
*/
int IntLinkedListLS::removeFromStart(){
	if (head != NULL){
		int retVal = head->data;
		IntNode* remove = head;
		head = remove->next;
		delete remove;
		remove = NULL;
		size--;
		return retVal;
	}
	else
	{
		return -1;
	}
}

/*
- adds an IntNode to the given index
*/
void IntLinkedListLS::addToIndex(int value, int index){
	IntNode* add = new IntNode;
	add->data = value;
	IntNode* curr = head;
	IntNode* before = curr;
	int presIndex = 0;
	if ((head == NULL) && (index == 0))
	{
		head = add;
		add->next = NULL;
		size++;
	}
	else if ((head != NULL) && (index == 0))
	{
		add->next = curr;
		head = add;
		size++;
	}
	else if ((head->next == NULL) && (index == 1))
	{
		head->next = add;
		add->next = NULL;
		size++;
	}
	else if ((head->next == NULL) && (index == 0))
	{
		add->next = curr;
		head = add;
		size++;
	}
	else if (head->next != NULL)
	{
		while ((curr != NULL) && (presIndex<index))
		{
			before = curr;
			curr = curr->next;
			presIndex++;
		}
		if ((before != NULL) && (index == presIndex))
		{   
			before->next = add;
		    add->next = curr;
			size++;
	    }
	   else{
		   cout << "Invalid index " << index << " for array of size " << size << ". Add request ignored." << endl;
	   }
    }
    else
    {
		cout << "Invalid index " << index << " for array of size " << size << ". Add request ignored." << endl;
    }

}

/*
- prints the data 
*/
void IntLinkedListLS::printAll()
{
	IntNode* curr = head;
	cout << "[";
	while (curr != NULL)
	{
		if (curr->next == NULL)
		{
			cout << curr->data << "]";
		}
		else
		{
			cout << curr->data << ", ";
		}
		curr = curr->next;
	}
	cout << " " << "(size: " << size << ")" << endl;	
}

/*
- returns the value at the given index
*/
int IntLinkedListLS::get(int index)
{
	int currIndex = 0;
	IntNode* currNode = head;

	while ((currNode != NULL) && (currIndex < index)) {
		currNode = currNode->next;
		currIndex++;
	}
	if ((currNode != NULL) && (currIndex == index))
	{
		return currNode->data;
	}
	else
	{
		return -1;
	}
}

/*
- removes the node at the given index
*/
int IntLinkedListLS::removeFromIndex(int index)
{
	IntNode* curr = head;
	IntNode* before = head;
	int currIndex = 0;

	if (head != NULL)
	{
		if ((head->next == NULL) && (index == 0))
		{
			int retVal = head->data;
			delete head;
			curr = NULL;
			before = NULL;
			size--;
			return retVal;
		}
		else if ((head->next != NULL) && (index == 0))
		{
			int retVal = head->data;
			head = head->next;
			delete curr;
			curr = NULL;
			before = NULL;
			size--;
			return retVal;
		}
		else if ((head->next != NULL) && (index > 0))
		{
			while ((curr != NULL) && (currIndex < index))
			{
				before = curr;
				curr = curr->next;
				currIndex++;
			}
			if (curr != NULL)
			{
				int retVal = curr->data;
				before->next = curr->next;
				delete curr;
				size--;
				return retVal;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
}


