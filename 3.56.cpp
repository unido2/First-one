
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

template<class t>
t min1(t r1, t r2);
template<class t>
t max1(t r1, t r2);


int main() {
	int r1,r2;
	float c1, c2;
	char d1, d2;

	cin >> r1 >> r2;
	cout << min1(r1, r2) << endl;
	cout << max1(r1, r2) << endl;

	return 0;
}


template<class t>
t min1(t r1,t r2) {
	t min;
	r1 = min;
	if (r2 < r1)
		r2 = min;
	return min;
}

template<class t>
t max1(t r1, t r2) {
	t max;
	r1 = max;
	if (r2 > r1)
		r2 = max;
	return max;
}