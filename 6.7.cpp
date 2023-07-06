#include <iostream>
#include "rational.h"


int main() {
	using namespace std;

	//Rational r(1, 2, 1, 4);
	Rational* ptr = new Rational[2];
	const char* cptr="lolo";
	int q;
	char nl = static_cast<char>(10);

	
	cout << "ptr= " << sizeof(float) << endl;
	cout << nl << nl;
	cout << "Rational= " << sizeof(double) << endl;

	delete[] ptr;

	return 0;
}