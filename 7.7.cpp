#include<iostream>
#include"Date1.h"

using namespace std;

int main() {
	Date *date1= new Date("Feburary", 2, 1990);
	Date* date2 = new Date(8, 3, 1991);
	Date* date3 = new Date();
	

	cout << "date: " << Date::getCount() << endl;
	date1->printF3();
	date2->printF3();
	date3->printF3();

	delete date1;
	delete date2;
	delete date3;

	cout << "date: " << Date::getCount() << endl;

	return 0;
}