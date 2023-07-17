#include<iostream>
#include"Date1.h"

int main() {
	using namespace std;

	Date d1, d2(12, 27, 1992), d3(0, 99, 8045);

	cout << "d2+=7: " << (d2 += 7) << endl << endl;

	d3.setDate(3, 18, 1969);
	cout << "d3: " << d3 << endl;
	cout << "++d3: " << ++d3 << endl << endl;

	Date d4(3, 18, 1970);
	cout << "d4: " << d4 << endl;
	cout << "++d4: " << ++d4 << endl;
	cout << "d4: " << d4 << endl<<endl;

	cout << "d4: " << d4 << endl;
	cout << "d4++: " << d4++ << endl;
	cout << "d4: " << d4 << endl;


	return 0;
}