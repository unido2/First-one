#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;


void printDigit(int,int(*)());
int size2byte();
int size4byte();


int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	int numb;

	cin >> numb;
	if (sizeof(int) == 4)
		printDigit(numb, size4byte);
	else
		if (sizeof(int) == 2)
			printDigit(numb, size2byte);


	return 0;
}

void printDigit(int d,int (*sizeF)())
{
	int size=(*sizeF)();
	int mask = 1 << (size - 1);

	for (int i = 1; i <= size; i++) {
		cout << (mask & d ? "1" : "0");
		d <<= 1;
		if (i % 8 == 0)
			cout << ' ';
	}
	cout << endl;
}

int size4byte()
{
	return 32;
}

int size2byte()
{
	return 16;
}
