
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int flip(int);
int fibo(int);

int main()
{
	int b,exp,k=0,orel=0;
	char otvet;

	
	cin >> b;
	cout<<fibo(b)<<endl;

	return 0;
}

int flip(int x, int y) {
	cout <<"y= " << y <<"x= "<< x <<endl;
	if (y == 1)
		return x;
	else
		return x * flip(x, y - 1);
}

int fibo(int b)
{
	if (b == 0 || b == 1)
		return b;
	else
		return fibo(b - 1) + fibo(b - 2);
}
 



