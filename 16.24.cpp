#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	char str[50]="hey, go for old this good games, shiit gAMAG",
		* searchPtr=NULL;
	char key[] = { "g" };

	cout << str << endl;
	
	searchPtr = strstr(str, key);
	cout << (searchPtr!=NULL?searchPtr:"") << endl;

	for (; searchPtr != NULL;) {
		searchPtr = strstr(searchPtr + 1, key);
		cout << (searchPtr != NULL ? searchPtr : "") << endl;
	}

	return 0;
}


