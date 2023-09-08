#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Stack_c.h"


using namespace std;


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Stack_c<int> intStack;
	int popInteger;
	cout << "stack with integers" << endl;


	for (int i = 0; i < 4; i++) {
		intStack.push(i);
		intStack.printStack();
	}

	while (!intStack.isStackEmpty()) {
		intStack.pop(popInteger);
		cout << popInteger << " pop from stack" << endl;
		intStack.printStack();
	}

	Stack_c<float> floatStack;
	float val = 1.1, popFloat;

	cout << "stack with floats" << endl;

	for (int i = 0; i < 4; i++) {
		floatStack.push(val);
		floatStack.printStack();
		val += 1.1;
	}

	while (!floatStack.isStackEmpty()) {
		floatStack.pop(popFloat);
		cout << popFloat << " pop from stack" << endl;
		floatStack.printStack();
	}


	return 0;
}


