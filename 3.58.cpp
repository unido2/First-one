
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

template<class t>
int min1(t r1, int r2);
template<class t>
t max1(t r1, t r2);


int main() {
	int r1,r2;
	float c1, c2;
	char d1, d2;

	cout << (int) 'a' << endl;
	cout << "Min: " << min1(5,1) << endl;
	cout << "Max; "<<max1(3.8567,3.8676) << endl;

	return 0;
}


template<class t>
int min1(tr1,int r2) {
	t min;
	min = r1;
	if (r2 < r1)
		min = r2;
	return min;
}

template<class t>
t max1(t r1, t r2) {
	t max;
	max = r1;
	if (r2 > r1)
		max = r2;
	return max;
}