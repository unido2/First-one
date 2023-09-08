#ifndef STACK_C_H
#define STACK_C_H

#include"List.h"

template<class STACKTYPE>
class Stack_c {
public:
	void push(const STACKTYPE&);
	int pop(STACKTYPE&);
	int isStackEmpty() const;
	void printStack() const;
private:
	List<STACKTYPE> s;
};


template<class STACKTYPE>
void Stack_c<STACKTYPE>::push(const STACKTYPE& value)
{
	s.insertAtFront(value);
}

template<class STACKTYPE>
int Stack_c<STACKTYPE>::pop(STACKTYPE& value)
{
	return s.removeFromFront(value);
}

template<class STACKTYPE>
int Stack_c<STACKTYPE>::isStackEmpty() const
{
	return s.isEmpty();
}

template<class STACKTYPE>
void Stack_c<STACKTYPE>::printStack() const
{
	s.print();
}

#endif // !STACK_C_H
