
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
	cin >> n;

	do {
		f = n % 10;
		n /= 10;
		cout << f << "  ";
	} while (n > 9);
	cout << n;

	return 0;
}


int deli(int n) {
	if (n > 9)
		return deli(n / 10) % 10;
	else
		return n;
}

 



