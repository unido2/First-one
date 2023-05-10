
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

template<class T>
void circleArea(T);


int main() {
	float r;
	
	cin >> r;
	circleArea(r);


	return 0;
}

template<class T>
void circleArea(T r) {
	float pi = 3.141592;
		cout << "Ploschad' kruga: " << pi * r * r << endl;
}