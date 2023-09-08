#ifndef QUEUE_H
#define QUEUE_H

#include"List.h"

template<class QUEUETYPE>
class Queue: private List<QUEUETYPE> {
public:
	void enqueue(const QUEUETYPE& d) { this->insertAtBack(d); }
	int dequeue(QUEUETYPE& d) { return this->removeFromFront(d); }
	int isQueueEmpty() const { return this->isEmpty(); }
	void printQueue() const { this->print(); }
};

#endif // !QUEUE_H
