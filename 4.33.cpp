
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int linearSear(int[],int,int);


int main() {

	const int size = 10;
	int key,c;
	int a[size] = { 18,21,3,47,5,68,73,8,91,10 };

	cin >> key;

	c=linearSear(a, key,size);
	if (c != -1)
		cout << "YEss! " << c << endl;
	else
		cout << "NO1!!" << endl;

	return 0;
}

int linearSear(int b[], int key, int size) {

	if (size > 0) {
		if (b[size - 1] == key)
			return size - 1;
		return linearSear(b, key, size - 1);
	}
	
	return -1;
}



