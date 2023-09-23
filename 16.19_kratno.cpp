#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;

int multiple(int);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	int y;
	cin >> y;

	if (multiple(y))
		cout << "kratno X" << endl;
	else
		cout << "ne kratno X" << endl;


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

int multiple(int num)
{
	int mask = 1, mult = 1;

	for (int i = 0; i < 10; i++, mask <<= 1) {
		//cout << mask << ' ';
		if ((num & mask) != 0) {
			mult = 0;
			break;
		}
	}
	return mult;
}
