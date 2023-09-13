#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"Stack.h"

using namespace std;



int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Stack<char*> str;
	char st[30];
	char* p;

	cin.getline(st,30);
	
	p = strtok(st, " ");
	while (p != NULL) {
		str.push(p);
		p = strtok(NULL, " ");
	}
	
	while (!str.isStackEmpty()) {
		str.pop(p);
		cout << p << ' ';
	}
	cout << endl;
	
	return 0;
}


