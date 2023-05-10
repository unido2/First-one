
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

void stringRev(const char[],int);


int main() {

	const int size = 7;
	int key,c;
	char a[size] = "papaya";

	stringRev(a, size);
	
	return 0;
}


void stringRev(const char b[], int size) {

	if (b[0]!='\0') {
		stringRev(&b[1], size - 1);
		cout << b[0];
	}
}




