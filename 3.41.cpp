
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	int i,n,k;
	int res1 = 0, res2 = 1;

	cin >> n;
	cout << 0 << "  " << 1 << "  ";

	for (i = 3; i <= 15; i++) {
	
		if (i % 2 != 0) {
			res1 = res1 + res2;
			cout << res1 << "  ";
		}
		else {
			res2 = res2 + res1;
			cout << res2 << "  ";
		}
		if (i == n) {
			if (res1 > res2)
				k=res1;
			else
				k=res2;
		}		
	}
	cout << endl << n << "-oe chsilo Fibonachi ravno: " << k << endl;

	return 0;
}


 



