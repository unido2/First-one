#include "Bits.h"
#include<iostream>
#include<iomanip>

using namespace std;

void Bits::displayBits(int digit)
{
	unsigned value = (unsigned)abs(digit);
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
