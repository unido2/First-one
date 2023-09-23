#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;


void strEnd(char*);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char str1[] = "badabumod";
	char str2[] = "hadumad";
	char str3[] = "big bbed";
	char str4[] = "big baraped";
	char str5[] = "edfor";


	strEnd(str1);
	strEnd(str2);
	strEnd(str3);
	strEnd(str4);
	strEnd(str5);


	return 0;
}
void strEnd(char* str)
{
	if(strchr(str, 'd')!=NULL)
		if (*(strrchr(str, 'd') + 1) == '\0' 
			&& *(strrchr(str, 'd') - 1)=='e')
			cout << str << endl;
}
