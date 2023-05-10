
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {

	const int size=10;
	int percent, u=668;
	int counter[11] = {0},
		sellers[size] = { 0 };


	for (int selSal = 0; selSal < size; selSal++) {
		percent = 203 + (0 + rand() % 5) * 103;
		sellers[selSal] = percent;
		cout << sellers[selSal] << "  " << endl;
	}
	for (int i = 0; i < size; i++) {
		if (sellers[i] >= 1000)
			++counter[9];
		else
			++counter[sellers[i] / 100 - 1];
	}

	for (int sal = 1; sal <= 9; sal++) {
		if (sal == 9)
			cout << sal << "." << (sal + 1) * 100 << "$ i bolee"
			<< setw(5) << counter[sal] << endl;
		else
			cout << sal << "." << (sal + 1) * 100 << "-" << (sal + 1) * 100 + 99 << "$"
			<< setw(5) << counter[sal] << endl;
	}

	return 0;
}


 



