
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int whatis(int[], int);

int main() {
	const int size = 10;
	int a[size] = {1,2,3,4,5,6,7,8,9,10};
	int result = whatis(a, size);
	int total = 0;
	for (int i = 0; i < size; i++)
		total += a[i];
	cout << "result: " << result<<" i "<<total<<endl;


	return 0;
}

int whatis(int b[], int size)
{
	if (size == 1)
		return b[0];
	else
		return b[size - 1] + whatis(b, size - 1);
}
