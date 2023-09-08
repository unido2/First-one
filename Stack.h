#ifndef STACK_H
#define STACK_H

#include"List.h"

template<class STACKTYPE>
class Stack : private List<STACKTYPE> {
public:
	void push(const STACKTYPE& d) { this->insertAtFront(d); }
	int pop(STACKTYPE& d) { return this->removeFromFront(d); }
	int isStackEmpty() const { return this->isEmpty(); }
	void printStack() const { this->print(); }
};

#endif // !STACK_H
