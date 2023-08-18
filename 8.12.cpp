#define _CRT_MAP_ALLOC
#include<iostream>
#include<crtdbg.h>
#include "Array2.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	using namespace std;

	Array2 a(5,6);


	a[03] = 100;
	cout << a << endl;
	cout << a[03] << endl;
	
	return 0;
}