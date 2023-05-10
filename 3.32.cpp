
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
void nod(int n, int m);
int nod1(int, int);

int main()
{
	int n,m,f, k=0,j;

	srand(time(NULL));
	cin >> n>>m;
	cout << nod1(n, m) << endl;

	return 0;
}


void nod(int n, int m) {
	int min, del_max;
	min=n;
	if (m < n)
		min = m;
	for (int i = min; i >= 1; i--) {
		if (n % i == 0 && m % i == 0) {
			del_max = i;
			break;
		}
	}
	cout << del_max << endl;

	
}

int nod1(int n, int m)
{
	cout << "n= " << n << "m= " << m;
	if (m == 0)
		return n;
	else
		return nod1(m, n % m);
}

 



