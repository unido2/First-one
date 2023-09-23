#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;


void strEnd(char*);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char str1[] = "badabum";
	char str2[] = "hadumed";
	char str3[] = "big bb";
	char str4[] = "big baraped";


	strEnd(str1);
	strEnd(str2);
	strEnd(str3);
	strEnd(str4);


	return 0;
}
void strEnd(char* str)
{
	if((*strchr(str,'d')+1)!='\0')
	cout << str << endl;
}
