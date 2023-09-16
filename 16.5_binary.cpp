#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include "c_try.h"

using namespace std;


int main() {
	//setlocale(LC_ALL, "Russian");
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	unsigned a;
	void displayBits(unsigned);

	cout << "Enter unsigned integer: ";
	cin >> a;
	displayBits(a);

	return 0;
}

void displayBits(unsigned value) {

	unsigned c, displayMask = 1 << 15;
	cout << setw(7) << value << " = ";

	for (c = 1; c <= 16; c++) {
		cout << (value & displayMask ? '1' : '0');
		value <<= 1;
		if (c % 8 == 0)
			cout << ' ';
	}
	cout << endl;
}


