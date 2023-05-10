
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int flip(void);

int main()
{
	int n,reshka=0,orel=0;

	srand(time(NULL));
	for (int i = 1; i <= 100; i++) {
		n = flip();
		cout << n << " ";
		if (n == 1)
			reshka++;
		else
			orel++;
	}
	cout <<endl<< "RESHKA= " << reshka << endl << "OREL= " << orel << endl;

	

	return 0;
}


int flip(void) {
	int q;
	q = 0 + rand() % 2;
	return q;	
}

 



