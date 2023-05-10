
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int testPali(char[],int);


int main() {

	const int size = 7;
	int p;
	char a[size] = "pottop";

	p = testPali(a, size);
	if (p == 0)
		cout << "NEA!" << endl;
	if(p == 1)
		cout << "DA!" << endl;
	return 0;
}

int testPali(char b[], int size) {

	cout << size << endl;

	if (size > 2) {
		cout << b[0] << " -- " << b[size - 2] << endl;
		if (b[0] != b[size - 2]) {
			return 0;
		}
		return testPali(&b[1], size - 2);
	}
	return 1;
	
}



