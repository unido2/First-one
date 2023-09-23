#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;


void printDigit4byte(int);
void packChar(unsigned &, char*);
void unpackChar(unsigned, char*);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	unsigned short int pack2b=0<<15;
	unsigned pack4b = 0<<(32-1);
	char str[] = { 'A','B','C','D','\0'};
	char strUnpack[5];
	char* ptr = str;
	
	while (*ptr != '\0') {
		printDigit4byte(*ptr);
		ptr++;
	}
	cout << "pack4b= ";
	printDigit4byte(pack4b);
	packChar(pack4b, str);
	
	cout <<"pack..."<<endl<< "pack4b= ";
	printDigit4byte(pack4b);

	unpackChar(pack4b, strUnpack);

	ptr = &strUnpack[0];

	while (*ptr != '\0') {
		printDigit4byte(*ptr);
		ptr++;
	}
	for (ptr = &strUnpack[0]; *ptr != '\0'; ptr++)
		cout << *ptr << ' ';
	cout << endl;

	return 0;
}

void printDigit4byte(int d)
{
	int size = 4*8;
	int mask = 1 << (size-1);

	for (int i = 1; i <= size; i++) {
		cout << (mask & d ? "1" : "0");
		d <<= 1;
		if (i % 8 == 0)
			cout << ' ';
	}
	cout << endl;
}

void packChar(unsigned & dig, char* c)
{
	while (*c != '\0') {
		dig = dig | *c;
		if(*(c+1) != '\0')
			dig <<= 8;
		c++;
	}
}

void unpackChar(unsigned c, char* str)
{
	unsigned mask = 255 << 8 * 3;

	for (int i = 4; i > 0; i--) {
		*str = (c & mask)>>8*(i-1);
		mask >>= 8;
		str++;
		if (i == 1)
			*str = '\0';
	}
}
