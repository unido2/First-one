
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int deli(int n);

int main()
{
	int n,f, k=0,j;

	srand(time(NULL));
	f = n = 1 + rand() % 32767;
	cout << n << endl;

	do {
		f /= 10;
		k++;
	} while (f > 9);

	for (int i = 0; i < k+1; i++) {
		j = n / (int)pow(10, k - i) % 10;
		cout << j << "  ";
	}

	return 0;
}


int deli(int n) {
	if (n > 9)
		return deli(n / 10) % 10;
	else
		return n;
}

 



