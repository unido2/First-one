#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Queue.h"

using namespace std;


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Queue<int> intQueue;
	int dequeueInt;
	cout << "Queue of integers" << endl;

	for (int i = 0; i < 4; i++)
	{
		intQueue.enqueue(i);
		intQueue.printQueue();
	}

	while (!intQueue.isQueueEmpty()) {
		intQueue.dequeue(dequeueInt);
		cout << dequeueInt << " deleted from queue" << endl;
		intQueue.printQueue();
	}


	return 0;
}
