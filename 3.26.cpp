// 

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
void perfect(int);

int main()
{
	int h,m,s,n1,n2, k=0,j;
	int number;

	
	cin >> number;
	
	for (int i = 1; i < number; i++) {
		
		perfect(i);
	}
	
}

void perfect(int numb) {
	int sum_k = 0;

		for (int k = 1; k<numb; k++) {
			if(numb%k==0)
			 sum_k = sum_k + k;	
	
		}
		if (sum_k == numb) {
			for (int k = 1; k < numb; k++) {
				if (numb % k == 0)
					cout << k << " ";
			}
			cout << "SOVERSHENNOST "<<sum_k << endl;
		}
	
}

 



