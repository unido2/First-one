
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int binarySearch(const int[],int,int,int,int);


int main() {

	const int size = 10;
	int key,c;
	int a[size] = { 10,12,15,18,20,25,29,38,40,60 };

	cin >> key;

	c=binarySearch(a, key,0,size-1,size);
	if (c != -1)
		cout << "YEss! " << c << endl;
	else
		cout << "NO1!!" << endl;
	
	return 0;
}


int binarySearch(const int b[], int key, int low, int high, int size) {
	int middle;

	middle = (low + high) / 2;
	
	if (low <= high) {
		
		if (b[middle] == key)
			return b[middle];
		
			if (key < b[middle]) {
				high = middle - 1;
				cout << "high " << high << endl;
				return binarySearch(b, key, low, high, middle);
			}
			else {

				low = middle + 1;
				cout << "low " << low << endl;
				return binarySearch(b, key, low, high, middle);
			}
	}
	return -1;
}



