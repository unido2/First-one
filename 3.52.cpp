// 

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int sqrt1(int);
float exp1(int);
float log1(float);
template<class v>
v fabs1(v a);
int ceil1(float);
int floor1(float);
int pow1(int, int);
float fmod1(float, float);


int main()
{
	int x=3,y;
	float e = 2.718282;
	
	cout << "result is " << fmod1(13.657,2.333) << endl;
	
	return 0;
}
 
int sqrt1(int a) {

	for (int i = a; i <= 1; i--) {
		if (i * i == a)
			return i;
	}
}

float exp1(int a) {
	float exp = 2.718282;
	if (a == 1)
		return exp;
	else
		return exp * exp1(a - 1);
}

float log1(float a) {			// Problemmss
	float ee= 2.718282;
	int d,k=0;
	
	if (a >= ee) {
		for (k = 0; a >= ee; k++) {
			a /= ee;
		}
		cout << a << endl;
	}
	if(a<ee) {
		a *= 100;
		ee *= 100;
		cout << a << "  " << ee << endl;
		d = (int)a / (int) ee;
	}
	cout << d << endl;
	return k;
}

template <class v>
v fabs1(v a) {
	if (a == 0)
		return 0;
	if (a < 0)
		return -a;
	else
		return a;
}

int ceil1(float a) {
	if (a > 0)
		return (int)a + 1;
	else
		return int(a);

}

int floor1(float a) {
	if (a > 0)
		return (int)a;
	else
		return int(a)-1;
}

int pow1(int a, int b) {
	if (b == 1)
		return a;
	else
		return a * pow1(a, b - 1);
}

float fmod1(float a, float b) {
	float q;
	int i;
	q = a;
	for (i = 0; q >= b; i++) {
		q -= b;
	}
	return a-i*b;
}




