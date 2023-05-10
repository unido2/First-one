
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	const int size = 20;
	int c[size] = {0};
	int a, b,k=0;

	for (int i = 0; i < size; i++) {
		cin >> b;
		c[i] = b;
		if (i == 0) {
			cout << c[i] << endl;
			continue;
		}
		else {
			for (int j = 0; j < i; j++)
				if (b == c[j]) {
					k++;
					j = i;
				}
		}
		if(k==0)
		cout << "new " << b << endl;
		k = 0;
	}
	for (int i = 0; i < size; i++)
		cout << c[i] << "  ";

	return 0;
}
