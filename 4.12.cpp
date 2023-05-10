
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	const int arraySize = 6;
	char a[arraySize] ;
	int hold,k=0;

	cin >> a;

	for (int i = 0; i < arraySize; i++)
		cout << setw(3) << a[i] << endl;

	return 0;
}


