
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int nod(int,int);

int main()
{
	const int arraySize = 10;
	int a[arraySize] = { 2,6,4,8,10,12,89,45,37 };
	int hold;

	for (int pass = 1; pass < arraySize; pass++)
		for (int i = 0; i, arraySize; i++)
			if (a[i] > a[i + 1]) {
				hold = a[i];
				a[i] = a[i + 1];
				a[i + 1] = hold;
			}
	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];
	cout << endl;
	return 0;
}


