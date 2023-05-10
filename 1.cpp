
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int creps(int[], int);


int main() {
	int res;
	int a[2] = { 0 };

	srand(time(NULL));

	for (int i = 1; i <= 10; i++) {
		res = creps(a,2);
		cout << a[0] << "  " << a[1] <<"  res= "<<res<< endl;
		a[0] = 0;
		a[1] = 0;
	}
		return 0;
}

int creps(int schet[],int size) {
	int a, b;

	a = 5 + rand() % 6;
	b = 0 + rand() % 2;
	for(int j=1;j<=a;j++)
	++schet[b];
	return a;
}

int rolldice(void) {
	int die1, die2, worksum;


	die1 = 1 + rand() % 6;
	die2 = 1 + rand() % 6;
	worksum = die1 + die2;
	cout << "Brosok igroka " << die1 << " + " << die2 << " = "
		<< worksum << endl;
	return worksum;
}

 



