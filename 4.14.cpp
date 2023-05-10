
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	const int size = 13;
	int frequency[size] = { 0 };
	int a, b,total=0;

	srand(time(NULL));
		
	for (int i = 1; i <= 36000; i++) {
		a = 1 + rand() % 6;
		b = 1 + rand() % 6;
		++frequency[a + b];
	}
	for (int j = 2; j < 13; j++) {
		cout <<setw(2)<< j << setw(6) << frequency[j] << endl;
		total += frequency[j];
	}
	cout << total << endl;

	return 0;
}
