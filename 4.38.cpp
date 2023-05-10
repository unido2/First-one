
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int recMIN(const int[],int);


int main() {

	const int size = 7;
	int key,c;
	int a[size] = { 5,2,-1,20,4,3,100 };

	cout << "min: " << recMIN(a, size) << endl;
	
	return 0;
}


int recMIN(const int b[], int size) {
	static int min=200;

	
	if (size>0) {
		if (b[size - 1] < min)
			min = b[size - 1];
		recMIN(b, size - 1);
	}

	return min;
}