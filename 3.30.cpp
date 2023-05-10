// 

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
void prost(int);

int main()
{
	int h,m,s,n1,n2, k=0,j;
	int number;
	
	for (int i = 2; i <=10000; i++) {
		prost(i);
	}
}

void prost(int i) {
	int y = 0;
	for (int k = 2; k < i - 1; k++) {
		if (i % k == 0)
			y = 1;
	}
		if (y == 0)
			cout << i <<"  ";
}

 



