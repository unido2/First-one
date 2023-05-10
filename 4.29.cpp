
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

void searchEratos(int *,int);
void printAr(int*, int);
void arONE(int*, int);


int main() {

	const int size = 1000;
	int a[size] = {0};

	arONE(a, size);
	searchEratos(a, size);
	printAr(a, size);

	return 0;
}

void searchEratos(int *a, int size) {

	for (int i = 2; i < size; i++)
		for (int j = 2; j < i; j++)
			if (a[i]!=0 && i% j == 0)
				a[i] = 0;
}

void printAr(int* a, int size) {
	int k=0;
	for (int i = 2; i < size; i++) {
		if (a[i] == 1) {
			cout << i << ", ";
			if ((++k) % 20 == 0)
				cout << endl;
		}
	}
}

void arONE(int* a, int size) {
	
	for (; *a == 0; a++)
		*a = 1;
}

