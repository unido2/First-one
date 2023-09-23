#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	char str[10], * ptr = str;
	unsigned i=4;
	int total=0;
	double total_d = 0;
	/*
	while (i-->0) {
		cin.getline(str, 10);
		total+=atoi(str);
	}
	cout << total << endl;
	*/
	while (i-- > 0) {
		cin.getline(str, 10);
		total_d += atof(str);
	}

	cout << total_d << endl;

	return 0;
}


