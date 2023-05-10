
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int factor(int);

int main()
{
	for (int i = 1; i <= 10; i++)
		cout << setw(5) << i << "!= " << factor(i) << endl;
	


	return 0;
}

int factor(int n) {
	if (n <= 1) {
		cout << 1;
		return 1;
		
	}
	else {
		cout << n << " * ";
		return n * factor(n - 1);
	}
}

 



