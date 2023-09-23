#define _CRT_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<stdlib.h>

using namespace std;

void power2(int, int);

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	int a, pow;

	cout << "number: ";
	cin >> a;
	cout << "pow: ";
	cin>> pow;

	power2(a, pow);

	return 0;
}

void power2(int num, int pow)
{
	unsigned mask = 1 << 15;
	int digit = num * (2 << (pow - 1));
	cout << "number*2^pow= " << num << "*2^" << pow << " = "
		<< digit << endl;

	cout << digit << " in binary: ";

	for (int i = 1; i <=16; i++) {
		cout << (mask & digit ? "1" : "0");
		digit <<= 1;
		if (i % 8 == 0)
			cout << ' ';
	}
	cout << endl;
}
