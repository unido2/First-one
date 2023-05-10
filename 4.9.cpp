
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	
	float total = 0;
	float t[3][4] = {};

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
		t[i][j] = i*2 +3+j;

	cout << "    [0]  [1]  [2]  [3]" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "[" << i << "]" << "  ";
		for (int j = 0; j < 4; j++)
			cout << t[i][j] << "    ";
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
		total += t[i][3];

	cout << "Sum t[i][3]: " << total << endl;

	return 0;
}


 



