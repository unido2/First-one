// 

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
int mystery(int,int);

int main()
{
	int x,y;

	cin >> x >> y;
	cout << "result is " << (y<0 ? (- 1 * mystery(x, y)) : mystery(x, y)) << endl;
	
	return 0;
}
 
int mystery(int a, int b) {
	if (b > 0) {
		if (b == 1)
			return a;
		else
			return a + mystery(a, b - 1);
	}
	if (b < 0) {
		if (b == -1)
			return a;
		else
			return a + mystery(a, b + 1);

	}
	if (b == 0)
		return 0;
}



