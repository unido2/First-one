#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;

void printDigit(int d);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	char str[30],*ptr=str;
	cin.getline(str, 30);

	while (*ptr != '\0') {
		*ptr = toupper(*ptr);
		cout << *ptr;
		ptr++;
	}
	cout << endl;

	ptr = &str[0];
	while (*ptr != '\0') {
		*ptr = tolower(*ptr);
		cout << *ptr;
		ptr++;
	}
	cout << endl;


	return 0;
}

void printDigit(int d)
{
	int size=16;
	int mask = 1 << (size - 1);

	for (int i = 1; i <= size; i++) {
		cout << (mask & d ? "1" : "0");
		d <<= 1;
		if (i % 8 == 0)
			cout << ' ';
	}
	cout << endl;
}

