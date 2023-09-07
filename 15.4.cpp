#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include"List.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	List<char*> a;
	char* c;
	a.insertAtFront((char*)"trosh");
	a.insertAtBack((char*)"kin");
	a.insertAtBack((char*)"kot");

	a.print();

	a.removeFromFront(c);
	//cout << c << endl;

	a.print();


	return 0;
}

