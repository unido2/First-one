// 

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int a,k,i,ii;
	
	cout << "Storona kvadrata: " << endl;
	cin >> a;
	cout << endl;

	for (ii=1; ii <= a; ii++) {
		cout << "*";
		
		if (ii == a || ii==1) {
			for (i=1; i <= a - 1; i++)
				cout << "*";
		}
		else {
			for (k=1; k <= a - 2; k++)
				cout << " ";
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
