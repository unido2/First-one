// 

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int counter;
	double number, largest;

	cout << "Vvedite 4 chisla:  " << endl;
	cin >> number;
	largest = number;
	for (counter=1;counter<=9;counter++) {
		cin >> number;
		if (number > largest)
			largest = number;
	}
	cout << "Max chislo:  " << largest <<endl;
return 0;
}
