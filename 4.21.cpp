
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

void selectionSort(int[],int);


int main() {

	const int size = 10;
	int a[size] = { 32,27,64,12,95,14,90,70,60,37 };

	selectionSort(a, size);
	for (int i = 0; i < 10; i++)
		cout << a[i] << "  ";
	cout <<endl;
	return 0;
}

void selectionSort(int b[], int size) {
	int hold;
	
	if (size>0) {
		if (b[size - 1] < b[0]) {
			hold=b[0];
			b[0]=b[size-1];
			b[size - 1] = hold;
		}
		selectionSort(b, size - 1);
	}
}



