
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

void printAr(int[],int);


int main() {

	const int size = 10;
	int a[size] = { 1,2,3,4,5,6,7,8,9,10 };

	printAr(a, size);

	return 0;
}

void printAr(int b[], int size) {

	if (size > 0) {
		printAr(b, size - 1);
		cout << b[size - 1]<<"  ";
	}
	
}



