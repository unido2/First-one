#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<assert.h>
#include"ListNode.h"

using namespace std;

template<class NODETYPE>
class List {

public:
	List();
	~List();
	void insertAtFront(const NODETYPE&);
	void insertAtBack(const NODETYPE&);
	int removeFromFront(NODETYPE&);
	int removeFromBack(NODETYPE&);
	int isEmpty() const;
	void print() const;
private:
	ListNode<NODETYPE>* firstPtr;
	ListNode<NODETYPE>* lastPtr;
	ListNode<NODETYPE>* getNewNode(const NODETYPE&);
};



template<class NODETYPE>
List<NODETYPE>::List()
{
	firstPtr = lastPtr = nullptr;
}

template<class NODETYPE>
 List<NODETYPE>::~List()
{
	if (!isEmpty()) {
		cout << "Delete nodes..." << endl;
		ListNode<NODETYPE>* currentPtr = firstPtr;
		ListNode<NODETYPE>*tempPtr;

		while (currentPtr != nullptr) {
			tempPtr = currentPtr;
			cout << tempPtr->data << endl;
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		}
	}
	cout << "All nodes are deleted" << endl;
}

template<class NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE& value)
{
	ListNode<NODETYPE>* newPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = lastPtr = newPtr;
	else {
		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;
	}
}

template<class NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE& value)
{
	ListNode<NODETYPE>* newPtr = getNewNode(value);

	if (isEmpty())
		firstPtr = lastPtr = newPtr;
	else {
		lastPtr->nextPtr = newPtr;
		lastPtr = newPtr;
	}
}


template<class NODETYPE>
int List<NODETYPE>::removeFromFront(NODETYPE& value)
{
	if (isEmpty())
		return 0;
	else {
		ListNode<NODETYPE>* tempPtr = firstPtr;
		if (firstPtr == lastPtr)
			firstPtr = lastPtr = nullptr;
		else
			firstPtr = firstPtr->nextPtr;
		value = tempPtr->data;
		delete tempPtr;
		return 1;
	}
}

template<class NODETYPE>
int List<NODETYPE>::removeFromBack(NODETYPE& value)
{
	if (isEmpty())
		return 0;
	else {
		ListNode<NODETYPE>* tempPtr = lastPtr;

		if (firstPtr == lastPtr)
			firstPtr = lastPtr = nullptr;
		else {
			ListNode<NODETYPE>* currentPtr = firstPtr;

			while (currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr;
			lastPtr = currentPtr;
			currentPtr->nextPtr = nullptr;
		}

		value = tempPtr->data;
		delete tempPtr;
		return 1;
	}
}

template<class NODETYPE>
int List<NODETYPE>::isEmpty() const { return firstPtr == 0; }


template<class NODETYPE>
ListNode<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE& value)
{
	ListNode<NODETYPE>* ptr = new ListNode<NODETYPE>(value);
	assert(ptr != 0);
	return ptr;
}


template<class NODETYPE>
void List<NODETYPE>::print() const
{
	if (isEmpty()) {
		cout << "List is empty" << endl << endl;
		return;
	}

	ListNode<NODETYPE>* currentPtr = firstPtr;
	cout << "List contains: ";

	while (currentPtr != 0) {
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nextPtr;
	}
	cout << endl << endl;
}

#endif // !LIST_H