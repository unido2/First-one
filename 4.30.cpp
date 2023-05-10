
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

void bucketSearch(int *,int [][10],int);
void printArray(const int*a, int);


int main() {

	const int size = 10;
	int a[size] = { 20,4,5,30,7,12,8,21,15,32 },
		buck[10][size] = {0};

	bucketSearch(a, buck, size);
	printArray(a, size);


	return 0;
}

void bucketSearch(int *a,int buck[][10], int size) {
	int j = 0;
	for (int r = 1; r <= 2; r++) {

		for (int i = 0; i < 10; i++)
			buck[a[i] % (int) pow(10,r) / (int)pow(10,r-1)][i] = a[i];

		for (int row = 0; row < 10; row++)
			for (int col = 0; col < 10; col++)
				if (buck[row][col] != 0) {
					a[j] = buck[row][col];
					j++;
				}
		j = 0;
		for (int row = 0; row < 10; row++)
			for (int col = 0; col < 10; col++)
				buck[row][col] = 0;
	}
}

void printArray(const int* a, int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << endl;
}