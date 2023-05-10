// 

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int y=1;
	double zar=0, ob_prod ;

	for (y; y > 0; y++) {
		cout << "Vvedite ob'yem prodagh d usd:  " << endl;
		cin >> ob_prod;
		if (ob_prod != EOF)
			zar = 250 + ob_prod * 0, 09;
		cout << "zarabotok:  " << zar << endl << endl;
		else
			break;
	}
return 0;
}
