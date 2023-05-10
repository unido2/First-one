#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include<string.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

void lold(int *, const int*);
void printAr(int[], int);


int main() {
	long v1=200000,v2;
	const int size = 5;
	int values[size] = {2,4,6,8,10};
	long* lptr = &v1;

	v2 = *lptr;
	cout << &v2 << endl;
	cout << lptr<< " "<<&v1;
	
	


	//lold(b, a);
	//printAr(b,10);
	return 0;
}



void lold(int* b, const int* a) {

	for (; (*b = *a) != 60; b++, a++)
		;
	}


void printAr(int b[], int size) {
	for (int i = 0; i < size; i++)
		cout << b[i] << "  ";
	cout << endl;
}


