#include <iostream>
#include "TIME1.h"
using namespace std;

int main()
	{
	Time t, t2(70,11);

	cout << "Original armytime: ";
	t2.printMilitary();
	cout << endl << "Original standard time: ";
	t.printStandard();

	t.setTime(13, 27, 6);
	cout << endl << endl<< "Army time before setTime: ";
	t.printMilitary();
	cout << endl<< "Standard time before setTime: ";
	t.printStandard();

	t.setTime(90, 98, 97);
	cout << endl << endl << "Try to set wrong time: "
		<< endl << "Military time: ";
	t.printMilitary();
	cout << endl << "Standard time: ";
	t.printStandard();
	cout << endl;

	return 0;
	}
