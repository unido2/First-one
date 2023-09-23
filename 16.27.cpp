#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;

int countSearchAlphabet(char*, char);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int alphabet[25];
	char str[50] = "qQQQQwertyuuuuuuuuuiopsdfghjklzxcvbnmzz";

	for (int i = 'a', j=0; i <= 'z'; i++) {
		alphabet[j]=countSearchAlphabet(str, i);
		if (alphabet[j] != 0) {
			cout << (char)i << " = " << alphabet[j] << endl;
			j != 24 ? j++ : j;
		}
	}
	cout << str << endl;

	return 0;
}

int countSearchAlphabet(char* str1, char key)
{
	char* s = new char[strlen(str1)+1];
	int count = 0;
	strcpy(s, str1);
	char* ptr = nullptr, *tmp=s;
	
	for (; *tmp != '\0'; tmp++)
		*tmp = tolower(*tmp);

	if ((ptr = strchr(s, key)) != NULL) {
		count++;
		do {
			ptr = strchr(ptr + 1, key);
			if (ptr != NULL)
				count++;
			else
				break;

		} while (ptr != NULL);
	}
	else {
		delete[]s;
		return 0;
	}

	delete[]s;
	return count;
}
