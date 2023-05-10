// 

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{
	int n=9, i, i1, i2,i3,i4,k=1;
	
	for (i = 0; i <= n; i++) {
		for (i1 = 1; i1 <= i + 1; i1++)
			cout << "*";
		for (i2 = 9; i2 >= i + 1; i2--) 
			cout << " ";
		cout << "\t";

		for (i2 = 10; i2 >= i + 1; i2--)
			cout << "*";
		for (i1 = 1; i1 < i + 1; i1++)
				cout << " ";
		cout << "\t";
	
		for (i1 = 1; i1 < i + 1; i1++)
			cout << " ";
		for (i2 = 10; i2 >= i+1; i2--) 
			cout << "*";
		cout << "\t";

		for (i2 = 10; i2 > i+1; i2--)
			cout << " ";
		for (i1 = 1; i1 <= i + 1; i1++)
			cout << "*";
		
	
		cout << endl;
	//	if (i < n) {
	//		for (i1 = 1; i1 <= i + 1; i1++)
	//			cout << " ";
	//	}

		
		
	}

					
	return 0;
}
