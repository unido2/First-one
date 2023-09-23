#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;

int countSearch(char*,char);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	char str1[50] = "fiuu fu  ",
		str2[50] = "hey, google are you good gingle game?";
	char key1 = ' ';
	char key = 'h';

	cout << countSearch(str1, key1) << endl;

	return 0;
}

int countSearch(char* str, char key)
{
	int count = 0;
	char* ptr=nullptr;

	if ((ptr=strchr(str, key)) != NULL) {
		count++;
		do {
			ptr = strchr(ptr + 1, key);
			if (ptr != NULL)
				count++;
			else
				break;

		} while (ptr != NULL);
	}
	else
		return 0;


	return count;
}
